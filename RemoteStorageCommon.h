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

#ifndef REMOTESTORAGECOMMON_H
#define REMOTESTORAGECOMMON_H
#ifdef _WIN32
#pragma once
#endif



#define STEAMREMOTESTORAGE_INTERFACE_VERSION_001 "STEAMREMOTESTORAGE_INTERFACE_VERSION001"
#define STEAMREMOTESTORAGE_INTERFACE_VERSION_002 "STEAMREMOTESTORAGE_INTERFACE_VERSION002"
#define STEAMREMOTESTORAGE_INTERFACE_VERSION_003 "STEAMREMOTESTORAGE_INTERFACE_VERSION003"
#define STEAMREMOTESTORAGE_INTERFACE_VERSION_004 "STEAMREMOTESTORAGE_INTERFACE_VERSION004"
#define STEAMREMOTESTORAGE_INTERFACE_VERSION_005 "STEAMREMOTESTORAGE_INTERFACE_VERSION005"
#define STEAMREMOTESTORAGE_INTERFACE_VERSION_006 "STEAMREMOTESTORAGE_INTERFACE_VERSION006"

#define CLIENTREMOTESTORAGE_INTERFACE_VERSION "CLIENTREMOTESTORAGE_INTERFACE_VERSION001"



enum ERemoteStorageFileRoot
{
	k_ERemoteStorageFileRootInvalid = -1,
	k_ERemoteStorageFileRootDefault,
	k_ERemoteStorageFileRootGameInstall,
	k_ERemoteStorageFileRootWinMyDocuments,
	k_ERemoteStorageFileRootWinAppDataLocal,
	k_ERemoteStorageFileRootWinAppDataRoaming,
	k_ERemoteStorageFileRootSteamUserBaseStorage,
	k_ERemoteStorageFileRootMacHome,
	k_ERemoteStorageFileRootMacAppSupport,
	k_ERemoteStorageFileRootMacDocuments,
	k_ERemoteStorageFileRootMax
};

enum ERemoteStorageSyncState
{
	k_ERemoteSyncStateDisabled = 0,
	k_ERemoteSyncStateUnknown = 1,
	k_ERemoteSyncStateSynchronized = 2,
	k_ERemoteSyncStateSyncInProgress = 3,
	k_ERemoteSyncStatePendingChangesInCloud = 4,
	k_ERemoteSyncStatePendingChangesLocally = 5,
	k_ERemoteSyncStatePendingChangesInCloudAndLocally = 6,
	k_ERemoteSyncStateConflictingChanges = 7,
};

enum EUCMFilePrivacyState
{
	k_EUCMFilePrivacyStateInvalid = -1,

	k_EUCMFilePrivacyStateUnpublished = 0,
	k_EUCMFilePrivacyStatePublished = 1,

	k_EUCMFilePrivacyStatePrivate = 2,
	k_EUCMFilePrivacyStateFriendsOnly = 4,
	k_EUCMFilePrivacyStatePublic = 8,
	k_EUCMFilePrivacyStateAll = 14,
};

enum ERemoteStoragePlatform
{
	k_ERemoteStoragePlatformNone		= 0,
	k_ERemoteStoragePlatformWindows		= (1 << 0),
	k_ERemoteStoragePlatformOSX			= (1 << 1 ),
	k_ERemoteStoragePlatformPS3			= (1 << 2),
	k_ERemoteStoragePlatformReserved1	= (1 << 3),
	k_ERemoteStoragePlatformReserved2	= (1 << 4),

	k_ERemoteStoragePlatformAll = 0xffffffff
};

// Ways to handle a synchronization conflict
enum EResolveConflict
{
	k_EResolveConflictKeepClient = 1,		// The local version of each file will be used to overwrite the server version
	k_EResolveConflictKeepServer = 2,		// The server version of each file will be used to overwrite the local version
};

enum ERemoteStoragePublishedFileVisibility
{
	// TODO: Reverse this enum
};

enum ERemoteStoragePublishedFileSortOrder
{
	// TODO: Reverse this enum
};

enum EWorkshopFileType
{
	// TODO: Reverse this enum
};


#pragma pack( push, 8 )

struct SteamParamStringArray_t
{
	// TODO: Reverse this struct
#ifdef _S4N_
	int iPadding;
#endif
};

struct RemoteStorageUpdatePublishedFileRequest_t
{
	// TODO: Reverse this struct
#ifdef _S4N_
	int iPadding;
#endif
};



//-----------------------------------------------------------------------------
// Purpose: sent when the local file cache is fully synced with the server for an app
//          That means that an application can be started and has all latest files
//-----------------------------------------------------------------------------
struct RemoteStorageAppSyncedClient_t
{
	enum { k_iCallback = k_iClientRemoteStorageCallbacks + 1 };
	AppId_t m_nAppID;
	EResult m_eResult;
	int m_unNumDownloads;
};

//-----------------------------------------------------------------------------
// Purpose: sent when the server is fully synced with the local file cache for an app
//          That means that we can shutdown Steam and our data is stored on the server
//-----------------------------------------------------------------------------
struct RemoteStorageAppSyncedServer_t
{
	enum { k_iCallback = k_iClientRemoteStorageCallbacks + 2 };
	AppId_t m_nAppID;
	EResult m_eResult;
	int m_unNumUploads;
};

//-----------------------------------------------------------------------------
// Purpose: Status of up and downloads during a sync session
//       
//-----------------------------------------------------------------------------
struct RemoteStorageAppSyncProgress_t
{
	enum { k_iCallback = k_iClientRemoteStorageCallbacks + 3 };
	char m_rgchCurrentFile[260];				// Current file being transferred
	AppId_t m_nAppID;							// App this info relates to
	uint32 m_uBytesTransferredThisChunk;		// Bytes transferred this chunk
	double m_dAppPercentComplete;				// Percent complete that this app's transfers are
	bool m_bUploading;							// if false, downloading
};

struct RemoteStorageAppInfoLoaded_t
{
	enum { k_iCallback = k_iClientRemoteStorageCallbacks + 4 };

	AppId_t m_nAppID;
	EResult m_eResult;
};

//-----------------------------------------------------------------------------
// Purpose: Sent after we've determined the list of files that are out of sync
//          with the server.
//-----------------------------------------------------------------------------
struct RemoteStorageAppSyncStatusCheck_t
{
	enum { k_iCallback = k_iClientRemoteStorageCallbacks + 5 };
	AppId_t m_nAppID;
	EResult m_eResult;
};

//-----------------------------------------------------------------------------
// Purpose: Sent after a conflict resolution attempt.
//-----------------------------------------------------------------------------
struct RemoteStorageConflictResolution_t
{
	enum { k_iCallback = k_iClientRemoteStorageCallbacks + 6 };
	AppId_t m_nAppID;
	EResult m_eResult;
};

//-----------------------------------------------------------------------------
// Purpose: The result of a call to FileShare()
//-----------------------------------------------------------------------------
struct RemoteStorageFileShareResult_t
{
	enum { k_iCallback = k_iClientRemoteStorageCallbacks + 7 };
	EResult m_eResult;			// The result of the operation
	UGCHandle_t m_hFile;		// The handle that can be shared with users and features
};

//-----------------------------------------------------------------------------
// Purpose: The result of a call to UGCDownload()
//-----------------------------------------------------------------------------
struct Deprecated_RemoteStorageDownloadUGCResult_t
{
	enum { k_iCallback = k_iClientRemoteStorageCallbacks + 8 };
	EResult m_eResult;				// The result of the operation.
	UGCHandle_t m_hFile;			// The handle to the file that was attempted to be downloaded.
	AppId_t m_nAppID;				// ID of the app that created this file.
	int32 m_nSizeInBytes;			// The size of the file that was downloaded, in bytes.
	char *m_pchFileName;			// The name of the file that was downloaded. This pointer is
									// not guaranteed to be valid indefinitely.
	uint64 m_ulSteamIDOwner;		// Steam ID of the user who created this content.
};


// TODO : Add callbacks 1309 to 1316
//RemoteStorageEnumerateUserPublishedFilesResult_t

//-----------------------------------------------------------------------------
// Purpose: The result of a call to UGCDownload()
//-----------------------------------------------------------------------------
struct RemoteStorageDownloadUGCResult_t
{
	enum { k_iCallback = k_iClientRemoteStorageCallbacks + 17 };
	EResult m_eResult;				// The result of the operation.
	UGCHandle_t m_hFile;			// The handle to the file that was attempted to be downloaded.
	AppId_t m_nAppID;				// ID of the app that created this file.
	int32 m_nSizeInBytes;			// The size of the file that was downloaded, in bytes.
	char m_pchFileName[260];		// The name of the file that was downloaded.
	uint64 m_ulSteamIDOwner;		// Steam ID of the user who created this content.
};

#pragma pack( pop )



#endif // REMOTESTORAGECOMMON_H
