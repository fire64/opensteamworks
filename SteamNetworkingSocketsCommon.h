 //==========================  Open Steamworks  ================================
//
// This file is part of the Open Steamworks project. All individuals associated
// with this project do not claim ownership of the contents
// 
// The code, comments, and all related files, projects, resources,
// redistributables included with this project are Copyright Valve Corporation.
// Additionally, Valve, the Valve logo, Half-Life, the Half-Life logo, the
// Lambda logo, Steam, the Steam logo, Team Fortress, the Team Fortress logo,
// Opposing Force, Day of Defeat, the Day of Defeat logo, Counter-Strike, the
// Counter-Strike logo, Source, the Source logo, and Counter-Strike Condition
// Zero are trademarks and or registered trademarks of Valve Corporation.
// All other trademarks are property of their respective owners.
//
//=============================================================================

#ifndef STEAMNETWORKINGSOCKETS_H
#define STEAMNETWORKINGSOCKETS_H
#ifdef _WIN32
#pragma once
#endif

#include "SteamNetworkingUtilsCommon.h"

typedef uint32 HSteamListenSocket;
typedef uint32 HSteamNetConnection;

class ISteamNetworkingConnectionCustomSignaling;
class ISteamNetworkingCustomSignalingRecvContext;

/// Max length, in bytes (including null terminator) of the reason string
/// when a connection is closed.
const int k_cchSteamNetworkingMaxConnectionCloseReason = 128;

/// Max length, in bytes (include null terminator) of debug description
/// of a connection.
const int k_cchSteamNetworkingMaxConnectionDescription = 128;

/// Max size of user data blob
const size_t k_cbMaxSteamDatagramGameCoordinatorServerLoginAppData = 2048;

/// Max size of serialized data blob
const size_t k_cbMaxSteamDatagramGameCoordinatorServerLoginSerialized = 4096;


/// Max length of diagnostic error message
const int k_cchMaxSteamNetworkingErrMsg = 1024;

/// Used to return English-language diagnostic error messages to caller.
/// (For debugging or spewing to a console, etc.  Not intended for UI.)
typedef char SteamNetworkingErrMsg[ k_cchMaxSteamNetworkingErrMsg ];

typedef SteamNetworkingErrMsg SteamDatagramErrMsg;


//
// Connection status
//


/// High level connection status
enum ESteamNetworkingConnectionState
{

	/// Dummy value used to indicate an error condition in the API.
	/// Specified connection doesn't exist or has already been closed.
	k_ESteamNetworkingConnectionState_None = 0,

	/// We are trying to establish whether peers can talk to each other,
	/// whether they WANT to talk to each other, perform basic auth,
	/// and exchange crypt keys.
	///
	/// - For connections on the "client" side (initiated locally):
	///   We're in the process of trying to establish a connection.
	///   Depending on the connection type, we might not know who they are.
	///   Note that it is not possible to tell if we are waiting on the
	///   network to complete handshake packets, or for the application layer
	///   to accept the connection.
	///
	/// - For connections on the "server" side (accepted through listen socket):
	///   We have completed some basic handshake and the client has presented
	///   some proof of identity.  The connection is ready to be accepted
	///   using AcceptConnection().
	///
	/// In either case, any unreliable packets sent now are almost certain
	/// to be dropped.  Attempts to receive packets are guaranteed to fail.
	/// You may send messages if the send mode allows for them to be queued.
	/// but if you close the connection before the connection is actually
	/// established, any queued messages will be discarded immediately.
	/// (We will not attempt to flush the queue and confirm delivery to the
	/// remote host, which ordinarily happens when a connection is closed.)
	k_ESteamNetworkingConnectionState_Connecting = 1,

	/// Some connection types use a back channel or trusted 3rd party
	/// for earliest communication.  If the server accepts the connection,
	/// then these connections switch into the rendezvous state.  During this
	/// state, we still have not yet established an end-to-end route (through
	/// the relay network), and so if you send any messages unreliable, they
	/// are going to be discarded.
	k_ESteamNetworkingConnectionState_FindingRoute = 2,

	/// We've received communications from our peer (and we know
	/// who they are) and are all good.  If you close the connection now,
	/// we will make our best effort to flush out any reliable sent data that
	/// has not been acknowledged by the peer.  (But note that this happens
	/// from within the application process, so unlike a TCP connection, you are
	/// not totally handing it off to the operating system to deal with it.)
	k_ESteamNetworkingConnectionState_Connected = 3,

	/// Connection has been closed by our peer, but not closed locally.
	/// The connection still exists from an API perspective.  You must close the
	/// handle to free up resources.  If there are any messages in the inbound queue,
	/// you may retrieve them.  Otherwise, nothing may be done with the connection
	/// except to close it.
	///
	/// This stats is similar to CLOSE_WAIT in the TCP state machine.
	k_ESteamNetworkingConnectionState_ClosedByPeer = 4,

	/// A disruption in the connection has been detected locally.  (E.g. timeout,
	/// local internet connection disrupted, etc.)
	///
	/// The connection still exists from an API perspective.  You must close the
	/// handle to free up resources.
	///
	/// Attempts to send further messages will fail.  Any remaining received messages
	/// in the queue are available.
	k_ESteamNetworkingConnectionState_ProblemDetectedLocally = 5,

//
// The following values are used internally and will not be returned by any API.
// We document them here to provide a little insight into the state machine that is used
// under the hood.
//

	/// We've disconnected on our side, and from an API perspective the connection is closed.
	/// No more data may be sent or received.  All reliable data has been flushed, or else
	/// we've given up and discarded it.  We do not yet know for sure that the peer knows
	/// the connection has been closed, however, so we're just hanging around so that if we do
	/// get a packet from them, we can send them the appropriate packets so that they can
	/// know why the connection was closed (and not have to rely on a timeout, which makes
	/// it appear as if something is wrong).
	k_ESteamNetworkingConnectionState_FinWait = -1,

	/// We've disconnected on our side, and from an API perspective the connection is closed.
	/// No more data may be sent or received.  From a network perspective, however, on the wire,
	/// we have not yet given any indication to the peer that the connection is closed.
	/// We are in the process of flushing out the last bit of reliable data.  Once that is done,
	/// we will inform the peer that the connection has been closed, and transition to the
	/// FinWait state.
	///
	/// Note that no indication is given to the remote host that we have closed the connection,
	/// until the data has been flushed.  If the remote host attempts to send us data, we will
	/// do whatever is necessary to keep the connection alive until it can be closed properly.
	/// But in fact the data will be discarded, since there is no way for the application to
	/// read it back.  Typically this is not a problem, as application protocols that utilize
	/// the lingering functionality are designed for the remote host to wait for the response
	/// before sending any more data.
	k_ESteamNetworkingConnectionState_Linger = -2, 

	/// Connection is completely inactive and ready to be destroyed
	k_ESteamNetworkingConnectionState_Dead = -3,

	k_ESteamNetworkingConnectionState__Force32Bit = 0x7fffffff
};

/// Enumerate various causes of connection termination.  These are designed to work similar
/// to HTTP error codes: the numeric range gives you a rough classification as to the source
/// of the problem.
enum ESteamNetConnectionEnd
{
	// Invalid/sentinel value
	k_ESteamNetConnectionEnd_Invalid = 0,

	//
	// Application codes.  These are the values you will pass to
	// ISteamNetworkingSockets::CloseConnection.  You can use these codes if
	// you want to plumb through application-specific reason codes.  If you don't
	// need this facility, feel free to always pass
	// k_ESteamNetConnectionEnd_App_Generic.
	//
	// The distinction between "normal" and "exceptional" termination is
	// one you may use if you find useful, but it's not necessary for you
	// to do so.  The only place where we distinguish between normal and
	// exceptional is in connection analytics.  If a significant
	// proportion of connections terminates in an exceptional manner,
	// this can trigger an alert.
	//

	// 1xxx: Application ended the connection in a "usual" manner.
	//       E.g.: user intentionally disconnected from the server,
	//             gameplay ended normally, etc
	k_ESteamNetConnectionEnd_App_Min = 1000,
		k_ESteamNetConnectionEnd_App_Generic = k_ESteamNetConnectionEnd_App_Min,
		// Use codes in this range for "normal" disconnection
	k_ESteamNetConnectionEnd_App_Max = 1999,

	// 2xxx: Application ended the connection in some sort of exceptional
	//       or unusual manner that might indicate a bug or configuration
	//       issue.
	// 
	k_ESteamNetConnectionEnd_AppException_Min = 2000,
		k_ESteamNetConnectionEnd_AppException_Generic = k_ESteamNetConnectionEnd_AppException_Min,
		// Use codes in this range for "unusual" disconnection
	k_ESteamNetConnectionEnd_AppException_Max = 2999,

	//
	// System codes.  These will be returned by the system when
	// the connection state is k_ESteamNetworkingConnectionState_ClosedByPeer
	// or k_ESteamNetworkingConnectionState_ProblemDetectedLocally.  It is
	// illegal to pass a code in this range to ISteamNetworkingSockets::CloseConnection
	//

	// 3xxx: Connection failed or ended because of problem with the
	//       local host or their connection to the Internet.
	k_ESteamNetConnectionEnd_Local_Min = 3000,

		// You cannot do what you want to do because you're running in offline mode.
		k_ESteamNetConnectionEnd_Local_OfflineMode = 3001,

		// We're having trouble contacting many (perhaps all) relays.
		// Since it's unlikely that they all went offline at once, the best
		// explanation is that we have a problem on our end.  Note that we don't
		// bother distinguishing between "many" and "all", because in practice,
		// it takes time to detect a connection problem, and by the time
		// the connection has timed out, we might not have been able to
		// actively probe all of the relay clusters, even if we were able to
		// contact them at one time.  So this code just means that:
		//
		// * We don't have any recent successful communication with any relay.
		// * We have evidence of recent failures to communicate with multiple relays.
		k_ESteamNetConnectionEnd_Local_ManyRelayConnectivity = 3002,

		// A hosted server is having trouble talking to the relay
		// that the client was using, so the problem is most likely
		// on our end
		k_ESteamNetConnectionEnd_Local_HostedServerPrimaryRelay = 3003,

		// We're not able to get the network config.  This is
		// *almost* always a local issue, since the network config
		// comes from the CDN, which is pretty darn reliable.
		k_ESteamNetConnectionEnd_Local_NetworkConfig = 3004,

		// Steam rejected our request because we don't have rights
		// to do this.
		k_ESteamNetConnectionEnd_Local_Rights = 3005,

	k_ESteamNetConnectionEnd_Local_Max = 3999,

	// 4xxx: Connection failed or ended, and it appears that the
	//       cause does NOT have to do with the local host or their
	//       connection to the Internet.  It could be caused by the
	//       remote host, or it could be somewhere in between.
	k_ESteamNetConnectionEnd_Remote_Min = 4000,

		// The connection was lost, and as far as we can tell our connection
		// to relevant services (relays) has not been disrupted.  This doesn't
		// mean that the problem is "their fault", it just means that it doesn't
		// appear that we are having network issues on our end.
		k_ESteamNetConnectionEnd_Remote_Timeout = 4001,

		// Something was invalid with the cert or crypt handshake
		// info you gave me, I don't understand or like your key types,
		// etc.
		k_ESteamNetConnectionEnd_Remote_BadCrypt = 4002,

		// You presented me with a cert that was I was able to parse
		// and *technically* we could use encrypted communication.
		// But there was a problem that prevents me from checking your identity
		// or ensuring that somebody int he middle can't observe our communication.
		// E.g.: - the CA key was missing (and I don't accept unsigned certs)
		// - The CA key isn't one that I trust,
		// - The cert doesn't was appropriately restricted by app, user, time, data center, etc.
		// - The cert wasn't issued to you.
		// - etc
		k_ESteamNetConnectionEnd_Remote_BadCert = 4003,

		// We couldn't rendezvous with the remote host because
		// they aren't logged into Steam
		k_ESteamNetConnectionEnd_Remote_NotLoggedIn = 4004,

		// We couldn't rendezvous with the remote host because
		// they aren't running the right application.
		k_ESteamNetConnectionEnd_Remote_NotRunningApp = 4005,

		// Something wrong with the protocol version you are using.
		// (Probably the code you are running is too old.)
		k_ESteamNetConnectionEnd_Remote_BadProtocolVersion = 4006,

	k_ESteamNetConnectionEnd_Remote_Max = 4999,

	// 5xxx: Connection failed for some other reason.
	k_ESteamNetConnectionEnd_Misc_Min = 5000,

		// A failure that isn't necessarily the result of a software bug,
		// but that should happen rarely enough that it isn't worth specifically
		// writing UI or making a localized message for.
		// The debug string should contain further details.
		k_ESteamNetConnectionEnd_Misc_Generic = 5001,

		// Generic failure that is most likely a software bug.
		k_ESteamNetConnectionEnd_Misc_InternalError = 5002,

		// The connection to the remote host timed out, but we
		// don't know if the problem is on our end, in the middle,
		// or on their end.
		k_ESteamNetConnectionEnd_Misc_Timeout = 5003,

		// We're having trouble talking to the relevant relay.
		// We don't have enough information to say whether the
		// problem is on our end or not.
		k_ESteamNetConnectionEnd_Misc_RelayConnectivity = 5004,

		// There's some trouble talking to Steam.
		k_ESteamNetConnectionEnd_Misc_SteamConnectivity = 5005,

		// A server in a dedicated hosting situation has no relay sessions
		// active with which to talk back to a client.  (It's the client's
		// job to open and maintain those sessions.)
		k_ESteamNetConnectionEnd_Misc_NoRelaySessionsToClient = 5006,

	k_ESteamNetConnectionEnd_Misc_Max = 5999,

	k_ESteamNetConnectionEnd__Force32Bit = 0x7fffffff
};

/// Convert 3- or 4-character ID to 32-bit int.
inline SteamNetworkingPOPID CalculateSteamNetworkingPOPIDFromString( const char *pszCode )
{
	// OK we made a bad decision when we decided how to pack 3-character codes into a uint32.  We'd like to support
	// 4-character codes, but we don't want to break compatibility.  The migration path has some subtleties that make
	// this nontrivial, and there are already some IDs stored in SQL.  Ug, so the 4 character code "abcd" will
	// be encoded with the digits like "0xddaabbcc".
	//
	// Also: we don't currently use 1- or 2-character codes, but if ever do in the future, let's make sure don't read
	// past the end of the string and access uninitialized memory.  (And if the string is empty, we always want
	// to return 0 and not read bytes past the '\0'.)
	//
	// There is also extra paranoia to make sure the bytes are not treated as signed.
	SteamNetworkingPOPID result = (uint32)(uint8)pszCode[0] << 16U;
	if ( pszCode[1] )
	{
		result |= ( (uint32)(uint8)pszCode[1] << 8U );
		if ( pszCode[2] )
		{
			result |= (uint32)(uint8)pszCode[2] | ( (uint32)(uint8)pszCode[3] << 24U );
		}
	}
	return result;
}

/// Unpack integer to string representation, including terminating '\0'
template <int N>
inline void GetSteamNetworkingLocationPOPStringFromID( SteamNetworkingPOPID id, char (&szCode)[N] )
{
	szCode[0] = char( id >> 16U );
	szCode[1] = char( id >> 8U );
	szCode[2] = char( id );
	szCode[3] = char( id >> 24U ); // See comment above about deep regret and sadness
	szCode[4] = 0;
}

#pragma pack( push, 1 )

/// In a few places we need to set configuration options on listen sockets and connections, and
/// have them take effect *before* the listen socket or connection really starts doing anything.
/// Creating the object and then setting the options "immediately" after creation doesn't work
/// completely, because network packets could be received between the time the object is created and
/// when the options are applied.  To set options at creation time in a reliable way, they must be
/// passed to the creation function.  This structure is used to pass those options.
///
/// For the meaning of these fields, see ISteamNetworkingUtils::SetConfigValue.  Basically
/// when the object is created, we just iterate over the list of options and call
/// ISteamNetworkingUtils::SetConfigValueStruct, where the scope arguments are supplied by the
/// object being created.
struct SteamNetworkingConfigValue_t
{
	/// Which option is being set
	ESteamNetworkingConfigValue m_eValue;

	/// Which field below did you fill in?
	ESteamNetworkingConfigDataType m_eDataType;

	/// Option value
	union
	{
		int32 m_int32;
		int64 m_int64;
		float m_float;
		const char *m_string; // Points to your '\0'-terminated buffer
		void *m_functionPtr;
	} m_val;
};

/// A struct used to describe our readiness to participate in authenticated,
/// encrypted communication.  In order to do this we need:
///
/// - The list of trusted CA certificates that might be relevant for this
///   app.
/// - A valid certificate issued by a CA.
struct SteamNetAuthenticationStatus_t
{ 
	enum { k_iCallback = k_iSteamNetworkingSocketsCallbacks + 2 };

	/// Status
	ESteamNetworkingAvailability m_eAvail;

	/// Non-localized English language status.  For diagnostic/debugging
	/// purposes only.
	char m_debugMsg[ 256 ];
};

/// Network-routable identifier for a service.  This is an intentionally
/// opaque byte blob.  The relays know how to use this to forward it on
/// to the intended destination, but otherwise clients really should not
/// need to know what's inside.  (Indeed, we don't really want them to
/// know, as it could reveal information useful to an attacker.)
struct SteamDatagramHostedAddress
{

	// Size of data blob.
	int m_cbSize;

	// Opaque data
	char m_data[ 128 ];

	// Reset to empty state
	void Clear() { memset( this, 0, sizeof(*this) ); }

	// Parse the data center out of the blob.
	SteamNetworkingPOPID GetPopID() const { return CalculateSteamNetworkingPOPIDFromString( m_data ); }

	/// Set a dummy routing blob with a hardcoded IP:port.  You should only use
	/// this in a dev environment, since the address is in plaintext!
	/// In production this information should come from the server,
	/// using ISteamNetworkingSockets::GetHostedDedicatedServerAddress
	void SetDevAddress( uint32 nIP, uint16 nPort, SteamNetworkingPOPID popid = 0 )
	{
		GetSteamNetworkingLocationPOPStringFromID( popid, m_data );
		m_cbSize = 4;
		m_data[m_cbSize++] = 1;
		m_data[m_cbSize++] = 1;
		m_data[m_cbSize++] = char(nPort);
		m_data[m_cbSize++] = char(nPort>>8);
		m_data[m_cbSize++] = char(nIP);
		m_data[m_cbSize++] = char(nIP>>8);
		m_data[m_cbSize++] = char(nIP>>16);
		m_data[m_cbSize++] = char(nIP>>24);
	}

	/// Convert to/from std::string (or anything that acts like it).
	/// Useful for interfacing with google protobuf.  It's a template
	/// mainly so that we don't have to include <string> in the header.
	/// Note: by "string", we don't mean that it's text.  It's a binary
	/// blob, and it might have zeros in it.  (std::string can handle that.)
	template <typename T> bool SetFromStdString( const T &str )
	{
		if ( str.length() >= sizeof(m_data) )
		{
			m_cbSize = 0;
			return false;
		}
		m_cbSize = (int)str.length();
		memcpy( m_data, str.c_str(), m_cbSize );
		return true;
	}
	template <typename T> void GetAsStdString( T *str ) const
	{
		str->assign( m_data, m_cbSize );
	}
};

/// Structure that describes a gameserver attempting to authenticate
/// with your central server allocator / matchmaking service ("game coordinator").
/// This is useful because the game coordinator needs to know:
///
/// - What data center is the gameserver running in?
/// - The routing blob of the gameserver
/// - Is the gameserver actually trusted?
///
/// Using this structure, you can securely communicate this information
/// to your server, and you can do this WITHOUT maintaining any
/// whitelists or tables of IP addresses.
///
/// See ISteamNetworkingSockets::GetGameCoordinatorServerLogin
struct SteamDatagramGameCoordinatorServerLogin
{
	/// Server's identity
	SteamNetworkingIdentity m_identity;

	/// Routing info.  Note that this includes the POPID
	SteamDatagramHostedAddress m_routing;

	/// AppID that the server thinks it is running
	AppId_t m_nAppID;

	/// Unix timestamp when this was generated
	RTime32 m_rtime;

	/// Size of application data
	int m_cbAppData;

	/// Application data.  This is any additional information
	/// that you need to identify the server not contained above.
	/// (E.g. perhaps a public IP as seen by the coordinator service.)
	char m_appData[ k_cbMaxSteamDatagramGameCoordinatorServerLoginAppData ];
};

/// Ticket used to gain access to the relay network.
struct SteamDatagramRelayAuthTicket
{
	SteamDatagramRelayAuthTicket() { Clear(); }

	/// Reset all fields
	void Clear() { memset( this, 0, sizeof(*this) ); m_nRestrictToVirtualPort = -1; }

	/// Identity of the gameserver we want to talk to.  This is required.
	SteamNetworkingIdentity m_identityGameserver;

	/// Identity of the person who was authorized.  This is required.
	SteamNetworkingIdentity m_identityAuthorizedClient;

	/// SteamID is authorized to send from a particular public IP.  If this
	/// is 0, then the sender is not restricted to a particular IP.
	///
	/// Recommend to leave this set to zero.
	uint32 m_unPublicIP;

	/// Time when the ticket expires.  Recommended: take the current
	/// time and add 6 hours, or maybe a bit longer if your gameplay
	/// sessions are longer.
	///
	/// NOTE: relays may reject tickets with expiry times excessively
	/// far in the future, so contact us if you wish to use an expiry
	/// longer than, say, 24 hours.
	RTime32 m_rtimeTicketExpiry;

	/// Routing information where the gameserver is listening for
	/// relayed traffic.  You should fill this in when generating
	/// a ticket.
	///
	/// When generating tickets on your backend:
	/// - In production: The gameserver knows the proper routing
	///   information, so you need to call
	///   ISteamNetworkingSockets::GetHostedDedicatedServerAddress
	///   and send the info to your backend.
	/// - In development, you will need to provide public IP
	///   of the server using SteamDatagramServiceNetID::SetDevAddress.
	///   Relays need to be able to send UDP
	///   packets to this server.  Since it's very likely that
	///   your server is behind a firewall/NAT, make sure that
	///   the address is the one that the outside world can use.
	///   The traffic from the relays will be "unsolicited", so
	///   stateful firewalls won't work -- you will probably have
	///   to set up an explicit port forward.
	/// On the client:
	/// - this field will always be blank.
	SteamDatagramHostedAddress m_routing;

	/// App ID this is for.  This is required, and should be the
	/// App ID the client is running.  (Even if your gameserver
	/// uses a different App ID.)
	uint32 m_nAppID;

	/// Restrict this ticket to be used for a particular virtual port?
	/// Set to -1 to allow any virtual port.
	///
	/// This is useful as a security measure, and also so the client will
	/// use the right ticket (which might have extra fields that are useful
	/// for proper analytics), if the client happens to have more than one
	/// appropriate ticket.
	///
	/// Note: if a client has more that one acceptable ticket, they will
	/// always use the one expiring the latest.
	int m_nRestrictToVirtualPort;

	//
	// Extra fields.
	//
	// These are collected for backend analytics.  For example, you might
	// send a MatchID so that all of the records for a particular match can
	// be located.  Or send a game mode field so that you can compare
	// the network characteristics of different game modes.
	//
	// (At the time of this writing we don't have a way to expose the data
	// we collect to partners, but we hope to in the future so that you can
	// get visibility into network conditions.)
	//

	struct ExtraField
	{
		enum EType
		{
			k_EType_String,
			k_EType_Int, // For most small integral values.  Uses google protobuf sint64, so it's small on the wire.  WARNING: In some places this value may be transmitted in JSON, in which case precision may be lost in backend analytics.  Don't use this for an "identifier", use it for a scalar quantity.
			k_EType_Fixed64, // 64 arbitrary bits.  This value is treated as an "identifier".  In places where JSON format is used, it will be serialized as a string.  No aggregation / analytics can be performed on this value.
		};
		int /* EType */ m_eType;
		char m_szName[28];

		union {
			char m_szStringValue[128];
			int64 m_nIntValue;
			uint64 m_nFixed64Value;
		};
	};
	enum { k_nMaxExtraFields = 16 };
	int m_nExtraFields;
	ExtraField m_vecExtraFields[ k_nMaxExtraFields ];

	/// Helper to add an extra field in a single call
	void AddExtraField_Int( const char *pszName, int64 val )
	{
		ExtraField *p = AddExtraField( pszName, ExtraField::k_EType_Int );
		if ( p )
			p->m_nIntValue = val;
	}
	void AddExtraField_Fixed64( const char *pszName, uint64 val )
	{
		ExtraField *p = AddExtraField( pszName, ExtraField::k_EType_Fixed64 );
		if ( p )
			p->m_nFixed64Value = val;
	}
	void AddExtraField_String( const char *pszName, const char *val )
	{
		ExtraField *p = AddExtraField( pszName, ExtraField::k_EType_String );
		if ( p )
		{
			size_t l = strlen( val );
			if ( l > sizeof(p->m_szStringValue)-1 )
				l = sizeof(p->m_szStringValue)-1;
			memcpy( p->m_szStringValue, val, l );
			p->m_szStringValue[l] = '\0';
		}
	}

private:
	ExtraField *AddExtraField( const char *pszName, ExtraField::EType eType )
	{
		if ( m_nExtraFields >= k_nMaxExtraFields )
		{
			return NULL;
		}
		ExtraField *p = &m_vecExtraFields[ m_nExtraFields++ ];
		p->m_eType = eType;

		size_t l = strlen( pszName );
		if ( l > sizeof(p->m_szName)-1 )
			l = sizeof(p->m_szName)-1;
		memcpy( p->m_szName, pszName, l );
		p->m_szName[l] = '\0';
		return p;
	}
};


/// Describe the state of a connection.
struct SteamNetConnectionInfo_t
{

	/// Who is on the other end?  Depending on the connection type and phase of the connection, we might not know
	SteamNetworkingIdentity m_identityRemote;

	/// Arbitrary user data set by the local application code
	int64 m_nUserData;

	/// Handle to listen socket this was connected on, or k_HSteamListenSocket_Invalid if we initiated the connection
	HSteamListenSocket m_hListenSocket;

	/// Remote address.  Might be all 0's if we don't know it, or if this is N/A.
	/// (E.g. Basically everything except direct UDP connection.)
	SteamNetworkingIPAddr m_addrRemote;
	uint16 m__pad1;

	/// What data center is the remote host in?  (0 if we don't know.)
	SteamNetworkingPOPID m_idPOPRemote;

	/// What relay are we using to communicate with the remote host?
	/// (0 if not applicable.)
	SteamNetworkingPOPID m_idPOPRelay;

	/// High level state of the connection
	ESteamNetworkingConnectionState m_eState;

	/// Basic cause of the connection termination or problem.
	/// See ESteamNetConnectionEnd for the values used
	int m_eEndReason;

	/// Human-readable, but non-localized explanation for connection
	/// termination or problem.  This is intended for debugging /
	/// diagnostic purposes only, not to display to users.  It might
	/// have some details specific to the issue.
	char m_szEndDebug[ k_cchSteamNetworkingMaxConnectionCloseReason ];

	/// Debug description.  This includes the connection handle,
	/// connection type (and peer information), and the app name.
	/// This string is used in various internal logging messages
	char m_szConnectionDescription[ k_cchSteamNetworkingMaxConnectionDescription ];

	/// Internal stuff, room to change API easily
	uint32 reserved[64];
};

/// A message that has been received
struct SteamNetworkingMessage_t
{

	/// Message payload
	void *m_pData;

	/// Size of the payload.
	uint32 m_cbSize;

	/// The connection this came from.  (Not used when using the ISteamMessages interface)
	HSteamNetConnection m_conn;

	/// Who sent this to us?
	SteamNetworkingIdentity m_sender;

	/// The user data associated with the connection.
	///
	/// This is *usually* the same as calling GetConnection() and then
	/// fetching the user data associated with that connection, but for
	/// the following subtle differences:
	///
	/// - This user data will match the connection's user data at the time
	///   is captured at the time the message is returned by the API.
	///   If you subsequently change the userdata on the connection,
	///   this won't be updated.
	/// - This is an inline call, so it's *much* faster.
	/// - You might have closed the connection, so fetching the user data
	///   would not be possible.
	int64 m_nConnUserData;

	/// Local timestamps when it was received
	SteamNetworkingMicroseconds m_usecTimeReceived;

	/// Message number assigned by the sender
	int64 m_nMessageNumber;

	/// Function used to free up m_pData.  This mechanism exists so that
	/// apps can create messages with buffers allocated from their own
	/// heap, and pass them into the library.  This function will
	/// usually be something like:
	///
	/// free( pMsg->m_pData );
	void (*m_pfnFreeData)( SteamNetworkingMessage_t *pMsg );

	/// Function to used to decrement reference count and, if it's zero, release
	/// the message.  You should not normally need to access this directly.
	/// (Use Release(), and don't set this.)
	void (*m_pfnRelease)( SteamNetworkingMessage_t *pMsg );

	/// The channel number the message was received on.
	/// (Not used for messages received on "connections")
	int m_nChannel;

	/// Pad to multiple of 8 bytes
	int m___nPadDummy;

	#ifdef __cplusplus

		/// You MUST call this when you're done with the object,
		/// to free up memory, etc.
		inline void Release();

		// For code compatibility, some accessors
		inline uint32 GetSize() const { return m_cbSize; }
		inline const void *GetData() const { return m_pData; }
		inline int GetChannel() const { return m_nChannel; }
		inline HSteamNetConnection GetConnection() const { return m_conn; }
		inline int64 GetConnectionUserData() const { return m_nConnUserData; }
		inline SteamNetworkingMicroseconds GetTimeReceived() const { return m_usecTimeReceived; }
		inline int64 GetMessageNumber() const { return m_nMessageNumber; }
	#endif
};

/// Quick connection state, pared down to something you could call
/// more frequently without it being too big of a perf hit.
struct SteamNetworkingQuickConnectionStatus
{

	/// High level state of the connection
	ESteamNetworkingConnectionState m_eState;

	/// Current ping (ms)
	int m_nPing;

	/// Connection quality measured locally, 0...1.  (Percentage of packets delivered
	/// end-to-end in order).
	float m_flConnectionQualityLocal;

	/// Packet delivery success rate as observed from remote host
	float m_flConnectionQualityRemote;

	/// Current data rates from recent history.
	float m_flOutPacketsPerSec;
	float m_flOutBytesPerSec;
	float m_flInPacketsPerSec;
	float m_flInBytesPerSec;

	/// Estimate rate that we believe that we can send data to our peer.
	/// Note that this could be significantly higher than m_flOutBytesPerSec,
	/// meaning the capacity of the channel is higher than you are sending data.
	/// (That's OK!)
	int m_nSendRateBytesPerSecond;

	/// Number of bytes pending to be sent.  This is data that you have recently
	/// requested to be sent but has not yet actually been put on the wire.  The
	/// reliable number ALSO includes data that was previously placed on the wire,
	/// but has now been scheduled for re-transmission.  Thus, it's possible to
	/// observe m_cbPendingReliable increasing between two checks, even if no
	/// calls were made to send reliable data between the checks.  Data that is
	/// awaiting the nagle delay will appear in these numbers.
	int m_cbPendingUnreliable;
	int m_cbPendingReliable;

	/// Number of bytes of reliable data that has been placed the wire, but
	/// for which we have not yet received an acknowledgment, and thus we may
	/// have to re-transmit.
	int m_cbSentUnackedReliable;

	/// If you asked us to send a message right now, how long would that message
	/// sit in the queue before we actually started putting packets on the wire?
	/// (And assuming Nagle does not cause any packets to be delayed.)
	///
	/// In general, data that is sent by the application is limited by the
	/// bandwidth of the channel.  If you send data faster than this, it must
	/// be queued and put on the wire at a metered rate.  Even sending a small amount
	/// of data (e.g. a few MTU, say ~3k) will require some of the data to be delayed
	/// a bit.
	///
	/// In general, the estimated delay will be approximately equal to
	///
	///		( m_cbPendingUnreliable+m_cbPendingReliable ) / m_nSendRateBytesPerSecond
	///
	/// plus or minus one MTU.  It depends on how much time has elapsed since the last
	/// packet was put on the wire.  For example, the queue might have *just* been emptied,
	/// and the last packet placed on the wire, and we are exactly up against the send
	/// rate limit.  In that case we might need to wait for one packet's worth of time to
	/// elapse before we can send again.  On the other extreme, the queue might have data
	/// in it waiting for Nagle.  (This will always be less than one packet, because as soon
	/// as we have a complete packet we would send it.)  In that case, we might be ready
	/// to send data now, and this value will be 0.
	SteamNetworkingMicroseconds m_usecQueueTime;

	/// Internal stuff, room to change API easily
	uint32 reserved[16];
};

#pragma pack( pop )


#define STEAMNETWORKINGSOCKETS_INTERFACE_VERSION_001 "SteamNetworkingSockets001"
#define STEAMNETWORKINGSOCKETS_INTERFACE_VERSION_002 "SteamNetworkingSockets002"
#define STEAMNETWORKINGSOCKETS_INTERFACE_VERSION_003 "SteamNetworkingSockets003"
#define STEAMNETWORKINGSOCKETS_INTERFACE_VERSION_004 "SteamNetworkingSockets004"
#define STEAMNETWORKINGSOCKETS_INTERFACE_VERSION_005 "SteamNetworkingSockets005"
#define STEAMNETWORKINGSOCKETS_INTERFACE_VERSION_006 "SteamNetworkingSockets006"

#endif // STEAMNETWORKINGSOCKETS_H
