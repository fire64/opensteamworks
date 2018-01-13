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

#ifndef ICLIENTREMOTESTORAGE_H
#define ICLIENTREMOTESTORAGE_H
#ifdef _WIN32
#pragma once
#endif

#include "SteamTypes.h"
#include "RemoteStorageCommon.h"

abstract_class UNSAFE_INTERFACE IClientRemoteStorage
{
public:

	virtual bool FileWrite( AppId_t nAppId, ERemoteStorageFileRoot eRemoteStorageFileRoot, const char *pchFile, const void *pvData, int cubData ) = 0;
	virtual int32 GetFileSize( AppId_t nAppId, ERemoteStorageFileRoot eRemoteStorageFileRoot, const char *pchFile  ) = 0;

	virtual int FileRead( AppId_t nAppId, ERemoteStorageFileRoot eRemoteStorageFileRoot, const char *pchFile, void *pvData, int cubDataToRead ) = 0;
	
	virtual bool FileForget( AppId_t nAppId, ERemoteStorageFileRoot eRemoteStorageFileRoot, const char *pchFile ) = 0;
	virtual bool FileDelete( AppId_t nAppId, ERemoteStorageFileRoot eRemoteStorageFileRoot, const char *pchFile ) = 0;
	virtual SteamAPICall_t FileShare( AppId_t nAppId, ERemoteStorageFileRoot eRemoteStorageFileRoot, const char *pchFile ) = 0;

	virtual bool FileExists( AppId_t nAppId, ERemoteStorageFileRoot eRemoteStorageFileRoot, const char *pchFile ) = 0;

	virtual bool FilePersisted( AppId_t nAppId, ERemoteStorageFileRoot eRemoteStorageFileRoot, const char *pchFile ) = 0;
	virtual int64 GetFileTimestamp( AppId_t nAppId, ERemoteStorageFileRoot eRemoteStorageFileRoot, const char *pchFile ) = 0;

	virtual bool SetSyncPlatforms( AppId_t nAppId, ERemoteStorageFileRoot eRemoteStorageFileRoot, const char *pchFile, ERemoteStoragePlatform eRemoteStoragePlatform ) = 0;
	virtual int GetSyncPlatforms( AppId_t nAppId, ERemoteStorageFileRoot eRemoteStorageFileRoot, const char *pchFile ) = 0;

	virtual int32 GetFileCount( AppId_t nAppId, bool bFromExternalAPI ) = 0;
	virtual const char *GetFileNameAndSize( AppId_t nAppId, int iFile, ERemoteStorageFileRoot *peRemoteStorageFileRoot, int *pnFileSizeInBytes, bool bFromExternalAPI ) = 0;

	virtual bool GetQuota( AppId_t nAppId, int32 *pnTotalBytes, int32 *pnAvailableBytes ) = 0;
	
	virtual bool IsCloudEnabledForAccount();
	virtual bool IsCloudEnabledForApp( AppId_t nAppId );
	virtual bool SetCloudEnabledForApp( AppId_t nAppId, bool bEnable );

	virtual SteamAPICall_t UGCDownload( UGCHandle_t hContent, bool bUseNewCallback ) = 0; // Old callback id = 1308, new callback id = 1317
	virtual bool GetUGCDownloadProgress( UGCHandle_t hContent, uint32 *puDownloadedBytes, uint32 *puTotalBytes );
	virtual bool GetUGCDetails( UGCHandle_t hContent, AppId_t *pnAppID, char **ppchName, int32 *pnFileSizeInBytes, CSteamID *pSteamIDOwner ) = 0;
	virtual int32 UGCRead( UGCHandle_t hContent, void *pubDest, int32 nDestBufferSize ) = 0;
	virtual int32 GetCachedUGCCount() = 0;
	virtual UGCHandle_t GetCachedUGCHandle( int32 iCachedContent ) = 0;

	virtual SteamAPICall_t PublishFile( AppId_t nAppId, ERemoteStorageFileRoot eRemoteStorageFileRoot, const char *cszFileName, const char *cszPreviewFileName, AppId_t nConsumerAppId , const char *cszTitle, const char *cszDescription, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility, bool bOverwrite, SteamParamStringArray_t *pTags, bool bWorkshopFile ) = 0;

	virtual JobID_t CreatePublishedFileUpdateRequest( AppId_t nAppId, UGCHandle_t m_hFile ) = 0;
	virtual bool UpdatePublishedFileFile( JobID_t hUpdateRequest, const char *cszFile ) = 0;
	virtual bool UpdatePublishedFilePreviewFile( JobID_t hUpdateRequest, const char *cszPreviewFile ) = 0;
	virtual bool UpdatePublishedFileTitle( JobID_t hUpdateRequest, const char *cszTitle ) = 0;
	virtual bool UpdatePublishedFileDescription( JobID_t hUpdateRequest, const char *cszDescription ) = 0;
	virtual bool UpdatePublishedFileVisibility( JobID_t hUpdateRequest, ERemoteStoragePublishedFileVisibility eVisibility ) = 0;
	virtual bool UpdatePublishedFileTags( JobID_t hUpdateRequest, SteamParamStringArray_t *pTags ) = 0;
	virtual SteamAPICall_t CommitPublishedFileUpdate( AppId_t nAppId, ERemoteStorageFileRoot eRemoteStorageFileRoot, JobID_t hUpdateRequest ) = 0;
	
	virtual SteamAPICall_t GetPublishedFileDetails( UGCHandle_t hPublishedFile, bool bUseNewCallback ) = 0; // Old callback id = 1310, new callback id = 1318
	virtual SteamAPICall_t DeletePublishedFile( UGCHandle_t hPublishedFile ) = 0;
	virtual SteamAPICall_t EnumerateUserPublishedFiles( AppId_t nAppId, uint32 uStartIndex, ERemoteStoragePublishedFileSortOrder eOrder ) = 0;
	virtual SteamAPICall_t SubscribePublishedFile( AppId_t nAppId, UGCHandle_t hPublishedFile ) = 0;
	virtual SteamAPICall_t EnumerateUserSubscribedFiles( AppId_t nAppId, uint32 uStartIndex ) = 0;
	virtual SteamAPICall_t UnsubscribePublishedFile( AppId_t nAppId, UGCHandle_t hPublishedFile ) = 0;

	virtual SteamAPICall_t EnumerateCRERankedByVote( AppId_t nAppId, uint32 uStartIndex, uint32 cCount, SteamParamStringArray_t *pTags, SteamParamStringArray_t *pUserTags ) = 0;
	virtual SteamAPICall_t EnumerateCRERankedByTrend( AppId_t nAppId, uint32 uStartIndex, uint32 cDays, uint32 cCount, SteamParamStringArray_t *pTags, SteamParamStringArray_t *pUserTags ) = 0;
	virtual SteamAPICall_t GetCREItemVoteSummary( UGCHandle_t hPublishedFile ) = 0;
	
	virtual EResult FilePersist( AppId_t nAppId, ERemoteStorageFileRoot eRemoteStorageFileRoot, const char *pchFile ) = 0;

	virtual bool FileFetch( AppId_t nAppId, ERemoteStorageFileRoot eRemoteStorageFileRoot, const char *pchFile ) = 0;

	virtual bool ResolvePath( AppId_t nAppID, ERemoteStorageFileRoot eRemoteStorageFileRoot, const char *pchRelPath, char *pchDest, uint32 cchDest ) = 0;

	virtual EResult FileTouch( AppId_t nAppId, ERemoteStorageFileRoot eRemoteStorageFileRoot, const char *pchFile, bool ) = 0;

	virtual bool SetCloudEnabledForAccount( bool bEnabled );

	virtual void LoadLocalFileInfoCache( AppId_t nAppId ) = 0;

	virtual void EvaluateRemoteStorageSyncState( AppId_t nAppId ) = 0;
	virtual ERemoteStorageSyncState GetRemoteStorageSyncState( AppId_t nAppId ) = 0;

	virtual bool HaveLatestFilesLocally( AppId_t nAppId ) = 0;

	virtual bool GetConflictingFileTimestamps( AppId_t nAppId, RTime32* pnTimestampLocal, RTime32* pnTimestampRemote ) = 0;
	virtual bool ResolveSyncConflict( AppId_t nAppId, bool bAcceptLocalFiles ) = 0;

	virtual void SynchronizeApp( AppId_t nAppId, bool bSyncClient, bool bSyncServer ) = 0;
	virtual bool IsAppSyncInProgress( AppId_t nAppId ) = 0;

	virtual ERemoteStorageFileRoot ERemoteStorageFileRootFromName( const char *pchName ) = 0;
	virtual const char* PchNameFromERemoteStorageFileRoot( ERemoteStorageFileRoot eRemoteStorageFileRoot ) = 0;
	
	virtual bool ResetFileRequestState( AppId_t nAppId ) = 0;

	virtual void ClearPublishFileUpdateRequests( AppId_t nAppId ) = 0;
};

#endif // ICLIENTREMOTESTORAGE_H
