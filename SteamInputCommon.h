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

#ifndef STEAMINPUTCOMMON_H
#define STEAMINPUTCOMMON_H
#ifdef _WIN32
#pragma once
#endif

#define STEAM_INPUT_MAX_COUNT 16

#define STEAM_INPUT_MAX_ANALOG_ACTIONS 16

#define STEAM_INPUT_MAX_DIGITAL_ACTIONS 128

#define STEAM_INPUT_MAX_ORIGINS 8

#define STEAM_INPUT_MAX_ACTIVE_LAYERS 16

// When sending an option to a specific controller handle, you can send to all devices via this command
#define STEAM_INPUT_HANDLE_ALL_CONTROLLERS UINT64_MAX

#define STEAM_INPUT_MIN_ANALOG_ACTION_DATA -1.0f
#define STEAM_INPUT_MAX_ANALOG_ACTION_DATA 1.0f

enum EInputSource
{
	k_EInputSource_None,
	k_EInputSource_LeftTrackpad,
	k_EInputSource_RightTrackpad,
	k_EInputSource_Joystick,
	k_EInputSource_ABXY,
	k_EInputSource_Switch,
	k_EInputSource_LeftTrigger,
	k_EInputSource_RightTrigger,
	k_EInputSource_LeftBumper,
	k_EInputSource_RightBumper,
	k_EInputSource_Gyro,
	k_EInputSource_CenterTrackpad,		// PS4
	k_EInputSource_RightJoystick,		// Traditional Controllers
	k_EInputSource_DPad,				// Traditional Controllers
	k_EInputSource_Key,                 // Keyboards with scan codes - Unused
	k_EInputSource_Mouse,               // Traditional mouse - Unused
	k_EInputSource_LeftGyro,			// Secondary Gyro - Switch - Unused
	k_EInputSource_Count
};

enum EInputSourceMode
{
	k_EInputSourceMode_None,
	k_EInputSourceMode_Dpad,
	k_EInputSourceMode_Buttons,
	k_EInputSourceMode_FourButtons,
	k_EInputSourceMode_AbsoluteMouse,
	k_EInputSourceMode_RelativeMouse,
	k_EInputSourceMode_JoystickMove,
	k_EInputSourceMode_JoystickMouse,
	k_EInputSourceMode_JoystickCamera,
	k_EInputSourceMode_ScrollWheel,
	k_EInputSourceMode_Trigger,
	k_EInputSourceMode_TouchMenu,
	k_EInputSourceMode_MouseJoystick,
	k_EInputSourceMode_MouseRegion,
	k_EInputSourceMode_RadialMenu,
	k_EInputSourceMode_SingleButton,
	k_EInputSourceMode_Switches
};

// Note: Please do not use action origins as a way to identify controller types. There is no
// guarantee that they will be added in a contiguous manner - use GetInputTypeForHandle instead.
// Versions of Steam that add new controller types in the future will extend this enum so if you're
// using a lookup table please check the bounds of any origins returned by Steam.
enum EInputActionOrigin
{
	// Steam Controller
	k_EInputActionOrigin_None,
	k_EInputActionOrigin_SteamController_A,
	k_EInputActionOrigin_SteamController_B,
	k_EInputActionOrigin_SteamController_X,
	k_EInputActionOrigin_SteamController_Y,
	k_EInputActionOrigin_SteamController_LeftBumper,
	k_EInputActionOrigin_SteamController_RightBumper,
	k_EInputActionOrigin_SteamController_LeftGrip,
	k_EInputActionOrigin_SteamController_RightGrip,
	k_EInputActionOrigin_SteamController_Start,
	k_EInputActionOrigin_SteamController_Back,
	k_EInputActionOrigin_SteamController_LeftPad_Touch,
	k_EInputActionOrigin_SteamController_LeftPad_Swipe,
	k_EInputActionOrigin_SteamController_LeftPad_Click,
	k_EInputActionOrigin_SteamController_LeftPad_DPadNorth,
	k_EInputActionOrigin_SteamController_LeftPad_DPadSouth,
	k_EInputActionOrigin_SteamController_LeftPad_DPadWest,
	k_EInputActionOrigin_SteamController_LeftPad_DPadEast,
	k_EInputActionOrigin_SteamController_RightPad_Touch,
	k_EInputActionOrigin_SteamController_RightPad_Swipe,
	k_EInputActionOrigin_SteamController_RightPad_Click,
	k_EInputActionOrigin_SteamController_RightPad_DPadNorth,
	k_EInputActionOrigin_SteamController_RightPad_DPadSouth,
	k_EInputActionOrigin_SteamController_RightPad_DPadWest,
	k_EInputActionOrigin_SteamController_RightPad_DPadEast,
	k_EInputActionOrigin_SteamController_LeftTrigger_Pull,
	k_EInputActionOrigin_SteamController_LeftTrigger_Click,
	k_EInputActionOrigin_SteamController_RightTrigger_Pull,
	k_EInputActionOrigin_SteamController_RightTrigger_Click,
	k_EInputActionOrigin_SteamController_LeftStick_Move,
	k_EInputActionOrigin_SteamController_LeftStick_Click,
	k_EInputActionOrigin_SteamController_LeftStick_DPadNorth,
	k_EInputActionOrigin_SteamController_LeftStick_DPadSouth,
	k_EInputActionOrigin_SteamController_LeftStick_DPadWest,
	k_EInputActionOrigin_SteamController_LeftStick_DPadEast,
	k_EInputActionOrigin_SteamController_Gyro_Move,
	k_EInputActionOrigin_SteamController_Gyro_Pitch,
	k_EInputActionOrigin_SteamController_Gyro_Yaw,
	k_EInputActionOrigin_SteamController_Gyro_Roll,
	k_EInputActionOrigin_SteamController_Reserved0,
	k_EInputActionOrigin_SteamController_Reserved1,
	k_EInputActionOrigin_SteamController_Reserved2,
	k_EInputActionOrigin_SteamController_Reserved3,
	k_EInputActionOrigin_SteamController_Reserved4,
	k_EInputActionOrigin_SteamController_Reserved5,
	k_EInputActionOrigin_SteamController_Reserved6,
	k_EInputActionOrigin_SteamController_Reserved7,
	k_EInputActionOrigin_SteamController_Reserved8,
	k_EInputActionOrigin_SteamController_Reserved9,
	k_EInputActionOrigin_SteamController_Reserved10,
	
	// PS4 Dual Shock
	k_EInputActionOrigin_PS4_X,
	k_EInputActionOrigin_PS4_Circle,
	k_EInputActionOrigin_PS4_Triangle,
	k_EInputActionOrigin_PS4_Square,
	k_EInputActionOrigin_PS4_LeftBumper,
	k_EInputActionOrigin_PS4_RightBumper,
	k_EInputActionOrigin_PS4_Options,	//Start
	k_EInputActionOrigin_PS4_Share,		//Back
	k_EInputActionOrigin_PS4_LeftPad_Touch,
	k_EInputActionOrigin_PS4_LeftPad_Swipe,
	k_EInputActionOrigin_PS4_LeftPad_Click,
	k_EInputActionOrigin_PS4_LeftPad_DPadNorth,
	k_EInputActionOrigin_PS4_LeftPad_DPadSouth,
	k_EInputActionOrigin_PS4_LeftPad_DPadWest,
	k_EInputActionOrigin_PS4_LeftPad_DPadEast,
	k_EInputActionOrigin_PS4_RightPad_Touch,
	k_EInputActionOrigin_PS4_RightPad_Swipe,
	k_EInputActionOrigin_PS4_RightPad_Click,
	k_EInputActionOrigin_PS4_RightPad_DPadNorth,
	k_EInputActionOrigin_PS4_RightPad_DPadSouth,
	k_EInputActionOrigin_PS4_RightPad_DPadWest,
	k_EInputActionOrigin_PS4_RightPad_DPadEast,
	k_EInputActionOrigin_PS4_CenterPad_Touch,
	k_EInputActionOrigin_PS4_CenterPad_Swipe,
	k_EInputActionOrigin_PS4_CenterPad_Click,
	k_EInputActionOrigin_PS4_CenterPad_DPadNorth,
	k_EInputActionOrigin_PS4_CenterPad_DPadSouth,
	k_EInputActionOrigin_PS4_CenterPad_DPadWest,
	k_EInputActionOrigin_PS4_CenterPad_DPadEast,
	k_EInputActionOrigin_PS4_LeftTrigger_Pull,
	k_EInputActionOrigin_PS4_LeftTrigger_Click,
	k_EInputActionOrigin_PS4_RightTrigger_Pull,
	k_EInputActionOrigin_PS4_RightTrigger_Click,
	k_EInputActionOrigin_PS4_LeftStick_Move,
	k_EInputActionOrigin_PS4_LeftStick_Click,
	k_EInputActionOrigin_PS4_LeftStick_DPadNorth,
	k_EInputActionOrigin_PS4_LeftStick_DPadSouth,
	k_EInputActionOrigin_PS4_LeftStick_DPadWest,
	k_EInputActionOrigin_PS4_LeftStick_DPadEast,
	k_EInputActionOrigin_PS4_RightStick_Move,
	k_EInputActionOrigin_PS4_RightStick_Click,
	k_EInputActionOrigin_PS4_RightStick_DPadNorth,
	k_EInputActionOrigin_PS4_RightStick_DPadSouth,
	k_EInputActionOrigin_PS4_RightStick_DPadWest,
	k_EInputActionOrigin_PS4_RightStick_DPadEast,
	k_EInputActionOrigin_PS4_DPad_North,
	k_EInputActionOrigin_PS4_DPad_South,
	k_EInputActionOrigin_PS4_DPad_West,
	k_EInputActionOrigin_PS4_DPad_East,
	k_EInputActionOrigin_PS4_Gyro_Move,
	k_EInputActionOrigin_PS4_Gyro_Pitch,
	k_EInputActionOrigin_PS4_Gyro_Yaw,
	k_EInputActionOrigin_PS4_Gyro_Roll,
	k_EInputActionOrigin_PS4_DPad_Move,
	k_EInputActionOrigin_PS4_Reserved1,
	k_EInputActionOrigin_PS4_Reserved2,
	k_EInputActionOrigin_PS4_Reserved3,
	k_EInputActionOrigin_PS4_Reserved4,
	k_EInputActionOrigin_PS4_Reserved5,
	k_EInputActionOrigin_PS4_Reserved6,
	k_EInputActionOrigin_PS4_Reserved7,
	k_EInputActionOrigin_PS4_Reserved8,
	k_EInputActionOrigin_PS4_Reserved9,
	k_EInputActionOrigin_PS4_Reserved10,

	// XBox One
	k_EInputActionOrigin_XBoxOne_A,
	k_EInputActionOrigin_XBoxOne_B,
	k_EInputActionOrigin_XBoxOne_X,
	k_EInputActionOrigin_XBoxOne_Y,
	k_EInputActionOrigin_XBoxOne_LeftBumper,
	k_EInputActionOrigin_XBoxOne_RightBumper,
	k_EInputActionOrigin_XBoxOne_Menu,  //Start
	k_EInputActionOrigin_XBoxOne_View,  //Back
	k_EInputActionOrigin_XBoxOne_LeftTrigger_Pull,
	k_EInputActionOrigin_XBoxOne_LeftTrigger_Click,
	k_EInputActionOrigin_XBoxOne_RightTrigger_Pull,
	k_EInputActionOrigin_XBoxOne_RightTrigger_Click,
	k_EInputActionOrigin_XBoxOne_LeftStick_Move,
	k_EInputActionOrigin_XBoxOne_LeftStick_Click,
	k_EInputActionOrigin_XBoxOne_LeftStick_DPadNorth,
	k_EInputActionOrigin_XBoxOne_LeftStick_DPadSouth,
	k_EInputActionOrigin_XBoxOne_LeftStick_DPadWest,
	k_EInputActionOrigin_XBoxOne_LeftStick_DPadEast,
	k_EInputActionOrigin_XBoxOne_RightStick_Move,
	k_EInputActionOrigin_XBoxOne_RightStick_Click,
	k_EInputActionOrigin_XBoxOne_RightStick_DPadNorth,
	k_EInputActionOrigin_XBoxOne_RightStick_DPadSouth,
	k_EInputActionOrigin_XBoxOne_RightStick_DPadWest,
	k_EInputActionOrigin_XBoxOne_RightStick_DPadEast,
	k_EInputActionOrigin_XBoxOne_DPad_North,
	k_EInputActionOrigin_XBoxOne_DPad_South,
	k_EInputActionOrigin_XBoxOne_DPad_West,
	k_EInputActionOrigin_XBoxOne_DPad_East,
	k_EInputActionOrigin_XBoxOne_DPad_Move,
	k_EInputActionOrigin_XBoxOne_Reserved1,
	k_EInputActionOrigin_XBoxOne_Reserved2,
	k_EInputActionOrigin_XBoxOne_Reserved3,
	k_EInputActionOrigin_XBoxOne_Reserved4,
	k_EInputActionOrigin_XBoxOne_Reserved5,
	k_EInputActionOrigin_XBoxOne_Reserved6,
	k_EInputActionOrigin_XBoxOne_Reserved7,
	k_EInputActionOrigin_XBoxOne_Reserved8,
	k_EInputActionOrigin_XBoxOne_Reserved9,
	k_EInputActionOrigin_XBoxOne_Reserved10,

	// XBox 360
	k_EInputActionOrigin_XBox360_A,
	k_EInputActionOrigin_XBox360_B,
	k_EInputActionOrigin_XBox360_X,
	k_EInputActionOrigin_XBox360_Y,
	k_EInputActionOrigin_XBox360_LeftBumper,
	k_EInputActionOrigin_XBox360_RightBumper,
	k_EInputActionOrigin_XBox360_Start,		//Start
	k_EInputActionOrigin_XBox360_Back,		//Back
	k_EInputActionOrigin_XBox360_LeftTrigger_Pull,
	k_EInputActionOrigin_XBox360_LeftTrigger_Click,
	k_EInputActionOrigin_XBox360_RightTrigger_Pull,
	k_EInputActionOrigin_XBox360_RightTrigger_Click,
	k_EInputActionOrigin_XBox360_LeftStick_Move,
	k_EInputActionOrigin_XBox360_LeftStick_Click,
	k_EInputActionOrigin_XBox360_LeftStick_DPadNorth,
	k_EInputActionOrigin_XBox360_LeftStick_DPadSouth,
	k_EInputActionOrigin_XBox360_LeftStick_DPadWest,
	k_EInputActionOrigin_XBox360_LeftStick_DPadEast,
	k_EInputActionOrigin_XBox360_RightStick_Move,
	k_EInputActionOrigin_XBox360_RightStick_Click,
	k_EInputActionOrigin_XBox360_RightStick_DPadNorth,
	k_EInputActionOrigin_XBox360_RightStick_DPadSouth,
	k_EInputActionOrigin_XBox360_RightStick_DPadWest,
	k_EInputActionOrigin_XBox360_RightStick_DPadEast,
	k_EInputActionOrigin_XBox360_DPad_North,
	k_EInputActionOrigin_XBox360_DPad_South,
	k_EInputActionOrigin_XBox360_DPad_West,
	k_EInputActionOrigin_XBox360_DPad_East,	
	k_EInputActionOrigin_XBox360_DPad_Move,
	k_EInputActionOrigin_XBox360_Reserved1,
	k_EInputActionOrigin_XBox360_Reserved2,
	k_EInputActionOrigin_XBox360_Reserved3,
	k_EInputActionOrigin_XBox360_Reserved4,
	k_EInputActionOrigin_XBox360_Reserved5,
	k_EInputActionOrigin_XBox360_Reserved6,
	k_EInputActionOrigin_XBox360_Reserved7,
	k_EInputActionOrigin_XBox360_Reserved8,
	k_EInputActionOrigin_XBox360_Reserved9,
	k_EInputActionOrigin_XBox360_Reserved10,


	// Switch - Pro or Joycons used as a single input device.
	// This does not apply to a single joycon
	k_EInputActionOrigin_Switch_A,
	k_EInputActionOrigin_Switch_B,
	k_EInputActionOrigin_Switch_X,
	k_EInputActionOrigin_Switch_Y,
	k_EInputActionOrigin_Switch_LeftBumper,
	k_EInputActionOrigin_Switch_RightBumper,
	k_EInputActionOrigin_Switch_Plus,	//Start
	k_EInputActionOrigin_Switch_Minus,	//Back
	k_EInputActionOrigin_Switch_Capture,
	k_EInputActionOrigin_Switch_LeftTrigger_Pull,
	k_EInputActionOrigin_Switch_LeftTrigger_Click,
	k_EInputActionOrigin_Switch_RightTrigger_Pull,
	k_EInputActionOrigin_Switch_RightTrigger_Click,
	k_EInputActionOrigin_Switch_LeftStick_Move,
	k_EInputActionOrigin_Switch_LeftStick_Click,
	k_EInputActionOrigin_Switch_LeftStick_DPadNorth,
	k_EInputActionOrigin_Switch_LeftStick_DPadSouth,
	k_EInputActionOrigin_Switch_LeftStick_DPadWest,
	k_EInputActionOrigin_Switch_LeftStick_DPadEast,
	k_EInputActionOrigin_Switch_RightStick_Move,
	k_EInputActionOrigin_Switch_RightStick_Click,
	k_EInputActionOrigin_Switch_RightStick_DPadNorth,
	k_EInputActionOrigin_Switch_RightStick_DPadSouth,
	k_EInputActionOrigin_Switch_RightStick_DPadWest,
	k_EInputActionOrigin_Switch_RightStick_DPadEast,
	k_EInputActionOrigin_Switch_DPad_North,
	k_EInputActionOrigin_Switch_DPad_South,
	k_EInputActionOrigin_Switch_DPad_West,
	k_EInputActionOrigin_Switch_DPad_East,
	k_EInputActionOrigin_Switch_ProGyro_Move,  // Primary Gyro in Pro Controller, or Right JoyCon
	k_EInputActionOrigin_Switch_ProGyro_Pitch,  // Primary Gyro in Pro Controller, or Right JoyCon
	k_EInputActionOrigin_Switch_ProGyro_Yaw,  // Primary Gyro in Pro Controller, or Right JoyCon
	k_EInputActionOrigin_Switch_ProGyro_Roll,  // Primary Gyro in Pro Controller, or Right JoyCon
	k_EInputActionOrigin_Switch_DPad_Move,
	k_EInputActionOrigin_Switch_Reserved1,
	k_EInputActionOrigin_Switch_Reserved2,
	k_EInputActionOrigin_Switch_Reserved3,
	k_EInputActionOrigin_Switch_Reserved4,
	k_EInputActionOrigin_Switch_Reserved5,
	k_EInputActionOrigin_Switch_Reserved6,
	k_EInputActionOrigin_Switch_Reserved7,
	k_EInputActionOrigin_Switch_Reserved8,
	k_EInputActionOrigin_Switch_Reserved9,
	k_EInputActionOrigin_Switch_Reserved10,

	// Switch JoyCon Specific
	k_EInputActionOrigin_Switch_RightGyro_Move,  // Right JoyCon Gyro generally should correspond to Pro's single gyro
	k_EInputActionOrigin_Switch_RightGyro_Pitch,  // Right JoyCon Gyro generally should correspond to Pro's single gyro
	k_EInputActionOrigin_Switch_RightGyro_Yaw,  // Right JoyCon Gyro generally should correspond to Pro's single gyro
	k_EInputActionOrigin_Switch_RightGyro_Roll,  // Right JoyCon Gyro generally should correspond to Pro's single gyro
	k_EInputActionOrigin_Switch_LeftGyro_Move,
	k_EInputActionOrigin_Switch_LeftGyro_Pitch,
	k_EInputActionOrigin_Switch_LeftGyro_Yaw,
	k_EInputActionOrigin_Switch_LeftGyro_Roll,
	k_EInputActionOrigin_Switch_LeftGrip_Lower, // Left JoyCon SR Button
	k_EInputActionOrigin_Switch_LeftGrip_Upper, // Left JoyCon SL Button
	k_EInputActionOrigin_Switch_RightGrip_Lower,  // Right JoyCon SL Button
	k_EInputActionOrigin_Switch_RightGrip_Upper,  // Right JoyCon SR Button
	k_EInputActionOrigin_Switch_Reserved11,
	k_EInputActionOrigin_Switch_Reserved12,
	k_EInputActionOrigin_Switch_Reserved13,
	k_EInputActionOrigin_Switch_Reserved14,
	k_EInputActionOrigin_Switch_Reserved15,
	k_EInputActionOrigin_Switch_Reserved16,
	k_EInputActionOrigin_Switch_Reserved17,
	k_EInputActionOrigin_Switch_Reserved18,
	k_EInputActionOrigin_Switch_Reserved19,
	k_EInputActionOrigin_Switch_Reserved20,

	k_EInputActionOrigin_Count, // If Steam has added support for new controllers origins will go here.
	k_EInputActionOrigin_MaximumPossibleValue = 32767, // Origins are currently a maximum of 16 bits.
};

// These values are passed into SetLEDColor
enum ESteamInputLEDFlag
{
	k_ESteamInputLEDFlag_SetColor,
	// Restore the LED color to the user's preference setting as set in the controller personalization menu.
	// This also happens automatically on exit of your game.  
	k_ESteamInputLEDFlag_RestoreUserDefault 
};

// InputHandle_t is used to refer to a specific controller.
// This handle will consistently identify a controller, even if it is disconnected and re-connected
typedef uint64 InputHandle_t;


// These handles are used to refer to a specific in-game action or action set
// All action handles should be queried during initialization for performance reasons
typedef uint64 InputActionSetHandle_t;
typedef uint64 InputDigitalActionHandle_t;
typedef uint64 InputAnalogActionHandle_t;

#pragma pack( push, 1 )

struct InputAnalogActionData_t
{
	// Type of data coming from this action, this will match what got specified in the action set
	EInputSourceMode eMode;
	
	// The current state of this action; will be delta updates for mouse actions
	float x, y;
	
	// Whether or not this action is currently available to be bound in the active action set
	bool bActive;
};

struct InputDigitalActionData_t
{
	// The current state of this action; will be true if currently pressed
	bool bState;
	
	// Whether or not this action is currently available to be bound in the active action set
	bool bActive;
};

struct InputMotionData_t
{
	// Sensor-fused absolute rotation; will drift in heading
	float rotQuatX;
	float rotQuatY;
	float rotQuatZ;
	float rotQuatW;
	
	// Positional acceleration
	float posAccelX;
	float posAccelY;
	float posAccelZ;

	// Angular velocity
	float rotVelX;
	float rotVelY;
	float rotVelZ;
};

#pragma pack( pop )

#define STEAMINPUT_INTERFACE_VERSION_001 "SteamInput001"

#endif // STEAMINPUTCOMMON_H
