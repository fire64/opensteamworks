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

#ifndef ISTEAMSTARINTERNAL001_H
#define ISTEAMSTARINTERNAL001_H
#ifdef _WIN32
#pragma once	
#endif

#include "SteamTypes.h"
#include "SteamSTARInternalCommon.h"

//-----------------------------------------------------------------------------
// Purpose: Functions to provide information about Steam Remote Play sessions
//-----------------------------------------------------------------------------
abstract_class ISteamSTARInternal001
{
public:
	virtual unknown_ret SendSerializedMessage(void*, unsigned int) = 0;
	virtual unknown_ret GetMessageResponse(unsigned long long, void*, unsigned int) = 0;
};

#endif // ISTEAMSTARINTERNAL001_H