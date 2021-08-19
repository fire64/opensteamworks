class ISteamUserStats011
{
public:
    virtual unknown_ret RequestCurrentStats() = 0;
    virtual unknown_ret GetStat(char const*, int*) = 0;
    virtual unknown_ret GetStat(char const*, float*) = 0;
    virtual unknown_ret SetStat(char const*, int) = 0;
    virtual unknown_ret SetStat(char const*, float) = 0;
    virtual unknown_ret UpdateAvgRateStat(char const*, float, double) = 0;
    virtual unknown_ret GetAchievement(char const*, bool*) = 0;
    virtual unknown_ret SetAchievement(char const*) = 0;
    virtual unknown_ret ClearAchievement(char const*) = 0;
    virtual unknown_ret GetAchievementAndUnlockTime(char const*, bool*, unsigned int*) = 0;
    virtual unknown_ret StoreStats() = 0;
    virtual unknown_ret GetAchievementIcon(char const*) = 0;
    virtual unknown_ret GetAchievementDisplayAttribute(char const*, char const*) = 0;
    virtual unknown_ret IndicateAchievementProgress(char const*, unsigned int, unsigned int) = 0;
    virtual unknown_ret GetNumAchievements() = 0;
    virtual unknown_ret GetAchievementName(unsigned int) = 0;
    virtual unknown_ret RequestUserStats(CSteamID) = 0;
    virtual unknown_ret GetUserStat(CSteamID, char const*, int*) = 0;
    virtual unknown_ret GetUserStat(CSteamID, char const*, float*) = 0;
    virtual unknown_ret GetUserAchievement(CSteamID, char const*, bool*) = 0;
    virtual unknown_ret GetUserAchievementAndUnlockTime(CSteamID, char const*, bool*, unsigned int*) = 0;
    virtual unknown_ret ResetAllStats(bool) = 0;
    virtual unknown_ret FindOrCreateLeaderboard(char const*, ELeaderboardSortMethod, ELeaderboardDisplayType) = 0;
    virtual unknown_ret FindLeaderboard(char const*) = 0;
    virtual unknown_ret GetLeaderboardName(unsigned long long) = 0;
    virtual unknown_ret GetLeaderboardEntryCount(unsigned long long) = 0;
    virtual unknown_ret GetLeaderboardSortMethod(unsigned long long) = 0;
    virtual unknown_ret GetLeaderboardDisplayType(unsigned long long) = 0;
    virtual unknown_ret DownloadLeaderboardEntries(unsigned long long, ELeaderboardDataRequest, int, int) = 0;
    virtual unknown_ret DownloadLeaderboardEntriesForUsers(unsigned long long, CSteamID*, int) = 0;
    virtual unknown_ret GetDownloadedLeaderboardEntry(unsigned long long, int, LeaderboardEntry_t*, int*, int) = 0;
    virtual unknown_ret UploadLeaderboardScore(unsigned long long, ELeaderboardUploadScoreMethod, int, int const*, int) = 0;
    virtual unknown_ret AttachLeaderboardUGC(unsigned long long, unsigned long long) = 0;
    virtual unknown_ret GetNumberOfCurrentPlayers() = 0;
    virtual unknown_ret RequestGlobalAchievementPercentages() = 0;
    virtual unknown_ret GetMostAchievedAchievementInfo(char*, unsigned int, float*, bool*) = 0;
    virtual unknown_ret GetNextMostAchievedAchievementInfo(int, char*, unsigned int, float*, bool*) = 0;
    virtual unknown_ret GetAchievementAchievedPercent(char const*, float*) = 0;
    virtual unknown_ret RequestGlobalStats(int) = 0;
    virtual unknown_ret GetGlobalStat(char const*, long long*) = 0;
    virtual unknown_ret GetGlobalStat(char const*, double*) = 0;
    virtual unknown_ret GetGlobalStatHistory(char const*, long long*, unsigned int) = 0;
    virtual unknown_ret GetGlobalStatHistory(char const*, double*, unsigned int) = 0;
};
