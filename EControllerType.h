typedef enum EControllerType
{
    k_EControllerTypeController_none = -1, // controller_none
    k_EControllerTypeController_unknown, // controller_unknown
    k_EControllerTypeController_steamcontroller_unknown, // controller_steamcontroller_unknown
    k_EControllerTypeController_steamcontroller_gordon, // controller_steamcontroller_gordon
    k_EControllerTypeController_steamcontroller_headcrab, // controller_steamcontroller_headcrab
    k_EControllerTypeController_ps4, // controller_ps4
    k_EControllerTypeController_front_panel_board = 20, // controller_front_panel_board
    k_EControllerTypeController_generic = 30, // controller_generic
    k_EControllerTypeController_xbox360, // controller_xbox360
    k_EControllerTypeController_xboxone, // controller_xboxone
    k_EControllerTypeController_ps3, // controller_ps3
    k_EControllerTypeController_ps4, // controller_ps4
    k_EControllerTypeController_wii, // controller_wii
    k_EControllerTypeController_apple, // controller_apple
    k_EControllerTypeController_android, // controller_android
    k_EControllerTypeController_switch_pro, // controller_switch_pro
    k_EControllerTypeController_switch_joycon_left, // controller_switch_joycon_left
    k_EControllerTypeController_switch_joycon_right, // controller_switch_joycon_right
    k_EControllerTypeController_switch_joycon_pair, // controller_switch_joycon_pair
    k_EControllerTypeController_switch_pro_generic, // controller_switch_pro_generic
    k_EControllerTypeController_mobile_touch, // controller_mobile_touch
    k_EControllerTypeController_ps5 = 45, // controller_ps5
    k_EControllerTypeController_xboxelite, // controller_xboxelite
    k_EControllerTypeController_keyboard_generic = 400, // controller_keyboard_generic
    k_EControllerTypeController_mouse_generic = 800, // controller_mouse_generic
} EControllerType;
