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

#ifndef ISTEAMREMOTEPLAY001_H
#define ISTEAMREMOTEPLAY001_H
#ifdef _WIN32
#pragma once	
#endif

#include "SteamTypes.h"
#include "SteamRemotePlayCommon.h"

//-----------------------------------------------------------------------------
// Purpose: Functions to provide information about Steam Remote Play sessions
//-----------------------------------------------------------------------------
abstract_class ISteamRemotePlay001
{
public:
	// Get the number of currently connected Steam Remote Play sessions
	virtual uint32 GetSessionCount() = 0;
	
	// Get the currently connected Steam Remote Play session ID at the specified index. Returns zero if index is out of bounds.
	virtual uint32 GetSessionID( int iSessionIndex ) = 0;

	// Get the SteamID of the connected user
	virtual CSteamID GetSessionSteamID( uint32 unSessionID ) = 0;

	// Get the name of the session client device
	// This returns NULL if the sessionID is not valid
	virtual const char *GetSessionClientName( uint32 unSessionID ) = 0;

	// Get the form factor of the session client device
	virtual ESteamDeviceFormFactor GetSessionClientFormFactor( uint32 unSessionID ) = 0;

	// Get the resolution, in pixels, of the session client device
	// This is set to 0x0 if the resolution is not available
	virtual bool BGetSessionClientResolution( uint32 unSessionID, int *pnResolutionX, int *pnResolutionY ) = 0;
};


#endif // ISTEAMREMOTEPLAY001_H
