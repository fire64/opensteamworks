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

#ifndef ISTEAMCONTROLLER002_H
#define ISTEAMCONTROLLER002_H
#ifdef _WIN32
#pragma once
#endif

#include "SteamTypes.h"
#include "ControllerCommon.h"

abstract_class ISteamController002
{
public:

	// Init and Shutdown must be called when starting/ending use of this interface
	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;
	
	// Synchronize API state with the latest Steam Controller inputs available. This
	// is performed automatically by SteamAPI_RunCallbacks, but for the absolute lowest
	// possible latency, you call this directly before reading controller state.
	virtual void RunFrame() = 0;

	// Enumerate currently connected controllers
	// handlesOut should point to a STEAM_CONTROLLER_MAX_COUNT sized array of ControllerHandle_t handles
	// Returns the number of handles written to handlesOut
	virtual int GetConnectedControllers( ControllerHandle_t *handlesOut ) = 0;

	// Trigger a haptic pulse on the controller
	virtual void TriggerHapticPulse( uint32 unControllerIndex, ESteamControllerPad eTargetPad, unsigned short usDurationMicroSec ) = 0;

	virtual unknown_ret ActivateMode( ControllerHandle_t handle, int32 unControllerIndex ) = 0;
	virtual unknown_ret GetJoystickForHandle( ControllerHandle_t handle ) = 0;
	virtual unknown_ret GetHandleForJoystick( int32 unControllerIndex ) = 0;
	virtual unknown_ret GetModeAnalogOutputData( ControllerHandle_t handle, int32 unControllerIndex ) = 0;

};

#endif //ISTEAMCONTROLLER002_H
