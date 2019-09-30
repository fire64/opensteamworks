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

#ifndef ISTEAMAPPLIST001_H
#define ISTEAMAPPLIST001_H
#ifdef _WIN32
#pragma once
#endif

#include "SteamTypes.h"
#include "AppsCommon.h"

//-----------------------------------------------------------------------------
// Purpose: interface to app data
//-----------------------------------------------------------------------------
abstract_class ISteamAppList001
{
public:
	virtual uint32 GetNumInstalledApps() = 0;
	virtual uint32 GetInstalledApps( AppId_t *pvecAppID, uint32 unMaxAppIDs ) = 0;

	virtual int  GetAppName( AppId_t nAppID, STEAM_OUT_STRING() char *pchName, int cchNameMax ) = 0; // returns -1 if no name was found
	virtual int  GetAppInstallDir( AppId_t nAppID, char *pchDirectory, int cchNameMax ) = 0; // returns -1 if no dir was found

	virtual int GetAppBuildId( AppId_t nAppID ) = 0; // return the buildid of this app, may change at any time based on backend updates to the game
};

#endif // ISTEAMAPPS001_H
