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

#ifndef STEAMGAMESEARCHCOMMON_H
#define STEAMGAMESEARCHCOMMON_H
#ifdef _WIN32
#pragma once
#endif

// game server flags
const uint32 k_unFavoriteFlagNone			= 0x00;
const uint32 k_unFavoriteFlagFavorite		= 0x01; // this game favorite entry is for the favorites list
const uint32 k_unFavoriteFlagHistory		= 0x02; // this game favorite entry is for the history list

enum EPlayerResult_t
{
	k_EPlayerResultFailedToConnect = 1, // failed to connect after confirming
	k_EPlayerResultAbandoned = 2,		// quit game without completing it
	k_EPlayerResultKicked = 3,			// kicked by other players/moderator/server rules
	k_EPlayerResultIncomplete = 4,		// player stayed to end but game did not conclude successfully ( nofault to player )
	k_EPlayerResultCompleted = 5,		// player completed game
};

enum EGameSearchErrorCode_t
{
	k_EGameSearchErrorCode_OK = 1,
	k_EGameSearchErrorCode_Failed_Search_Already_In_Progress = 2,
	k_EGameSearchErrorCode_Failed_No_Search_In_Progress = 3,
	k_EGameSearchErrorCode_Failed_Not_Lobby_Leader = 4, // if not the lobby leader can not call SearchForGameWithLobby
	k_EGameSearchErrorCode_Failed_No_Host_Available = 5, // no host is available that matches those search params
	k_EGameSearchErrorCode_Failed_Search_Params_Invalid = 6, // search params are invalid
	k_EGameSearchErrorCode_Failed_Offline = 7, // offline, could not communicate with server
	k_EGameSearchErrorCode_Failed_NotAuthorized = 8, // either the user or the application does not have priveledges to do this
	k_EGameSearchErrorCode_Failed_Unknown_Error = 9, // unknown error
};


// returns true of the flags indicate that a user has been removed from the chat
#define BChatMemberStateChangeRemoved( rgfChatMemberStateChangeFlags ) ( rgfChatMemberStateChangeFlags & ( k_EChatMemberStateChangeDisconnected | k_EChatMemberStateChangeLeft | k_EChatMemberStateChangeKicked | k_EChatMemberStateChangeBanned ) )


#define STEAMGAMESEARCH_INTERFACE_VERSION001 "SteamMatchGameSearch001"

#endif // STEAMGAMESEARCHCOMMON_H
