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

#ifndef ISTEAMTV001_H
#define ISTEAMTV001_H
#ifdef _WIN32
#pragma once	
#endif

#include "SteamTypes.h"
#include "SteamTVCommon.h"

//-----------------------------------------------------------------------------
// Purpose: Functions to provide information about Steam Remote Play sessions
//-----------------------------------------------------------------------------
abstract_class ISteamTV001
{
public:
	virtual bool IsBroadcasting(int *pnNumViewers) = 0;
	virtual void AddBroadcastGameData(const char *pchKey, const char *pchValue) = 0;
	virtual void RemoveBroadcastGameData(const char *pchKey) = 0;
	virtual void AddTimelineMarker(const char *pchTemplateName, bool bPersistent, uint8 nColorR, uint8 nColorG, uint8 nColorB) = 0;
	virtual void RemoveTimelineMarker() = 0;
	virtual uint32 AddRegion(const char *pchElementName, const char *pchTimelineDataSection, const struct SteamTVRegion_t *pSteamTVRegion, ESteamTVRegionBehavior eSteamTVRegionBehavior) = 0;
	virtual void RemoveRegion(uint32 unRegionHandle) = 0;
};

#endif // ISTEAMTV001_H
