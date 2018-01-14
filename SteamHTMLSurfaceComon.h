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

#ifndef HTMSURFACECOMMON_H
#define HTMSURFACECOMMON_H
#ifdef _WIN32
#pragma once
#endif

typedef uint32 HHTMLBrowser;
const uint32 INVALID_HTTMLBROWSER = 0;

enum EHTMLMouseButton
{
	eHTMLMouseButton_Left = 0,
	eHTMLMouseButton_Right = 1,
	eHTMLMouseButton_Middle = 2,
};

enum EMouseCursor
{
	dc_user = 0,
	dc_none,
	dc_arrow,
	dc_ibeam,
	dc_hourglass,
	dc_waitarrow,
	dc_crosshair,
	dc_up,
	dc_sizenw,
	dc_sizese,
	dc_sizene,
	dc_sizesw,
	dc_sizew,
	dc_sizee,
	dc_sizen,
	dc_sizes,
	dc_sizewe,
	dc_sizens,
	dc_sizeall,
	dc_no,
	dc_hand,
	dc_blank, // don't show any custom cursor, just use your default
	dc_middle_pan,
	dc_north_pan,
	dc_north_east_pan,
	dc_east_pan,
	dc_south_east_pan,
	dc_south_pan,
	dc_south_west_pan,
	dc_west_pan,
	dc_north_west_pan,
	dc_alias,
	dc_cell,
	dc_colresize,
	dc_copycur,
	dc_verticaltext,
	dc_rowresize,
	dc_zoomin,
	dc_zoomout,
	dc_help,
	dc_custom,

	dc_last, // custom cursors start from this value and up
};

	enum EHTMLKeyModifiers
	{
		eHTMLKeyModifier_None = 0,
		eHTMLKeyModifier_AltDown = 1 << 0,
		eHTMLKeyModifier_CrtlDown = 1 << 1,
		eHTMLKeyModifier_ShiftDown = 1 << 2,
	};

#define STEAMHTMLSURFACE_INTERFACE_VERSION_001 "STEAMHTMLSURFACE_INTERFACE_VERSION_001"
#define STEAMHTMLSURFACE_INTERFACE_VERSION_002 "STEAMHTMLSURFACE_INTERFACE_VERSION_002"
#define STEAMHTMLSURFACE_INTERFACE_VERSION_003 "STEAMHTMLSURFACE_INTERFACE_VERSION_003"
#define STEAMHTMLSURFACE_INTERFACE_VERSION_004 "STEAMHTMLSURFACE_INTERFACE_VERSION_004"

#endif // MUSICCOMMON_H