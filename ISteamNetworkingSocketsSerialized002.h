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

#ifndef ISTEAMNETWORKINGSOCKETSSERIALIZED002_H
#define ISTEAMNETWORKINGSOCKETSSERIALIZED002_H
#ifdef _WIN32
#pragma once	
#endif

#include "SteamTypes.h"
#include "SteamNetworkingSocketsSerializedCommon.h"

//-----------------------------------------------------------------------------
// Purpose: Functions to provide information about Steam Remote Play sessions
//-----------------------------------------------------------------------------
abstract_class ISteamNetworkingSocketsSerialized002
{
public:
	virtual void SendP2PRendezvous( CSteamID steamIDRemote, uint32 unConnectionIDSrc, const void *pMsgRendezvous, uint32 cbRendezvous ) = 0;
	virtual void SendP2PConnectionFailure( CSteamID steamIDRemote, uint32 unConnectionIDDest, uint32 nReason, const char *pszReason ) = 0;
	virtual SteamAPICall_t GetCertAsync() = 0;
	virtual int GetNetworkConfigJSON( void *buf, uint32 cbBuf ) = 0;
	virtual void CacheRelayTicket( const void *pTicket, uint32 cbTicket ) = 0;
	virtual uint32 GetCachedRelayTicketCount() = 0;
	virtual int GetCachedRelayTicket( uint32 idxTicket, void *buf, uint32 cbBuf ) = 0;
	virtual void PostConnectionStateMsg( const void *pMsg, uint32 cbMsg ) = 0;
};


#endif // ISTEAMNETWORKINGSOCKETSSERIALIZED002_H