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


#ifndef ISTEAMPARENTALSETTINGS001_H
#define ISTEAMPARENTALSETTINGS001_H
#ifdef _WIN32
#pragma once
#endif

#include "SteamTypes.h"
#include "ParentalSettings.h"

//-----------------------------------------------------------------------------
// Purpose: Functions for making connections and sending data between clients,
//			traversing NAT's where possible
//-----------------------------------------------------------------------------
abstract_class ISteamParentalSettings001
{
public:
	virtual bool BIsParentalLockEnabled() = 0;
	virtual bool BIsParentalLockLocked() = 0;
	virtual bool BIsAppBlocked( AppId_t nAppID ) = 0;
	virtual bool BIsAppInBlockList( AppId_t nAppID ) = 0;
	virtual bool BIsFeatureBlocked( EParentalFeature eFeature ) = 0;
	virtual bool BIsFeatureInBlockList( EParentalFeature eFeature ) = 0;
};

#endif // ISTEAMPARENTALSETTINGS001_H
