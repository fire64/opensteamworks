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

#ifndef STEAMPARTIESCOMMON_H
#define STEAMPARTIESCOMMON_H
#ifdef _WIN32
#pragma once
#endif

typedef uint64 PartyBeaconID_t;

//-----------------------------------------------------------------------------
// Purpose: Functions for quickly creating a Party with friends or acquaintances,
//			EG from chat rooms.
//-----------------------------------------------------------------------------
enum ESteamPartyBeaconLocationType
{
	k_ESteamPartyBeaconLocationType_Invalid = 0,
	k_ESteamPartyBeaconLocationType_ChatGroup = 1,

	k_ESteamPartyBeaconLocationType_Max,
};

struct SteamPartyBeaconLocation_t
{
	ESteamPartyBeaconLocationType m_eType;
	uint64 m_ulLocationID;
};

struct SteamPartyBeaconLocation_v001_t
{
	ESteamPartyBeaconLocationType m_eType;
	uint64 m_ulLocationID;
};


enum ESteamPartyBeaconLocationData
{
	k_ESteamPartyBeaconLocationDataInvalid = 0,
	k_ESteamPartyBeaconLocationDataName = 1,
	k_ESteamPartyBeaconLocationDataIconURLSmall = 2,
	k_ESteamPartyBeaconLocationDataIconURLMedium = 3,
	k_ESteamPartyBeaconLocationDataIconURLLarge = 4,
};

#define STEAMPARTIES_INTERFACE_VERSION_001 "SteamParties001"
#define STEAMPARTIES_INTERFACE_VERSION_002 "SteamParties002"


#endif // STEAMPARTIESCOMMON_H
