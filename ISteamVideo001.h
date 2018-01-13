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

#ifndef ISTEAMVIDEO_001_H
#define ISTEAMVIDEO_001_H
#ifdef _WIN32
#pragma once
#endif

#include "SteamTypes.h"


abstract_class ISteamVideo001
{
public:

        virtual unknown_ret GetVideoURL( uint32 ) = 0;
        virtual unknown_ret IsBroadcasting( int32 * ) = 0;
};

#endif // ISTEAMVIDEO_001_H

