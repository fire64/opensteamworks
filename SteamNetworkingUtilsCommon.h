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

#ifndef STEAMNETWORKINGUTILSCOMMON_H
#define STEAMNETWORKINGUTILSCOMMON_H
#ifdef _WIN32
#pragma once
#endif

typedef uint32 SteamNetworkingPOPID;
typedef int64 SteamNetworkingMicroseconds;


//
// Configuration values
//

/// Configuration values can be applied to different types of objects.
enum ESteamNetworkingConfigScope
{

	/// Get/set global option, or defaults.  Even options that apply to more specific scopes
	/// have global scope, and you may be able to just change the global defaults.  If you
	/// need different settings per connection (for example), then you will need to set those
	/// options at the more specific scope.
	k_ESteamNetworkingConfig_Global = 1,

	/// Some options are specific to a particular interface.  Note that all connection
	/// and listen socket settings can also be set at the interface level, and they will
	/// apply to objects created through those interfaces.
	k_ESteamNetworkingConfig_SocketsInterface = 2,

	/// Options for a listen socket.  Listen socket options can be set at the interface layer,
	/// if  you have multiple listen sockets and they all use the same options.
	/// You can also set connection options on a listen socket, and they set the defaults
	/// for all connections accepted through this listen socket.  (They will be used if you don't
	/// set a connection option.)
	k_ESteamNetworkingConfig_ListenSocket = 3,

	/// Options for a specific connection.
	k_ESteamNetworkingConfig_Connection = 4,

	k_ESteamNetworkingConfigScope__Force32Bit = 0x7fffffff
};

// Different configuration values have different data types
enum ESteamNetworkingConfigDataType
{
	k_ESteamNetworkingConfig_Int32 = 1,
	k_ESteamNetworkingConfig_Int64 = 2,
	k_ESteamNetworkingConfig_Float = 3,
	k_ESteamNetworkingConfig_String = 4,
	k_ESteamNetworkingConfig_FunctionPtr = 5, // NOTE: When setting	callbacks, you should put the pointer into a variable and pass a pointer to that variable.

	k_ESteamNetworkingConfigDataType__Force32Bit = 0x7fffffff
};

/// Configuration options
enum ESteamNetworkingConfigValue
{
	k_ESteamNetworkingConfig_Invalid = 0,

	/// [global float, 0--100] Randomly discard N pct of packets instead of sending/recv
	/// This is a global option only, since it is applied at a low level
	/// where we don't have much context
	k_ESteamNetworkingConfig_FakePacketLoss_Send = 2,
	k_ESteamNetworkingConfig_FakePacketLoss_Recv = 3,

	/// [global int32].  Delay all outbound/inbound packets by N ms
	k_ESteamNetworkingConfig_FakePacketLag_Send = 4,
	k_ESteamNetworkingConfig_FakePacketLag_Recv = 5,

	/// [global float] 0-100 Percentage of packets we will add additional delay
	/// to (causing them to be reordered)
	k_ESteamNetworkingConfig_FakePacketReorder_Send = 6,
	k_ESteamNetworkingConfig_FakePacketReorder_Recv = 7,

	/// [global int32] Extra delay, in ms, to apply to reordered packets.
	k_ESteamNetworkingConfig_FakePacketReorder_Time = 8,

	/// [global float 0--100] Globally duplicate some percentage of packets we send
	k_ESteamNetworkingConfig_FakePacketDup_Send = 26,
	k_ESteamNetworkingConfig_FakePacketDup_Recv = 27,

	/// [global int32] Amount of delay, in ms, to delay duplicated packets.
	/// (We chose a random delay between 0 and this value)
	k_ESteamNetworkingConfig_FakePacketDup_TimeMax = 28,

	/// [connection int32] Timeout value (in ms) to use when first connecting
	k_ESteamNetworkingConfig_TimeoutInitial = 24,

	/// [connection int32] Timeout value (in ms) to use after connection is established
	k_ESteamNetworkingConfig_TimeoutConnected = 25,

	/// [connection int32] Upper limit of buffered pending bytes to be sent,
	/// if this is reached SendMessage will return k_EResultLimitExceeded
	/// Default is 512k (524288 bytes)
	k_ESteamNetworkingConfig_SendBufferSize = 9,

	/// [connection int32] Minimum/maximum send rate clamp, 0 is no limit.
	/// This value will control the min/max allowed sending rate that 
	/// bandwidth estimation is allowed to reach.  Default is 0 (no-limit)
	k_ESteamNetworkingConfig_SendRateMin = 10,
	k_ESteamNetworkingConfig_SendRateMax = 11,

	/// [connection int32] Nagle time, in microseconds.  When SendMessage is called, if
	/// the outgoing message is less than the size of the MTU, it will be
	/// queued for a delay equal to the Nagle timer value.  This is to ensure
	/// that if the application sends several small messages rapidly, they are
	/// coalesced into a single packet.
	/// See historical RFC 896.  Value is in microseconds. 
	/// Default is 5000us (5ms).
	k_ESteamNetworkingConfig_NagleTime = 12,

	/// [connection int32] Don't automatically fail IP connections that don't have
	/// strong auth.  On clients, this means we will attempt the connection even if
	/// we don't know our identity or can't get a cert.  On the server, it means that
	/// we won't automatically reject a connection due to a failure to authenticate.
	/// (You can examine the incoming connection and decide whether to accept it.)
	k_ESteamNetworkingConfig_IP_AllowWithoutAuth = 23,

	/// [connection int32] Do not send UDP packets with a payload of
	/// larger than N bytes.  If you set this, k_ESteamNetworkingConfig_MTU_DataSize
	/// is automatically adjusted
	k_ESteamNetworkingConfig_MTU_PacketSize = 32,

	/// [connection int32] (read only) Maximum message size you can send that
	/// will not fragment, based on k_ESteamNetworkingConfig_MTU_PacketSize
	k_ESteamNetworkingConfig_MTU_DataSize = 33,

	//
	// Settings for SDR relayed connections
	//

	/// [int32 global] If the first N pings to a port all fail, mark that port as unavailable for
	/// a while, and try a different one.  Some ISPs and routers may drop the first
	/// packet, so setting this to 1 may greatly disrupt communications.
	k_ESteamNetworkingConfig_SDRClient_ConsecutitivePingTimeoutsFailInitial = 19,

	/// [int32 global] If N consecutive pings to a port fail, after having received successful 
	/// communication, mark that port as unavailable for a while, and try a 
	/// different one.
	k_ESteamNetworkingConfig_SDRClient_ConsecutitivePingTimeoutsFail = 20,

	/// [int32 global] Minimum number of lifetime pings we need to send, before we think our estimate
	/// is solid.  The first ping to each cluster is very often delayed because of NAT,
	/// routers not having the best route, etc.  Until we've sent a sufficient number
	/// of pings, our estimate is often inaccurate.  Keep pinging until we get this
	/// many pings.
	k_ESteamNetworkingConfig_SDRClient_MinPingsBeforePingAccurate = 21,

	/// [int32 global] Set all steam datagram traffic to originate from the same
	/// local port. By default, we open up a new UDP socket (on a different local
	/// port) for each relay.  This is slightly less optimal, but it works around
	/// some routers that don't implement NAT properly.  If you have intermittent
	/// problems talking to relays that might be NAT related, try toggling
	/// this flag
	k_ESteamNetworkingConfig_SDRClient_SingleSocket = 22,

	/// [global string] Code of relay cluster to force use.  If not empty, we will
	/// only use relays in that cluster.  E.g. 'iad'
	k_ESteamNetworkingConfig_SDRClient_ForceRelayCluster = 29,

	/// [connection string] For debugging, generate our own (unsigned) ticket, using
	/// the specified  gameserver address.  Router must be configured to accept unsigned
	/// tickets.
	k_ESteamNetworkingConfig_SDRClient_DebugTicketAddress = 30,

	/// [global string] For debugging.  Override list of relays from the config with
	/// this set (maybe just one).  Comma-separated list.
	k_ESteamNetworkingConfig_SDRClient_ForceProxyAddr = 31,

	//
	// Log levels for debuging information.  A higher priority
	// (lower numeric value) will cause more stuff to be printed.  
	//
	k_ESteamNetworkingConfig_LogLevel_AckRTT = 13, // [connection int32] RTT calculations for inline pings and replies
	k_ESteamNetworkingConfig_LogLevel_PacketDecode = 14, // [connection int32] log SNP packets send
	k_ESteamNetworkingConfig_LogLevel_Message = 15, // [connection int32] log each message send/recv
	k_ESteamNetworkingConfig_LogLevel_PacketGaps = 16, // [connection int32] dropped packets
	k_ESteamNetworkingConfig_LogLevel_P2PRendezvous = 17, // [connection int32] P2P rendezvous messages
	k_ESteamNetworkingConfig_LogLevel_SDRRelayPings = 18, // [global int32] Ping relays

	k_ESteamNetworkingConfigValue__Force32Bit = 0x7fffffff
};

/// Return value of ISteamNetworkintgUtils::GetConfigValue
enum ESteamNetworkingGetConfigValueResult
{
	k_ESteamNetworkingGetConfigValue_BadValue = -1,	// No such configuration value
	k_ESteamNetworkingGetConfigValue_BadScopeObj = -2,	// Bad connection handle, etc
	k_ESteamNetworkingGetConfigValue_BufferTooSmall = -3, // Couldn't fit the result in your buffer
	k_ESteamNetworkingGetConfigValue_OK = 1,
	k_ESteamNetworkingGetConfigValue_OKInherited = 2, // A value was not set at this level, but the effective (inherited) value was returned.

	k_ESteamNetworkingGetConfigValueResult__Force32Bit = 0x7fffffff
};

//
// Debug output
//

/// Detail level for diagnostic output callback.
/// See ISteamNetworkingUtils::SetDebugOutputFunction
enum ESteamNetworkingSocketsDebugOutputType
{
	k_ESteamNetworkingSocketsDebugOutputType_None = 0,
	k_ESteamNetworkingSocketsDebugOutputType_Bug = 1, // You used the API incorrectly, or an internal error happened
	k_ESteamNetworkingSocketsDebugOutputType_Error = 2, // Run-time error condition that isn't the result of a bug.  (E.g. we are offline, cannot bind a port, etc)
	k_ESteamNetworkingSocketsDebugOutputType_Important = 3, // Nothing is wrong, but this is an important notification
	k_ESteamNetworkingSocketsDebugOutputType_Warning = 4,
	k_ESteamNetworkingSocketsDebugOutputType_Msg = 5, // Recommended amount
	k_ESteamNetworkingSocketsDebugOutputType_Verbose = 6, // Quite a bit
	k_ESteamNetworkingSocketsDebugOutputType_Debug = 7, // Practically everything
	k_ESteamNetworkingSocketsDebugOutputType_Everything = 8, // Wall of text, detailed packet contents breakdown, etc

	k_ESteamNetworkingSocketsDebugOutputType__Force32Bit = 0x7fffffff
};

/// Describe the status of a particular network resource
enum ESteamNetworkingAvailability
{
	// Negative values indicate a problem.
	//
	// In general, we will not automatically retry unless you take some action that
	// depends on of requests this resource, such as querying the status, attempting
	// to initiate a connection, receive a connection, etc.  If you do not take any
	// action at all, we do not automatically retry in the background.
	k_ESteamNetworkingAvailability_CannotTry = -102,		// A dependent resource is missing, so this service is unavailable.  (E.g. we cannot talk to routers because Internet is down or we don't have the network config.)
	k_ESteamNetworkingAvailability_Failed = -101,			// We have tried for enough time that we would expect to have been successful by now.  We have never been successful
	k_ESteamNetworkingAvailability_Previously = -100,		// We tried and were successful at one time, but now it looks like we have a problem

	k_ESteamNetworkingAvailability_Retrying = -10,		// We previously failed and are currently retrying

	// Not a problem, but not ready either
	k_ESteamNetworkingAvailability_NeverTried = 1,		// We don't know because we haven't ever checked/tried
	k_ESteamNetworkingAvailability_Waiting = 2,			// We're waiting on a dependent resource to be acquired.  (E.g. we cannot obtain a cert until we are logged into Steam.  We cannot measure latency to relays until we have the network config.)
	k_ESteamNetworkingAvailability_Attempting = 3,		// We're actively trying now, but are not yet successful.

	k_ESteamNetworkingAvailability_Current = 100,			// Resource is online/available


	k_ESteamNetworkingAvailability_Unknown = 0,			// Internal dummy/sentinel, or value is not applicable in this context
	k_ESteamNetworkingAvailability__Force32bit = 0x7fffffff,
};


//
// Describing network hosts
//

/// Different methods of describing the identity of a network host
enum ESteamNetworkingIdentityType
{
	// Dummy/empty/invalid.
	// Plese note that if we parse a string that we don't recognize
	// but that appears reasonable, we will NOT use this type.  Instead
	// we'll use k_ESteamNetworkingIdentityType_UnknownType.
	k_ESteamNetworkingIdentityType_Invalid = 0,

	//
	// Basic platform-specific identifiers.
	//
	k_ESteamNetworkingIdentityType_SteamID = 16, // 64-bit CSteamID

	//
	// Special identifiers.
	//

	// Use their IP address (and port) as their "identity".
	// These types of identities are always unauthenticated.
	// They are useful for porting plain sockets code, and other
	// situations where you don't care about authentication.  In this
	// case, the local identity will be "localhost",
	// and the remote address will be their network address.
	//
	// We use the same type for either IPv4 or IPv6, and
	// the address is always store as IPv6.  We use IPv4
	// mapped addresses to handle IPv4.
	k_ESteamNetworkingIdentityType_IPAddress = 1,

	// Generic string/binary blobs.  It's up to your app to interpret this.
	// This library can tell you if the remote host presented a certificate
	// signed by somebody you have chosen to trust, with this identity on it.
	// It's up to you to ultimately decide what this identity means.
	k_ESteamNetworkingIdentityType_GenericString = 2,
	k_ESteamNetworkingIdentityType_GenericBytes = 3,

	// This identity type is used when we parse a string that looks like is a
	// valid identity, just of a kind that we don't recognize.  In this case, we
	// can often still communicate with the peer!  Allowing such identities
	// for types we do not recognize useful is very useful for forward
	// compatibility.
	k_ESteamNetworkingIdentityType_UnknownType = 4,

	// Make sure this enum is stored in an int.
	k_ESteamNetworkingIdentityType__Force32bit = 0x7fffffff,
};

/// Setup callback for debug output, and the desired verbosity you want.
typedef void (*FSteamNetworkingSocketsDebugOutput)( ESteamNetworkingSocketsDebugOutputType nType, const char *pszMsg );

#pragma pack( push, 1 )

/// A struct used to describe our readiness to use the relay network.
/// To do this we first need to fetch the network configuration,
/// which describes what POPs are available.
struct SteamRelayNetworkStatus_t
{ 
	enum { k_iCallback = k_iSteamNetworkingUtilsCallbacks + 1 };

	/// Summary status.  When this is "current", initialization has
	/// completed.  Anything else means you are not ready yet, or
	/// there is a significant problem.
	ESteamNetworkingAvailability m_eAvail;

	/// Nonzero if latency measurement is in progress (or pending,
	/// awaiting a prerequisite).
	int m_bPingMeasurementInProgress;

	/// Status obtaining the network config.  This is a prerequisite
	/// for relay network access.
	///
	/// Failure to obtain the network config almost always indicates
	/// a problem with the local internet connection.
	ESteamNetworkingAvailability m_eAvailNetworkConfig;

	/// Current ability to communicate with ANY relay.  Note that
	/// the complete failure to communicate with any relays almost
	/// always indicates a problem with the local Internet connection.
	/// (However, just because you can reach a single relay doesn't
	/// mean that the local connection is in perfect health.)
	ESteamNetworkingAvailability m_eAvailAnyRelay;

	/// Non-localized English language status.  For diagnostic/debugging
	/// purposes only.
	char m_debugMsg[ 256 ];
};

/// NOTE: This object should only be used in the same process!  Do not serialize it,
/// send it over the wire, or persist it in a file or database!  If you need
/// to do that, convert it to a string representation using the methods in
/// ISteamNetworkingUtils().
struct SteamNetworkPingLocation_t
{
	uint8 m_data[ 512 ];
};

typedef struct SteamNetworkingIPAddr
{
	union
	{
		uint8 m_ipv6[ 16 ];
		struct
		{
			uint64 m_8zeros;
			uint16 m_0000;
			uint16 m_ffff;
			uint8 m_ip[ 4 ];
		} m_ipv4;
	} ip;
	uint16 m_port;
} SteamNetworkingIPAddr;

#define k_cchMaxGenericString 32
#define k_cchMaxXboxPairwiseID 32
#define k_cbMaxGenericBytes 32

typedef struct SteamNetworkingIdentity
{
	ESteamNetworkingIdentityType m_eType;

	int m_cbSize;

	union {
		uint64 m_steamID64;
		char m_szGenericString[ k_cchMaxGenericString ];
		char m_szXboxPairwiseID[ k_cchMaxXboxPairwiseID ];
		uint8 m_genericBytes[ k_cbMaxGenericBytes ];
		SteamNetworkingIPAddr m_ip;
		uint32 m_reserved[ 32 ];
	} data;
} SteamNetworkingIdentity;

#pragma pack( pop )


#define STEAMNETWORKINGUTILS_INTERFACE_VERSION_001 "SteamNetworkingUtils001"
#define STEAMNETWORKINGUTILS_INTERFACE_VERSION_002 "SteamNetworkingUtils002"

#endif // STEAMNETWORKINGUTILSCOMMON_H
