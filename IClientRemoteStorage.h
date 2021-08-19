class IClientRemoteStorage
{
public:
    virtual unknown_ret FileWrite(unsigned int, ERemoteStorageFileRoot, char const*, void const*, int) = 0;
    virtual unknown_ret GetFileSize(unsigned int, ERemoteStorageFileRoot, char const*) = 0;
    virtual unknown_ret FileWriteAsync(unsigned int, ERemoteStorageFileRoot, char const*, CUtlBuffer*) = 0;
    virtual unknown_ret FileReadAsync(unsigned int, ERemoteStorageFileRoot, char const*, unsigned int, unsigned int) = 0;
    virtual unknown_ret FileReadAsyncComplete(unsigned int, unsigned long long, void*, unsigned int) = 0;
    virtual unknown_ret FileRead(unsigned int, ERemoteStorageFileRoot, char const*, void*, int) = 0;
    virtual unknown_ret FileForget(unsigned int, ERemoteStorageFileRoot, char const*) = 0;
    virtual unknown_ret FileDelete(unsigned int, ERemoteStorageFileRoot, char const*) = 0;
    virtual unknown_ret FileShare(unsigned int, ERemoteStorageFileRoot, char const*) = 0;
    virtual unknown_ret FileExists(unsigned int, ERemoteStorageFileRoot, char const*) = 0;
    virtual unknown_ret FilePersisted(unsigned int, ERemoteStorageFileRoot, char const*) = 0;
    virtual unknown_ret GetFileTimestamp(unsigned int, ERemoteStorageFileRoot, char const*) = 0;
    virtual unknown_ret SetSyncPlatforms(unsigned int, ERemoteStorageFileRoot, char const*, ERemoteStoragePlatform) = 0;
    virtual unknown_ret GetSyncPlatforms(unsigned int, ERemoteStorageFileRoot, char const*) = 0;
    virtual unknown_ret FileWriteStreamOpen(unsigned int, ERemoteStorageFileRoot, char const*) = 0;
    virtual unknown_ret FileWriteStreamClose(unsigned long long) = 0;
    virtual unknown_ret FileWriteStreamCancel(unsigned long long) = 0;
    virtual unknown_ret FileWriteStreamWriteChunk(unsigned long long, void const*, int) = 0;
    virtual unknown_ret GetFileCount(unsigned int, bool) = 0;
    virtual unknown_ret GetFileNameAndSize(unsigned int, int, ERemoteStorageFileRoot*, int*, bool) = 0;
    virtual unknown_ret GetQuota(unsigned int, unsigned long long*, unsigned long long*) = 0;
    virtual unknown_ret IsCloudEnabledForAccount() = 0;
    virtual unknown_ret IsCloudEnabledForApp(unsigned int) = 0;
    virtual unknown_ret SetCloudEnabledForApp(unsigned int, bool) = 0;
    virtual unknown_ret UGCDownload(unsigned long long, bool, unsigned int) = 0;
    virtual unknown_ret UGCDownloadToLocation(unsigned long long, char const*, unsigned int) = 0;
    virtual unknown_ret GetUGCDownloadProgress(unsigned long long, int*, int*) = 0;
    virtual unknown_ret GetUGCDetails(unsigned long long, unsigned int*, char**, int*, CSteamID*) = 0;
    virtual unknown_ret UGCRead(unsigned long long, void*, int, unsigned int, EUGCReadAction) = 0;
    virtual unknown_ret GetCachedUGCCount() = 0;
    virtual unknown_ret GetCachedUGCHandle(int) = 0;
    virtual unknown_ret PublishFile(unsigned int, ERemoteStorageFileRoot, char const*, char const*, unsigned int, char const*, char const*, ERemoteStoragePublishedFileVisibility, SteamParamStringArray_t const*, EWorkshopFileType) = 0;
    virtual unknown_ret PublishVideo(unsigned int, EWorkshopVideoProvider, char const*, char const*, ERemoteStorageFileRoot, char const*, unsigned int, char const*, char const*, ERemoteStoragePublishedFileVisibility, SteamParamStringArray_t const*) = 0;
    virtual unknown_ret PublishVideoFromURL(unsigned int, ERemoteStorageFileRoot, char const*, char const*, unsigned int, char const*, char const*, ERemoteStoragePublishedFileVisibility, SteamParamStringArray_t const*) = 0;
    virtual unknown_ret CreatePublishedFileUpdateRequest(unsigned int, unsigned long long) = 0;
    virtual unknown_ret UpdatePublishedFileFile(unsigned long long, char const*) = 0;
    virtual unknown_ret UpdatePublishedFilePreviewFile(unsigned long long, char const*) = 0;
    virtual unknown_ret UpdatePublishedFileTitle(unsigned long long, char const*) = 0;
    virtual unknown_ret UpdatePublishedFileDescription(unsigned long long, char const*) = 0;
    virtual unknown_ret UpdatePublishedFileSetChangeDescription(unsigned long long, char const*) = 0;
    virtual unknown_ret UpdatePublishedFileVisibility(unsigned long long, ERemoteStoragePublishedFileVisibility) = 0;
    virtual unknown_ret UpdatePublishedFileTags(unsigned long long, SteamParamStringArray_t const*) = 0;
    virtual unknown_ret UpdatePublishedFileURL(unsigned long long, char const*) = 0;
    virtual unknown_ret CommitPublishedFileUpdate(unsigned int, ERemoteStorageFileRoot, unsigned long long) = 0;
    virtual unknown_ret GetPublishedFileDetails(unsigned long long, bool, unsigned int) = 0;
    virtual unknown_ret DeletePublishedFile(unsigned long long) = 0;
    virtual unknown_ret EnumerateUserPublishedFiles(unsigned int, unsigned int, ERemoteStoragePublishedFileSortOrder) = 0;
    virtual unknown_ret SubscribePublishedFile(unsigned int, unsigned long long) = 0;
    virtual unknown_ret EnumerateUserSubscribedFiles(unsigned int, unsigned int, unsigned char, EPublishedFileInfoMatchingFileType) = 0;
    virtual unknown_ret UnsubscribePublishedFile(unsigned int, unsigned long long) = 0;
    virtual unknown_ret SetUserPublishedFileAction(unsigned int, unsigned long long, EWorkshopFileAction) = 0;
    virtual unknown_ret EnumeratePublishedFilesByUserAction(unsigned int, EWorkshopFileAction, unsigned int) = 0;
    virtual unknown_ret EnumerateUserSubscribedFilesWithUpdates(unsigned int, unsigned int, unsigned int) = 0;
    virtual unknown_ret GetCREItemVoteSummary(unsigned long long) = 0;
    virtual unknown_ret UpdateUserPublishedItemVote(unsigned long long, bool) = 0;
    virtual unknown_ret GetUserPublishedItemVoteDetails(unsigned long long) = 0;
    virtual unknown_ret EnumerateUserSharedWorkshopFiles(unsigned int, CSteamID, unsigned int, SteamParamStringArray_t const*, SteamParamStringArray_t const*) = 0;
    virtual unknown_ret EnumeratePublishedWorkshopFiles(unsigned int, EWorkshopEnumerationType, EPublishedFileInfoMatchingFileType, unsigned int, unsigned int, unsigned int, SteamParamStringArray_t const*, SteamParamStringArray_t const*) = 0;
    virtual unknown_ret EGetFileSyncState(unsigned int, ERemoteStorageFileRoot, char const*) = 0;
    virtual unknown_ret BIsFileSyncing(unsigned int, ERemoteStorageFileRoot, char const*) = 0;
    virtual unknown_ret FilePersist(unsigned int, ERemoteStorageFileRoot, char const*) = 0;
    virtual unknown_ret FileFetch(unsigned int, ERemoteStorageFileRoot, char const*) = 0;
    virtual unknown_ret ResolvePath(unsigned int, ERemoteStorageFileRoot, char const*, char*, unsigned int) = 0;
    virtual unknown_ret FileTouch(unsigned int, ERemoteStorageFileRoot, char const*, bool) = 0;
    virtual unknown_ret SetCloudEnabledForAccount(bool) = 0;
    virtual unknown_ret LoadLocalFileInfoCache(unsigned int) = 0;
    virtual unknown_ret EvaluateRemoteStorageSyncState(unsigned int, bool) = 0;
    virtual unknown_ret GetRemoteStorageSyncState(unsigned int) = 0;
    virtual unknown_ret HaveLatestFilesLocally(unsigned int) = 0;
    virtual unknown_ret GetConflictingFileTimestamps(unsigned int, unsigned int*, unsigned int*) = 0;
    virtual unknown_ret ResolveSyncConflict(unsigned int, bool) = 0;
    virtual unknown_ret SynchronizeApp(unsigned int, ERemoteStorageSyncDirection, unsigned long long) = 0;
    virtual unknown_ret IsAppSyncInProgress(unsigned int) = 0;
    virtual unknown_ret RunAutoCloudOnAppLaunch(unsigned int) = 0;
    virtual unknown_ret RunAutoCloudOnAppExit(unsigned int) = 0;
    virtual unknown_ret ResetFileRequestState(unsigned int) = 0;
    virtual unknown_ret ClearPublishFileUpdateRequests(unsigned int) = 0;
    virtual unknown_ret GetSubscribedFileDownloadCount() = 0;
    virtual unknown_ret BGetSubscribedFileDownloadInfo(int, unsigned long long*, unsigned int*, unsigned int*, unsigned int*) = 0;
    virtual unknown_ret BGetSubscribedFileDownloadInfo(unsigned long long, unsigned int*, unsigned int*, unsigned int*) = 0;
    virtual unknown_ret PauseSubscribedFileDownloadsForApp(unsigned int) = 0;
    virtual unknown_ret ResumeSubscribedFileDownloadsForApp(unsigned int) = 0;
    virtual unknown_ret PauseAllSubscribedFileDownloads() = 0;
    virtual unknown_ret ResumeAllSubscribedFileDownloads() = 0;
    virtual unknown_ret CancelCurrentAndPendingOperations() = 0;
};
