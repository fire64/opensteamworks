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

#ifndef ICLIENTDEPOTBUILDER_H
#define ICLIENTDEPOTBUILDER_H
#ifdef _WIN32
#pragma once
#endif

#include "SteamTypes.h"



#define CLIENTDEPOTBUILDER_INTERFACE_VERSION "CLIENTDEPOTBUILDER_INTERFACE_VERSION001"



typedef enum EDepotBuildStatus
{
	k_EDepotBuildStatusInvalid = 0,
	k_EDepotBuildStatusProcessingConfig = 1,
	k_EDepotBuildStatusBuildingFileList = 2,
	k_EDepotBuildStatusProcessingData = 3,
	k_EDepotBuildStatusUploadingData = 4,
	k_EDepotBuildStatusCompleted = 5,
	k_EDepotBuildStatusFailed = 6,
}  EDepotBuildStatus;

//-----------------------------------------------------------------------------
// Purpose: Status of a given depot version, these are stored in the DB, don't renumber
//-----------------------------------------------------------------------------
typedef enum EStatusDepotVersion
{
	k_EStatusDepotVersionInvalid = 0,
	k_EStatusDepotVersionCompleteDisabled = 1,
	k_EStatusDepotVersionCompleteEnabledBeta = 2,
	k_EStatusDepotVersionCompleteEnabledPublic = 3,
} EStatusDepotVersion;


typedef uint32 HDEPOTBUILD;


abstract_class IClientDepotBuilder
{
public:
	virtual uint32 RegisterAppBuild( AppId_t nAppID, const char *cszDescription, const char *cszBetaKey ) = 0;
	virtual uint32 GetRegisteredBuildID( uint32 ) = 0;

	virtual HDEPOTBUILD InitializeDepotBuildForConfigFile( const char *pchConfigFile ) = 0;
	
	virtual bool StartBuild( HDEPOTBUILD hDepotBuild, uint32 uFlags, const char *cszBetaKey, const char *cszChunksPath, uint32 ) = 0;

	virtual bool BGetDepotBuildStatus( HDEPOTBUILD hDepotBuild, EDepotBuildStatus* pStatusOut, uint32* pPercentDone ) = 0;
	virtual bool CloseDepotBuildHandle( HDEPOTBUILD hDepotBuild ) = 0;

	virtual HDEPOTBUILD ReconstructDepotFromManifestAndChunks( const char *pchLocalManifestPath, const char *pchLocalChunkPath, const char *pchRestorePath ) = 0;

	virtual bool BGetChunkCounts( HDEPOTBUILD hDepotBuild, uint32 *unTotalChunksInNewBuild, uint32 *unChunksAlsoInOldBuild ) = 0;

	virtual bool GetManifestGIDs( HDEPOTBUILD hDepotBuild, GID_t* pBaselineGID, GID_t* pNewGID ) = 0;

	virtual uint32 FinishAppBuild( uint32 uBuildID, uint32 nAppID, const char *cszBetaKey, bool bOnlyFinish, uint32 cNumSkipDepots ) = 0;
};

#endif // ICLIENTDEPOTBUILDER_H
