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

#ifndef CONTROLLERCOMMON_H
#define CONTROLLERCOMMON_H
#ifdef _WIN32
#pragma once
#endif

#define STEAMCONTROLLER_INTERFACE_VERSION_001 "STEAMCONTROLLER_INTERFACE_VERSION"
#define STEAMCONTROLLER_INTERFACE_VERSION_002 "STEAMCONTROLLER_INTERFACE_VERSION_002"
#define STEAMCONTROLLER_INTERFACE_VERSION_003 "SteamController003"
#define STEAMCONTROLLER_INTERFACE_VERSION_004 "SteamController004"
#define STEAMCONTROLLER_INTERFACE_VERSION_005 "SteamController005"
#define STEAMCONTROLLER_INTERFACE_VERSION_006 "SteamController006"
#define STEAMCONTROLLER_INTERFACE_VERSION_007 "SteamController007"

#define STEAM_RIGHT_TRIGGER_MASK            0x0000000000000001l
#define STEAM_LEFT_TRIGGER_MASK             0x0000000000000002l
#define STEAM_RIGHT_BUMPER_MASK             0x0000000000000004l
#define STEAM_LEFT_BUMPER_MASK              0x0000000000000008l
#define STEAM_BUTTON_0_MASK                 0x0000000000000010l
#define STEAM_BUTTON_1_MASK                 0x0000000000000020l
#define STEAM_BUTTON_2_MASK                 0x0000000000000040l
#define STEAM_BUTTON_3_MASK                 0x0000000000000080l
#define STEAM_TOUCH_0_MASK                  0x0000000000000100l
#define STEAM_TOUCH_1_MASK                  0x0000000000000200l
#define STEAM_TOUCH_2_MASK                  0x0000000000000400l
#define STEAM_TOUCH_3_MASK                  0x0000000000000800l
#define STEAM_BUTTON_MENU_MASK              0x0000000000001000l
#define STEAM_BUTTON_STEAM_MASK             0x0000000000002000l
#define STEAM_BUTTON_ESCAPE_MASK            0x0000000000004000l
#define STEAM_BUTTON_BACK_LEFT_MASK         0x0000000000008000l
#define STEAM_BUTTON_BACK_RIGHT_MASK        0x0000000000010000l
#define STEAM_BUTTON_LEFTPAD_CLICKED_MASK   0x0000000000020000l
#define STEAM_BUTTON_RIGHTPAD_CLICKED_MASK  0x0000000000040000l
#define STEAM_LEFTPAD_FINGERDOWN_MASK       0x0000000000080000l
#define STEAM_RIGHTPAD_FINGERDOWN_MASK      0x0000000000100000l

#define STEAM_CONTROLLER_MAX_COUNT 16

#define STEAM_CONTROLLER_MAX_ANALOG_ACTIONS 16

#define STEAM_CONTROLLER_MAX_DIGITAL_ACTIONS 128

#define STEAM_CONTROLLER_MAX_ORIGINS 8

#define STEAM_CONTROLLER_MAX_ACTIVE_LAYERS 16

// When sending an option to a specific controller handle, you can send to all controllers via this command
#define STEAM_CONTROLLER_HANDLE_ALL_CONTROLLERS UINT64_MAX

#define STEAM_CONTROLLER_MIN_ANALOG_ACTION_DATA -1.0f
#define STEAM_CONTROLLER_MAX_ANALOG_ACTION_DATA 1.0f

enum ESteamControllerPad
{
	k_ESteamControllerPad_Left,
	k_ESteamControllerPad_Right
};

enum EControllerSource
{
	k_EControllerSource_None,
	k_EControllerSource_LeftTrackpad,
	k_EControllerSource_RightTrackpad,
	k_EControllerSource_Joystick,
	k_EControllerSource_ABXY,
	k_EControllerSource_Switch,
	k_EControllerSource_LeftTrigger,
	k_EControllerSource_RightTrigger,
	k_EControllerSource_LeftBumper,
	k_EControllerSource_RightBumper,
	k_EControllerSource_Gyro,
	k_EControllerSource_CenterTrackpad,		// PS4
	k_EControllerSource_RightJoystick,		// Traditional Controllers
	k_EControllerSource_DPad,				// Traditional Controllers
	k_EControllerSource_Key,                // Keyboards with scan codes - Unused
	k_EControllerSource_Mouse,              // Traditional mouse - Unused
	k_EControllerSource_LeftGyro,			// Secondary Gyro - Switch - Unused
	k_EControllerSource_Count
};

enum EControllerSourceMode
{
	k_EControllerSourceMode_None,
	k_EControllerSourceMode_Dpad,
	k_EControllerSourceMode_Buttons,
	k_EControllerSourceMode_FourButtons,
	k_EControllerSourceMode_AbsoluteMouse,
	k_EControllerSourceMode_RelativeMouse,
	k_EControllerSourceMode_JoystickMove,
	k_EControllerSourceMode_JoystickMouse,
	k_EControllerSourceMode_JoystickCamera,
	k_EControllerSourceMode_ScrollWheel,
	k_EControllerSourceMode_Trigger,
	k_EControllerSourceMode_TouchMenu,
	k_EControllerSourceMode_MouseJoystick,
	k_EControllerSourceMode_MouseRegion,
	k_EControllerSourceMode_RadialMenu,
	k_EControllerSourceMode_SingleButton,
	k_EControllerSourceMode_Switches
};

// Note: Please do not use action origins as a way to identify controller types. There is no
// guarantee that they will be added in a contiguous manner - use GetInputTypeForHandle instead
// Versions of Steam that add new controller types in the future will extend this enum if you're
// using a lookup table please check the bounds of any origins returned by Steam.
enum EControllerActionOrigin
{
	// Steam Controller
	k_EControllerActionOrigin_None,
	k_EControllerActionOrigin_A,
	k_EControllerActionOrigin_B,
	k_EControllerActionOrigin_X,
	k_EControllerActionOrigin_Y,
	k_EControllerActionOrigin_LeftBumper,
	k_EControllerActionOrigin_RightBumper,
	k_EControllerActionOrigin_LeftGrip,
	k_EControllerActionOrigin_RightGrip,
	k_EControllerActionOrigin_Start,
	k_EControllerActionOrigin_Back,
	k_EControllerActionOrigin_LeftPad_Touch,
	k_EControllerActionOrigin_LeftPad_Swipe,
	k_EControllerActionOrigin_LeftPad_Click,
	k_EControllerActionOrigin_LeftPad_DPadNorth,
	k_EControllerActionOrigin_LeftPad_DPadSouth,
	k_EControllerActionOrigin_LeftPad_DPadWest,
	k_EControllerActionOrigin_LeftPad_DPadEast,
	k_EControllerActionOrigin_RightPad_Touch,
	k_EControllerActionOrigin_RightPad_Swipe,
	k_EControllerActionOrigin_RightPad_Click,
	k_EControllerActionOrigin_RightPad_DPadNorth,
	k_EControllerActionOrigin_RightPad_DPadSouth,
	k_EControllerActionOrigin_RightPad_DPadWest,
	k_EControllerActionOrigin_RightPad_DPadEast,
	k_EControllerActionOrigin_LeftTrigger_Pull,
	k_EControllerActionOrigin_LeftTrigger_Click,
	k_EControllerActionOrigin_RightTrigger_Pull,
	k_EControllerActionOrigin_RightTrigger_Click,
	k_EControllerActionOrigin_LeftStick_Move,
	k_EControllerActionOrigin_LeftStick_Click,
	k_EControllerActionOrigin_LeftStick_DPadNorth,
	k_EControllerActionOrigin_LeftStick_DPadSouth,
	k_EControllerActionOrigin_LeftStick_DPadWest,
	k_EControllerActionOrigin_LeftStick_DPadEast,
	k_EControllerActionOrigin_Gyro_Move,
	k_EControllerActionOrigin_Gyro_Pitch,
	k_EControllerActionOrigin_Gyro_Yaw,
	k_EControllerActionOrigin_Gyro_Roll,
	
	// PS4 Dual Shock
	k_EControllerActionOrigin_PS4_X,
	k_EControllerActionOrigin_PS4_Circle,
	k_EControllerActionOrigin_PS4_Triangle,
	k_EControllerActionOrigin_PS4_Square,
	k_EControllerActionOrigin_PS4_LeftBumper,
	k_EControllerActionOrigin_PS4_RightBumper,
	k_EControllerActionOrigin_PS4_Options,  //Start
	k_EControllerActionOrigin_PS4_Share,	//Back
	k_EControllerActionOrigin_PS4_LeftPad_Touch,
	k_EControllerActionOrigin_PS4_LeftPad_Swipe,
	k_EControllerActionOrigin_PS4_LeftPad_Click,
	k_EControllerActionOrigin_PS4_LeftPad_DPadNorth,
	k_EControllerActionOrigin_PS4_LeftPad_DPadSouth,
	k_EControllerActionOrigin_PS4_LeftPad_DPadWest,
	k_EControllerActionOrigin_PS4_LeftPad_DPadEast,
	k_EControllerActionOrigin_PS4_RightPad_Touch,
	k_EControllerActionOrigin_PS4_RightPad_Swipe,
	k_EControllerActionOrigin_PS4_RightPad_Click,
	k_EControllerActionOrigin_PS4_RightPad_DPadNorth,
	k_EControllerActionOrigin_PS4_RightPad_DPadSouth,
	k_EControllerActionOrigin_PS4_RightPad_DPadWest,
	k_EControllerActionOrigin_PS4_RightPad_DPadEast,
	k_EControllerActionOrigin_PS4_CenterPad_Touch,
	k_EControllerActionOrigin_PS4_CenterPad_Swipe,
	k_EControllerActionOrigin_PS4_CenterPad_Click,
	k_EControllerActionOrigin_PS4_CenterPad_DPadNorth,
	k_EControllerActionOrigin_PS4_CenterPad_DPadSouth,
	k_EControllerActionOrigin_PS4_CenterPad_DPadWest,
	k_EControllerActionOrigin_PS4_CenterPad_DPadEast,
	k_EControllerActionOrigin_PS4_LeftTrigger_Pull,
	k_EControllerActionOrigin_PS4_LeftTrigger_Click,
	k_EControllerActionOrigin_PS4_RightTrigger_Pull,
	k_EControllerActionOrigin_PS4_RightTrigger_Click,
	k_EControllerActionOrigin_PS4_LeftStick_Move,
	k_EControllerActionOrigin_PS4_LeftStick_Click,
	k_EControllerActionOrigin_PS4_LeftStick_DPadNorth,
	k_EControllerActionOrigin_PS4_LeftStick_DPadSouth,
	k_EControllerActionOrigin_PS4_LeftStick_DPadWest,
	k_EControllerActionOrigin_PS4_LeftStick_DPadEast,
	k_EControllerActionOrigin_PS4_RightStick_Move,
	k_EControllerActionOrigin_PS4_RightStick_Click,
	k_EControllerActionOrigin_PS4_RightStick_DPadNorth,
	k_EControllerActionOrigin_PS4_RightStick_DPadSouth,
	k_EControllerActionOrigin_PS4_RightStick_DPadWest,
	k_EControllerActionOrigin_PS4_RightStick_DPadEast,
	k_EControllerActionOrigin_PS4_DPad_North,
	k_EControllerActionOrigin_PS4_DPad_South,
	k_EControllerActionOrigin_PS4_DPad_West,
	k_EControllerActionOrigin_PS4_DPad_East,
	k_EControllerActionOrigin_PS4_Gyro_Move,
	k_EControllerActionOrigin_PS4_Gyro_Pitch,
	k_EControllerActionOrigin_PS4_Gyro_Yaw,
	k_EControllerActionOrigin_PS4_Gyro_Roll,

	// XBox One
	k_EControllerActionOrigin_XBoxOne_A,
	k_EControllerActionOrigin_XBoxOne_B,
	k_EControllerActionOrigin_XBoxOne_X,
	k_EControllerActionOrigin_XBoxOne_Y,
	k_EControllerActionOrigin_XBoxOne_LeftBumper,
	k_EControllerActionOrigin_XBoxOne_RightBumper,
	k_EControllerActionOrigin_XBoxOne_Menu,  //Start
	k_EControllerActionOrigin_XBoxOne_View,  //Back
	k_EControllerActionOrigin_XBoxOne_LeftTrigger_Pull,
	k_EControllerActionOrigin_XBoxOne_LeftTrigger_Click,
	k_EControllerActionOrigin_XBoxOne_RightTrigger_Pull,
	k_EControllerActionOrigin_XBoxOne_RightTrigger_Click,
	k_EControllerActionOrigin_XBoxOne_LeftStick_Move,
	k_EControllerActionOrigin_XBoxOne_LeftStick_Click,
	k_EControllerActionOrigin_XBoxOne_LeftStick_DPadNorth,
	k_EControllerActionOrigin_XBoxOne_LeftStick_DPadSouth,
	k_EControllerActionOrigin_XBoxOne_LeftStick_DPadWest,
	k_EControllerActionOrigin_XBoxOne_LeftStick_DPadEast,
	k_EControllerActionOrigin_XBoxOne_RightStick_Move,
	k_EControllerActionOrigin_XBoxOne_RightStick_Click,
	k_EControllerActionOrigin_XBoxOne_RightStick_DPadNorth,
	k_EControllerActionOrigin_XBoxOne_RightStick_DPadSouth,
	k_EControllerActionOrigin_XBoxOne_RightStick_DPadWest,
	k_EControllerActionOrigin_XBoxOne_RightStick_DPadEast,
	k_EControllerActionOrigin_XBoxOne_DPad_North,
	k_EControllerActionOrigin_XBoxOne_DPad_South,
	k_EControllerActionOrigin_XBoxOne_DPad_West,
	k_EControllerActionOrigin_XBoxOne_DPad_East,

	// XBox 360
	k_EControllerActionOrigin_XBox360_A,
	k_EControllerActionOrigin_XBox360_B,
	k_EControllerActionOrigin_XBox360_X,
	k_EControllerActionOrigin_XBox360_Y,
	k_EControllerActionOrigin_XBox360_LeftBumper,
	k_EControllerActionOrigin_XBox360_RightBumper,
	k_EControllerActionOrigin_XBox360_Start,  //Start
	k_EControllerActionOrigin_XBox360_Back,  //Back
	k_EControllerActionOrigin_XBox360_LeftTrigger_Pull,
	k_EControllerActionOrigin_XBox360_LeftTrigger_Click,
	k_EControllerActionOrigin_XBox360_RightTrigger_Pull,
	k_EControllerActionOrigin_XBox360_RightTrigger_Click,
	k_EControllerActionOrigin_XBox360_LeftStick_Move,
	k_EControllerActionOrigin_XBox360_LeftStick_Click,
	k_EControllerActionOrigin_XBox360_LeftStick_DPadNorth,
	k_EControllerActionOrigin_XBox360_LeftStick_DPadSouth,
	k_EControllerActionOrigin_XBox360_LeftStick_DPadWest,
	k_EControllerActionOrigin_XBox360_LeftStick_DPadEast,
	k_EControllerActionOrigin_XBox360_RightStick_Move,
	k_EControllerActionOrigin_XBox360_RightStick_Click,
	k_EControllerActionOrigin_XBox360_RightStick_DPadNorth,
	k_EControllerActionOrigin_XBox360_RightStick_DPadSouth,
	k_EControllerActionOrigin_XBox360_RightStick_DPadWest,
	k_EControllerActionOrigin_XBox360_RightStick_DPadEast,
	k_EControllerActionOrigin_XBox360_DPad_North,
	k_EControllerActionOrigin_XBox360_DPad_South,
	k_EControllerActionOrigin_XBox360_DPad_West,
	k_EControllerActionOrigin_XBox360_DPad_East,	

	// SteamController V2
	k_EControllerActionOrigin_SteamV2_A,
	k_EControllerActionOrigin_SteamV2_B,
	k_EControllerActionOrigin_SteamV2_X,
	k_EControllerActionOrigin_SteamV2_Y,
	k_EControllerActionOrigin_SteamV2_LeftBumper,
	k_EControllerActionOrigin_SteamV2_RightBumper,
	k_EControllerActionOrigin_SteamV2_LeftGrip_Lower,
	k_EControllerActionOrigin_SteamV2_LeftGrip_Upper,
	k_EControllerActionOrigin_SteamV2_RightGrip_Lower,
	k_EControllerActionOrigin_SteamV2_RightGrip_Upper,
	k_EControllerActionOrigin_SteamV2_LeftBumper_Pressure,
	k_EControllerActionOrigin_SteamV2_RightBumper_Pressure,
	k_EControllerActionOrigin_SteamV2_LeftGrip_Pressure,
	k_EControllerActionOrigin_SteamV2_RightGrip_Pressure,
	k_EControllerActionOrigin_SteamV2_LeftGrip_Upper_Pressure,
	k_EControllerActionOrigin_SteamV2_RightGrip_Upper_Pressure,
	k_EControllerActionOrigin_SteamV2_Start,
	k_EControllerActionOrigin_SteamV2_Back,
	k_EControllerActionOrigin_SteamV2_LeftPad_Touch,
	k_EControllerActionOrigin_SteamV2_LeftPad_Swipe,
	k_EControllerActionOrigin_SteamV2_LeftPad_Click,
	k_EControllerActionOrigin_SteamV2_LeftPad_Pressure,
	k_EControllerActionOrigin_SteamV2_LeftPad_DPadNorth,
	k_EControllerActionOrigin_SteamV2_LeftPad_DPadSouth,
	k_EControllerActionOrigin_SteamV2_LeftPad_DPadWest,
	k_EControllerActionOrigin_SteamV2_LeftPad_DPadEast,
	k_EControllerActionOrigin_SteamV2_RightPad_Touch,
	k_EControllerActionOrigin_SteamV2_RightPad_Swipe,
	k_EControllerActionOrigin_SteamV2_RightPad_Click,
	k_EControllerActionOrigin_SteamV2_RightPad_Pressure,
	k_EControllerActionOrigin_SteamV2_RightPad_DPadNorth,
	k_EControllerActionOrigin_SteamV2_RightPad_DPadSouth,
	k_EControllerActionOrigin_SteamV2_RightPad_DPadWest,
	k_EControllerActionOrigin_SteamV2_RightPad_DPadEast,
	k_EControllerActionOrigin_SteamV2_LeftTrigger_Pull,
	k_EControllerActionOrigin_SteamV2_LeftTrigger_Click,
	k_EControllerActionOrigin_SteamV2_RightTrigger_Pull,
	k_EControllerActionOrigin_SteamV2_RightTrigger_Click,
	k_EControllerActionOrigin_SteamV2_LeftStick_Move,
	k_EControllerActionOrigin_SteamV2_LeftStick_Click,
	k_EControllerActionOrigin_SteamV2_LeftStick_DPadNorth,
	k_EControllerActionOrigin_SteamV2_LeftStick_DPadSouth,
	k_EControllerActionOrigin_SteamV2_LeftStick_DPadWest,
	k_EControllerActionOrigin_SteamV2_LeftStick_DPadEast,
	k_EControllerActionOrigin_SteamV2_Gyro_Move,
	k_EControllerActionOrigin_SteamV2_Gyro_Pitch,
	k_EControllerActionOrigin_SteamV2_Gyro_Yaw,
	k_EControllerActionOrigin_SteamV2_Gyro_Roll,

	// Switch - Pro or Joycons used as a single input device.
	// This does not apply to a single joycon
	k_EControllerActionOrigin_Switch_A,
	k_EControllerActionOrigin_Switch_B,
	k_EControllerActionOrigin_Switch_X,
	k_EControllerActionOrigin_Switch_Y,
	k_EControllerActionOrigin_Switch_LeftBumper,
	k_EControllerActionOrigin_Switch_RightBumper,
	k_EControllerActionOrigin_Switch_Plus,  //Start
	k_EControllerActionOrigin_Switch_Minus,	//Back
	k_EControllerActionOrigin_Switch_Capture,
	k_EControllerActionOrigin_Switch_LeftTrigger_Pull,
	k_EControllerActionOrigin_Switch_LeftTrigger_Click,
	k_EControllerActionOrigin_Switch_RightTrigger_Pull,
	k_EControllerActionOrigin_Switch_RightTrigger_Click,
	k_EControllerActionOrigin_Switch_LeftStick_Move,
	k_EControllerActionOrigin_Switch_LeftStick_Click,
	k_EControllerActionOrigin_Switch_LeftStick_DPadNorth,
	k_EControllerActionOrigin_Switch_LeftStick_DPadSouth,
	k_EControllerActionOrigin_Switch_LeftStick_DPadWest,
	k_EControllerActionOrigin_Switch_LeftStick_DPadEast,
	k_EControllerActionOrigin_Switch_RightStick_Move,
	k_EControllerActionOrigin_Switch_RightStick_Click,
	k_EControllerActionOrigin_Switch_RightStick_DPadNorth,
	k_EControllerActionOrigin_Switch_RightStick_DPadSouth,
	k_EControllerActionOrigin_Switch_RightStick_DPadWest,
	k_EControllerActionOrigin_Switch_RightStick_DPadEast,
	k_EControllerActionOrigin_Switch_DPad_North,
	k_EControllerActionOrigin_Switch_DPad_South,
	k_EControllerActionOrigin_Switch_DPad_West,
	k_EControllerActionOrigin_Switch_DPad_East,
	k_EControllerActionOrigin_Switch_ProGyro_Move,  // Primary Gyro in Pro Controller, or Right JoyCon
	k_EControllerActionOrigin_Switch_ProGyro_Pitch,  // Primary Gyro in Pro Controller, or Right JoyCon
	k_EControllerActionOrigin_Switch_ProGyro_Yaw,  // Primary Gyro in Pro Controller, or Right JoyCon
	k_EControllerActionOrigin_Switch_ProGyro_Roll,  // Primary Gyro in Pro Controller, or Right JoyCon
	// Switch JoyCon Specific
	k_EControllerActionOrigin_Switch_RightGyro_Move,  // Right JoyCon Gyro generally should correspond to Pro's single gyro
	k_EControllerActionOrigin_Switch_RightGyro_Pitch,  // Right JoyCon Gyro generally should correspond to Pro's single gyro
	k_EControllerActionOrigin_Switch_RightGyro_Yaw,  // Right JoyCon Gyro generally should correspond to Pro's single gyro
	k_EControllerActionOrigin_Switch_RightGyro_Roll,  // Right JoyCon Gyro generally should correspond to Pro's single gyro
	k_EControllerActionOrigin_Switch_LeftGyro_Move,
	k_EControllerActionOrigin_Switch_LeftGyro_Pitch,
	k_EControllerActionOrigin_Switch_LeftGyro_Yaw,
	k_EControllerActionOrigin_Switch_LeftGyro_Roll,
	k_EControllerActionOrigin_Switch_LeftGrip_Lower, // Left JoyCon SR Button
	k_EControllerActionOrigin_Switch_LeftGrip_Upper, // Left JoyCon SL Button
	k_EControllerActionOrigin_Switch_RightGrip_Lower,  // Right JoyCon SL Button
	k_EControllerActionOrigin_Switch_RightGrip_Upper,  // Right JoyCon SR Button

	// Added in SDK 1.45
	k_EControllerActionOrigin_PS4_DPad_Move,
	k_EControllerActionOrigin_XBoxOne_DPad_Move,
	k_EControllerActionOrigin_XBox360_DPad_Move,
	k_EControllerActionOrigin_Switch_DPad_Move,

	k_EControllerActionOrigin_Count, // If Steam has added support for new controllers origins will go here.
	k_EControllerActionOrigin_MaximumPossibleValue = 32767, // Origins are currently a maximum of 16 bits.
};

enum EXboxOrigin
{
	k_EXboxOrigin_A,
	k_EXboxOrigin_B,
	k_EXboxOrigin_X,
	k_EXboxOrigin_Y,
	k_EXboxOrigin_LeftBumper,
	k_EXboxOrigin_RightBumper,
	k_EXboxOrigin_Menu,  //Start
	k_EXboxOrigin_View,  //Back
	k_EXboxOrigin_LeftTrigger_Pull,
	k_EXboxOrigin_LeftTrigger_Click,
	k_EXboxOrigin_RightTrigger_Pull,
	k_EXboxOrigin_RightTrigger_Click,
	k_EXboxOrigin_LeftStick_Move,
	k_EXboxOrigin_LeftStick_Click,
	k_EXboxOrigin_LeftStick_DPadNorth,
	k_EXboxOrigin_LeftStick_DPadSouth,
	k_EXboxOrigin_LeftStick_DPadWest,
	k_EXboxOrigin_LeftStick_DPadEast,
	k_EXboxOrigin_RightStick_Move,
	k_EXboxOrigin_RightStick_Click,
	k_EXboxOrigin_RightStick_DPadNorth,
	k_EXboxOrigin_RightStick_DPadSouth,
	k_EXboxOrigin_RightStick_DPadWest,
	k_EXboxOrigin_RightStick_DPadEast,
	k_EXboxOrigin_DPad_North,
	k_EXboxOrigin_DPad_South,
	k_EXboxOrigin_DPad_West,
	k_EXboxOrigin_DPad_East,
};

enum ESteamInputType
{
	k_ESteamInputType_Unknown,
	k_ESteamInputType_SteamController,
	k_ESteamInputType_XBox360Controller,
	k_ESteamInputType_XBoxOneController,
	k_ESteamInputType_GenericGamepad,		// DirectInput controllers
	k_ESteamInputType_PS4Controller,
	k_ESteamInputType_AppleMFiController,	// Unused
	k_ESteamInputType_AndroidController,	// Unused
	k_ESteamInputType_SwitchJoyConPair,		// Unused
	k_ESteamInputType_SwitchJoyConSingle,	// Unused
	k_ESteamInputType_SwitchProController,
	k_ESteamInputType_MobileTouch,			// Steam Link App On-screen Virtual Controller
	k_ESteamInputType_PS3Controller,		// Currently uses PS4 Origins
	k_ESteamInputType_Count,
	k_ESteamInputType_MaximumPossibleValue = 255,
};

enum ESteamControllerLEDFlag
{
	k_ESteamControllerLEDFlag_SetColor,
	k_ESteamControllerLEDFlag_RestoreUserDefault
};

// ControllerHandle_t is used to refer to a specific controller.
// This handle will consistently identify a controller, even if it is disconnected and re-connected
typedef uint64 ControllerHandle_t;


// These handles are used to refer to a specific in-game action or action set
// All action handles should be queried during initialization for performance reasons
typedef uint64 ControllerActionSetHandle_t;
typedef uint64 ControllerDigitalActionHandle_t;
typedef uint64 ControllerAnalogActionHandle_t;

#pragma pack( push, 1 )

struct SteamControllerState001_t
{
	// If packet num matches that on your prior call, then the controller state hasn't been changed since 
	// your last call and there is no need to process it
	uint32 unPacketNum;

	// bit flags for each of the buttons
	uint64 ulButtons;

	// Left pad coordinates
	short sLeftPadX;
	short sLeftPadY;

	// Right pad coordinates
	short sRightPadX;
	short sRightPadY;
};

struct ControllerAnalogActionData_t
{
	// Type of data coming from this action, this will match what got specified in the action set
	EControllerSourceMode eMode;
	
	// The current state of this action; will be delta updates for mouse actions
	float x, y;
	
	// Whether or not this action is currently available to be bound in the active action set
	bool bActive;
};

struct ControllerDigitalActionData_t
{
	// The current state of this action; will be true if currently pressed
	bool bState;
	
	// Whether or not this action is currently available to be bound in the active action set
	bool bActive;
};

struct ControllerMotionData_t
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

#endif //CONTROLLERCOMMON_H
