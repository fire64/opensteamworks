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

#ifndef ISTEAMUGC010_H
#define ISTEAMUGC010H
#ifdef _WIN32
#pragma once
#endif

#include "SteamTypes.h"
#include "UGCCommon.h"


abstract_class ISteamUGC010
{
public:


	// Query UGC associated with a user. Creator app id or consumer app id must be valid and be set to the current running app. unPage should start at 1.
	virtual UGCQueryHandle_t CreateQueryUserUGCRequest( AccountID_t unAccountID, EUserUGCList eListType, EUGCMatchingUGCType eMatchingUGCType, EUserUGCListSortOrder eSortOrder, AppId_t nCreatorAppID, AppId_t nConsumerAppID, uint32 unPage ) = 0;

	// Query for all matching UGC. Creator app id or consumer app id must be valid and be set to the current running app. unPage should start at 1.
	virtual UGCQueryHandle_t CreateQueryAllUGCRequest( EUGCQuery eQueryType, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t nCreatorAppID, AppId_t nConsumerAppID, uint32 unPage ) = 0;

	virtual unknown_ret CreateQueryUGCDetailsRequest( uint64 *, uint32 ) = 0;
	
	// Send the query to Steam
	virtual SteamAPICall_t SendQueryUGCRequest( UGCQueryHandle_t handle ) = 0;

	// Retrieve an individual result after receiving the callback for querying UGC
	virtual bool GetQueryUGCResult( UGCQueryHandle_t handle, uint32 index, SteamUGCDetails_t *pDetails ) = 0;

	
	virtual unknown_ret GetQueryUGCPreviewURL( uint64, uint32, char *, uint32 ) = 0;
	virtual unknown_ret GetQueryUGCMetadata( uint64, uint32, char *, uint32 ) = 0;
	virtual unknown_ret GetQueryUGCChildren( uint64, uint32, uint64 *, uint32 ) = 0;
	virtual unknown_ret GetQueryUGCStatistic( uint64, uint32, EItemStatistic, uint64 * ) = 0;

	virtual unknown_ret GetQueryUGCNumAdditionalPreviews( uint64, uint32 ) = 0;
	virtual unknown_ret GetQueryUGCAdditionalPreview( uint64, uint32, uint32, char *, uint32, char *, uint32, EItemPreviewType * ) = 0;
	virtual unknown_ret GetQueryUGCNumKeyValueTags( uint64, uint32 ) = 0;
	virtual unknown_ret GetQueryUGCKeyValueTag( uint64, uint32, uint32, char *, uint32, char *, uint32 ) = 0;
	
	// Release the request to free up memory, after retrieving results
	virtual bool ReleaseQueryUGCRequest( UGCQueryHandle_t handle ) = 0;

	// Options to set for querying UGC
	virtual bool AddRequiredTag( UGCQueryHandle_t handle, const char *pTagName ) = 0;
	virtual bool AddExcludedTag( UGCQueryHandle_t handle, const char *pTagName ) = 0;
	virtual unknown_ret SetReturnOnlyIDs( uint64, bool ) = 0;
	virtual bool SetReturnKeyValueTags( UGCQueryHandle_t handle, bool ) = 0;
	virtual bool SetReturnLongDescription( UGCQueryHandle_t handle, bool bReturnLongDescription ) = 0;
	virtual bool SetReturnMetadata( UGCQueryHandle_t handle, bool ) = 0;
	virtual bool SetReturnChildren( UGCQueryHandle_t handle, bool ) = 0;
	virtual bool SetReturnAdditionalPreviews( UGCQueryHandle_t handle, bool ) = 0;
	virtual bool SetReturnTotalOnly( UGCQueryHandle_t handle, bool bReturnTotalOnly ) = 0;
	virtual unknown_ret SetReturnPlaytimeStats( UGCQueryHandle_t handle, uint32 ) = 0;
	virtual bool SetLanguage( UGCQueryHandle_t handle, const char * ) = 0;
	virtual bool SetAllowCachedResponse( UGCQueryHandle_t handle, uint32 unMaxAgeSeconds ) = 0;

	// Options only for querying user UGC
	virtual bool SetCloudFileNameFilter( UGCQueryHandle_t handle, const char *pMatchCloudFileName ) = 0;

	// Options only for querying all UGC
	virtual bool SetMatchAnyTag( UGCQueryHandle_t handle, bool bMatchAnyTag ) = 0;
	virtual bool SetSearchText( UGCQueryHandle_t handle, const char *pSearchText ) = 0;
	virtual bool SetRankedByTrendDays( UGCQueryHandle_t handle, uint32 unDays ) = 0;
	
	 virtual unknown_ret AddRequiredKeyValueTag( uint64, const char *, const char * ) = 0;

	// Request full details for one piece of UGC
	virtual SteamAPICall_t RequestUGCDetails( PublishedFileId_t nPublishedFileID, uint32 unMaxAgeSeconds ) = 0;

	// Steam Workshop Creator API
	virtual SteamAPICall_t CreateItem( AppId_t nConsumerAppId, EWorkshopFileType eFileType ) = 0; // create new item for this app with no content attached yet

	virtual UGCUpdateHandle_t StartItemUpdate( AppId_t nConsumerAppId, PublishedFileId_t nPublishedFileID ) = 0; // start an UGC item update. Set changed properties before commiting update with CommitItemUpdate()

	virtual bool SetItemTitle( UGCUpdateHandle_t handle, const char *pchTitle ) = 0; // change the title of an UGC item
	virtual bool SetItemDescription( UGCUpdateHandle_t handle, const char *pchDescription ) = 0; // change the description of an UGC item
	virtual bool SetItemUpdateLanguage( UGCUpdateHandle_t handle, const char *pchUpdateLanguage ) = 0;
	virtual bool SetItemMetadata( UGCUpdateHandle_t handle, const char *pchMetadata ) = 0;
	virtual bool SetItemVisibility( UGCUpdateHandle_t handle, ERemoteStoragePublishedFileVisibility eVisibility ) = 0; // change the visibility of an UGC item
	virtual bool SetItemTags( UGCUpdateHandle_t updateHandle, const SteamParamStringArray_t *pTags ) = 0; // change the tags of an UGC item
	virtual bool SetItemContent( UGCUpdateHandle_t handle, const char *pszContentFolder ) = 0; // update item content from this local folder
	virtual bool SetItemPreview( UGCUpdateHandle_t handle, const char *pszPreviewFile ) = 0; //  change preview image file for this item. pszPreviewFile points to local image file 
	virtual unknown_ret RemoveItemKeyValueTags( uint64, const char * ) = 0;
	virtual unknown_ret AddItemKeyValueTag( uint64, const char *, const char * ) = 0;

	virtual unknown_ret AddItemPreviewFile( uint64, char const*, EItemPreviewType ) = 0;
	virtual unknown_ret AddItemPreviewVideo( uint64, char const* ) = 0;
	virtual unknown_ret UpdateItemPreviewFile( uint64, uint32, char const* ) = 0;
	virtual unknown_ret UpdateItemPreviewVideo( uint64, uint32, char const* ) = 0;
	virtual unknown_ret RemoveItemPreview( uint64, uint32 ) = 0;

	
	virtual SteamAPICall_t SubmitItemUpdate( UGCUpdateHandle_t handle, const char *pchChangeNote ) = 0; // commit update process started with StartItemUpdate()
	virtual EItemUpdateStatus GetItemUpdateProgress( UGCUpdateHandle_t handle, uint64 *punBytesProcessed, uint64* punBytesTotal ) = 0;

	virtual unknown_ret SetUserItemVote( uint64, bool ) = 0;
	virtual unknown_ret GetUserItemVote( uint64 ) = 0;	
	
	virtual unknown_ret AddItemToFavorites( uint32, uint64 ) = 0;
	virtual unknown_ret RemoveItemFromFavorites( uint32, uint64 ) = 0;

	// Steam Workshop Consumer API
	virtual SteamAPICall_t SubscribeItem( PublishedFileId_t nPublishedFileID ) = 0; // subscript to this item, will be installed ASAP
	virtual SteamAPICall_t UnsubscribeItem( PublishedFileId_t nPublishedFileID ) = 0; // unsubscribe from this item, will be uninstalled after game quits
	virtual uint32 GetNumSubscribedItems() = 0; // number of subscribed items 
	virtual uint32 GetSubscribedItems( PublishedFileId_t* pvecPublishedFileID, uint32 cMaxEntries ) = 0; // all subscribed item PublishFileIDs

	// Get info about the item on disk.  If you are supporting items published through the legacy RemoteStorage APIs then *pbLegacyItem will be set to true
	// and pchFolder will contain the full path to the file rather than the containing folder.
	virtual unknown_ret GetItemState( PublishedFileId_t nPublishedFileID ) = 0;
	virtual unknown_ret GetItemInstallInfo( PublishedFileId_t nPublishedFileID, uint64 *punSizeOnDisk, char *pchFolder, uint32 cchFolderSize, uint32 * ) = 0;
	virtual unknown_ret GetItemDownloadInfo( PublishedFileId_t nPublishedFileID, uint64 *, uint64 * ) = 0;
	virtual unknown_ret DownloadItem( PublishedFileId_t nPublishedFileID, bool ) = 0;
	virtual unknown_ret BInitWorkshopForGameServer( uint32 a1, const char *a2 ) = 0;
	virtual unknown_ret SuspendDownloads( bool bSuspend ) = 0;

	virtual unknown_ret StartPlaytimeTracking( uint64 *, uint32 ) = 0;
	virtual unknown_ret StopPlaytimeTracking( uint64 *, uint32 ) = 0;
	virtual unknown_ret StopPlaytimeTrackingForAllItems() = 0;

	virtual unknown_ret AddDependency( uint64, uint64 ) = 0;
	virtual unknown_ret RemoveDependency( uint64, uint64 ) = 0;
	virtual unknown_ret AddAppDependency( uint64, uint32 ) = 0;
	virtual unknown_ret RemoveAppDependency( uint64, uint32 ) = 0;
	virtual unknown_ret GetAppDependencies( uint64 ) = 0;
	virtual unknown_ret DeleteItem( uint64 ) = 0;
};

#endif // ISTEAMUGC010_H
