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

#ifndef ISTEAMFRIENDS001_H
#define ISTEAMFRIENDS001_H
#ifdef _WIN32
#pragma once
#endif

#include "SteamTypes.h"
#include "FriendsCommon.h"

//-----------------------------------------------------------------------------
// Purpose: interface to friends
//-----------------------------------------------------------------------------
abstract_class ISteamFriends001
{
public:
	// returns the local players name - guaranteed to not be NULL.
	// this is the same name as on the users community profile page
	// this is stored in UTF-8 format
	// like all the other interface functions that return a char *, it's important that this pointer is not saved
	// off; it will eventually be free'd or re-allocated
	virtual const char *GetPersonaName() = 0;
	
	virtual void SetPersonaName( const char *pchPersonaName ) = 0;
	virtual EPersonaState GetPersonaState() = 0;
	virtual void SetPersonaState( EPersonaState ePersonaState ) = 0;
	virtual bool AddFriend( CSteamID steamIDFriend ) = 0;
	virtual bool RemoveFriend( CSteamID steamIDFriend ) = 0;
	virtual bool HasFriend( CSteamID steamIDFriend ) = 0;
	virtual EFriendRelationship GetFriendRelationship( CSteamID steamIDFriend ) = 0;
	virtual EPersonaState GetFriendPersonaState( CSteamID steamIDFriend ) = 0;
	virtual bool Deprecated_GetFriendGamePlayed( CSteamID steamIDFriend, int32 *pnGameID, uint32 *punGameIP, uint16 *pusGamePort ) = 0;
	virtual const char *GetFriendPersonaName( CSteamID steamIDFriend ) = 0;
	virtual int32 AddFriendByName( const char *pchEmailOrAccountName ) = 0;
	virtual int GetFriendCount() = 0;
	virtual CSteamID GetFriendByIndex( int iFriend ) = 0;
	virtual void SendMsgToFriend( CSteamID steamIDFriend, EChatEntryType eChatEntryType, const char *pchMsgBody ) = 0;
	virtual void SetFriendRegValue( CSteamID steamIDFriend, const char *pchKey, const char *pchValue ) = 0;
	virtual const char *GetFriendRegValue( CSteamID steamIDFriend, const char *pchKey ) = 0;
	virtual const char *GetFriendPersonaNameHistory( CSteamID steamIDFriend, int iPersonaName ) = 0;
	virtual int GetChatMessage( CSteamID steamIDFriend, int iChatID, void *pvData, int cubData, EChatEntryType *peChatEntryType ) = 0;

	virtual bool SendMsgToFriend( CSteamID steamIDFriend, EChatEntryType eChatEntryType, const void *pvMsgBody, int cubMsgBody ) = 0;
	virtual int GetChatIDOfChatHistoryStart( CSteamID steamIDFriend ) = 0;
	virtual void SetChatHistoryStart( CSteamID steamIDFriend, int iChatID ) = 0;
	virtual void ClearChatHistory( CSteamID steamIDFriend ) = 0;
	virtual bool InviteFriendByEmail( const char *pchEmailAccount ) = 0;
	virtual int GetBlockedFriendCount() = 0;
	virtual bool GetFriendGamePlayed( CSteamID steamIDFriend, uint64 *pulGameID, uint32 *punGameIP, uint16 *pusGamePort ) = 0;
	virtual bool GetFriendGamePlayed2( CSteamID steamIDFriend, uint64 *pulGameID, uint32 *punGameIP, uint16 *pusGamePort, uint16 *pusQueryPort ) = 0;
};


#endif // ISTEAMFRIENDS_H

