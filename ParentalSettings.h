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

#ifndef PARENTALSETTINGSCOMMON_H
#define PARENTALSETTINGSCOMMON_H
#ifdef _WIN32
#pragma once
#endif

enum EParentalFeature
{
	k_EParentalFeatureInvalid = 0,	// Invalid
	k_EParentalFeatureStore,	// Store
	k_EParentalFeatureCommunity,	// Community
	k_EParentalFeatureProfile,	// Profile
	k_EParentalFeatureFriends,	// Friends
	k_EParentalFeatureNews,	// News
	k_EParentalFeatureTrading,	// Trading
	k_EParentalFeatureSettings,	// Settings
	k_EParentalFeatureConsole,	// Console
	k_EParentalFeatureBrowser,	// Browser
	k_EParentalFeatureParentalSetup,	// ParentalSetup
	k_EParentalFeatureLibrary,	// Library
	k_EParentalFeatureTest,	// Test
};

// versions
#define STEAMPARENTALSETTINGS_INTERFACE_VERSION_001 "SteamParentalSettings001"


#endif // PARENTALSETTINGSCOMMON_H
