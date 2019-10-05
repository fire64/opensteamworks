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

#ifndef STEAMREMOTEPLAYCOMMON_H
#define STEAMREMOTEPLAYCOMMON_H
#ifdef _WIN32
#pragma once
#endif

//-----------------------------------------------------------------------------
// Purpose: The form factor of a device
//-----------------------------------------------------------------------------
enum ESteamDeviceFormFactor
{
	k_ESteamDeviceFormFactorUnknown,
	k_ESteamDeviceFormFactorPhone,
	k_ESteamDeviceFormFactorTablet,
	k_ESteamDeviceFormFactorComputer,
	k_ESteamDeviceFormFactorTV,
};

#define STEAMREMOTEPLAY_INTERFACE_VERSION_001 "STEAMREMOTEPLAY_INTERFACE_VERSION001"


#endif // STEAMREMOTEPLAYCOMMON_H
