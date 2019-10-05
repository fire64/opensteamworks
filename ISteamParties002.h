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

#ifndef ISTEAMPARTIES002_H
#define ISTEAMPARTIES002_H
#ifdef _WIN32
#pragma once	
#endif

#include "SteamTypes.h"
#include "SteamPartiesCommon.h"

//-----------------------------------------------------------------------------
// Purpose: Functions for match making services for clients to get to favorites
//			and to operate on game lobbies.
//-----------------------------------------------------------------------------
abstract_class ISteamParties002
{
public:

	// =============================================================================================
	// Party Client APIs
	
	// Enumerate any active beacons for parties you may wish to join
	virtual uint32 GetNumActiveBeacons() = 0;
	virtual PartyBeaconID_t GetBeaconByIndex( uint32 unIndex ) = 0;
	virtual bool GetBeaconDetails( PartyBeaconID_t ulBeaconID, CSteamID *pSteamIDBeaconOwner, STEAM_OUT_STRUCT() SteamPartyBeaconLocation_t *pLocation, STEAM_OUT_STRING_COUNT(cchMetadata) char *pchMetadata, int cchMetadata ) = 0;

	// Join an open party. Steam will reserve one beacon slot for your SteamID,
	// and return the necessary JoinGame string for you to use to connect
	STEAM_CALL_RESULT( JoinPartyCallback_t )
	virtual SteamAPICall_t JoinParty( PartyBeaconID_t ulBeaconID ) = 0;

	// =============================================================================================
	// Party Host APIs

	// Get a list of possible beacon locations
	virtual bool GetNumAvailableBeaconLocations( uint32 *puNumLocations ) = 0;
	virtual bool GetAvailableBeaconLocations( SteamPartyBeaconLocation_t *pLocationList, uint32 uMaxNumLocations ) = 0;

	// Create a new party beacon and activate it in the selected location.
	// unOpenSlots is the maximum number of users that Steam will send to you.
	// When people begin responding to your beacon, Steam will send you
	// PartyReservationCallback_t callbacks to let you know who is on the way.
	STEAM_CALL_RESULT( CreateBeaconCallback_t )
	virtual SteamAPICall_t CreateBeacon( uint32 unOpenSlots, SteamPartyBeaconLocation_t *pBeaconLocation, const char *pchConnectString, const char *pchMetadata ) = 0;

	// Call this function when a user that had a reservation (see callback below) 
	// has successfully joined your party.
	// Steam will manage the remaining open slots automatically.
	virtual void OnReservationCompleted( PartyBeaconID_t ulBeacon, CSteamID steamIDUser ) = 0;

	// To cancel a reservation (due to timeout or user input), call this.
	// Steam will open a new reservation slot.
	// Note: The user may already be in-flight to your game, so it's possible they will still connect and try to join your party.
	virtual void CancelReservation( PartyBeaconID_t ulBeacon, CSteamID steamIDUser ) = 0;

	// Change the number of open beacon reservation slots.
	// Call this if, for example, someone without a reservation joins your party (eg a friend, or via your own matchmaking system).
	STEAM_CALL_RESULT( ChangeNumOpenSlotsCallback_t )
	virtual SteamAPICall_t ChangeNumOpenSlots( PartyBeaconID_t ulBeacon, uint32 unOpenSlots ) = 0;

	// Turn off the beacon. 
	virtual bool DestroyBeacon( PartyBeaconID_t ulBeacon ) = 0;

	// Utils
	virtual bool GetBeaconLocationData( SteamPartyBeaconLocation_t BeaconLocation, ESteamPartyBeaconLocationData eData, STEAM_OUT_STRING_COUNT(cchDataStringOut) char *pchDataStringOut, int cchDataStringOut ) = 0;

};


#endif // ISTEAMPARTIES002_H
