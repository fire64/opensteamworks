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

#ifndef ISTEAMUSERSTATS001_H
#define ISTEAMUSERSTATS001_H
#ifdef _WIN32
#pragma once
#endif

#include "SteamTypes.h"
#include "UserStatsCommon.h"

abstract_class ISteamUserStats001
{
public:
       virtual uint32 GetNumStats( CGameID nGameID ) = 0;
       virtual const char *GetStatName( CGameID nGameID, uint32 iStat ) = 0;
       virtual ESteamUserStatType GetStatType( CGameID nGameID, const char *pchName ) = 0;
       virtual uint32 GetNumAchievements( CGameID nGameID ) = 0;
       virtual const char *GetAchievementName( CGameID nGameID, uint32 iAchievement ) = 0;
       virtual uint32 GetNumGroupAchievements( CGameID nGameID ) = 0;
       virtual const char *GetGroupAchievementName( CGameID nGameID, uint32 iAchievement ) = 0;
       virtual bool RequestCurrentStats( CGameID nGameID ) = 0;
       virtual bool GetStat( CGameID nGameID, const char *pchName, int32 *pData ) = 0;
       virtual bool GetStat( CGameID nGameID, const char *pchName, float *pData ) = 0;
       virtual bool SetStat( CGameID nGameID, const char *pchName, int32 nData ) = 0;
       virtual bool SetStat( CGameID nGameID, const char *pchName, float fData ) = 0;
       virtual bool UpdateAvgRateStat( CGameID nGameID, const char *pchName, float flCountThisSession, double dSessionLength ) = 0;
       virtual bool GetAchievement( CGameID nGameID, const char *pchName, bool *pbAchieved ) = 0;
       virtual bool GetGroupAchievement( CGameID nGameID, const char *pchName, bool *pbAchieved ) = 0;
       virtual bool SetAchievement( CGameID nGameID, const char *pchName ) = 0;
       virtual bool SetGroupAchievement( CGameID nGameID, const char *pchName ) = 0;
       virtual bool StoreStats( CGameID nGameID ) = 0;
       virtual bool ClearAchievement( CGameID nGameID, const char *pchName ) = 0;
       virtual bool ClearGroupAchievement( CGameID nGameID, const char *pchName ) = 0;
       virtual int GetAchievementIcon( CGameID nGameID, const char *pchName ) = 0;
       virtual const char *GetAchievementDisplayAttribute( CGameID nGameID, const char *pchName, const char *pchKey ) = 0;
};

#endif // ISTEAMUSERSTATS001_H
