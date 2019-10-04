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

#ifndef ISTEAMGAMESEARCH001_H
#define ISTEAMGAMESEARCH001_H
#ifdef _WIN32
#pragma once	
#endif

#include "SteamTypes.h"
#include "SteamGameSearchCommon.h"

//-----------------------------------------------------------------------------
// Purpose: Functions for match making services for clients to get to favorites
//			and to operate on game lobbies.
//-----------------------------------------------------------------------------
abstract_class ISteamGameSearch001
{
public:
	// =============================================================================================
	// Game Player APIs

	// a keyname and a list of comma separated values: one of which is must be found in order for the match to qualify
	// fails if a search is currently in progress
	virtual EGameSearchErrorCode_t AddGameSearchParams( const char *pchKeyToFind, const char *pchValuesToFind ) = 0;

	// all players in lobby enter the queue and await a SearchForGameNotificationCallback_t callback. fails if another search is currently in progress
	// if not the owner of the lobby or search already in progress this call fails
	// periodic callbacks will be sent as queue time estimates change
	virtual EGameSearchErrorCode_t SearchForGameWithLobby( CSteamID steamIDLobby, int nPlayerMin, int nPlayerMax ) = 0;

	// user enter the queue and await a SearchForGameNotificationCallback_t callback. fails if another search is currently in progress
	// periodic callbacks will be sent as queue time estimates change
	virtual EGameSearchErrorCode_t SearchForGameSolo( int nPlayerMin, int nPlayerMax ) = 0;

	// after receiving SearchForGameResultCallback_t, accept or decline the game
	// multiple SearchForGameResultCallback_t will follow as players accept game until the host starts or cancels the game
	virtual EGameSearchErrorCode_t AcceptGame() = 0;
	virtual EGameSearchErrorCode_t DeclineGame() = 0;

	// after receiving GameStartedByHostCallback_t get connection details to server
	virtual EGameSearchErrorCode_t RetrieveConnectionDetails( CSteamID steamIDHost, char *pchConnectionDetails, int cubConnectionDetails ) = 0;

	// leaves queue if still waiting
	virtual EGameSearchErrorCode_t EndGameSearch() = 0;

	// =============================================================================================
	// Game Host APIs

	// a keyname and a list of comma separated values: all the values you allow
	virtual EGameSearchErrorCode_t SetGameHostParams( const char *pchKey, const char *pchValue ) = 0;

	// set connection details for players once game is found so they can connect to this server
	virtual EGameSearchErrorCode_t SetConnectionDetails( const char *pchConnectionDetails, int cubConnectionDetails ) = 0;

	// mark server as available for more players with nPlayerMin,nPlayerMax desired
	// accept no lobbies with playercount greater than nMaxTeamSize
	// the set of lobbies returned must be partitionable into teams of no more than nMaxTeamSize
	// RequestPlayersForGameNotificationCallback_t callback will be sent when the search has started
	// multple RequestPlayersForGameResultCallback_t callbacks will follow when players are found
	virtual EGameSearchErrorCode_t RequestPlayersForGame( int nPlayerMin, int nPlayerMax, int nMaxTeamSize ) = 0;

	// accept the player list and release connection details to players
	// players will only be given connection details and host steamid when this is called
	// ( allows host to accept after all players confirm, some confirm, or none confirm. decision is entirely up to the host )
	virtual EGameSearchErrorCode_t HostConfirmGameStart( uint64 ullUniqueGameID ) = 0;

	// cancel request and leave the pool of game hosts looking for players
	// if a set of players has already been sent to host, all players will receive SearchForGameHostFailedToConfirm_t
	virtual EGameSearchErrorCode_t CancelRequestPlayersForGame() = 0;

	// submit a result for one player. does not end the game. ullUniqueGameID continues to describe this game
	virtual EGameSearchErrorCode_t SubmitPlayerResult( uint64 ullUniqueGameID, CSteamID steamIDPlayer, EPlayerResult_t EPlayerResult ) = 0;

	// ends the game. no further SubmitPlayerResults for ullUniqueGameID will be accepted
	// any future requests will provide a new ullUniqueGameID
	virtual EGameSearchErrorCode_t EndGame( uint64 ullUniqueGameID ) = 0;

};


#endif // ISTEAMGAMESEARCH001_H
