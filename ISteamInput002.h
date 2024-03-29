class ISteamInput002
{
public:
    virtual unknown_ret Init() = 0;
    virtual unknown_ret Shutdown() = 0;
    virtual unknown_ret RunFrame() = 0;
    virtual unknown_ret GetConnectedControllers(unsigned long long*) = 0;
    virtual unknown_ret GetActionSetHandle(char const*) = 0;
    virtual unknown_ret ActivateActionSet(unsigned long long, unsigned long long) = 0;
    virtual unknown_ret GetCurrentActionSet(unsigned long long) = 0;
    virtual unknown_ret ActivateActionSetLayer(unsigned long long, unsigned long long) = 0;
    virtual unknown_ret DeactivateActionSetLayer(unsigned long long, unsigned long long) = 0;
    virtual unknown_ret DeactivateAllActionSetLayers(unsigned long long) = 0;
    virtual unknown_ret GetActiveActionSetLayers(unsigned long long, unsigned long long*) = 0;
    virtual unknown_ret GetDigitalActionHandle(char const*) = 0;
    virtual unknown_ret GetDigitalActionData(unsigned long long, unsigned long long) = 0;
    virtual unknown_ret GetDigitalActionOrigins(unsigned long long, unsigned long long, unsigned long long, EInputActionOrigin*) = 0;
    virtual unknown_ret GetAnalogActionHandle(char const*) = 0;
    virtual unknown_ret GetAnalogActionData(unsigned long long, unsigned long long) = 0;
    virtual unknown_ret GetAnalogActionOrigins(unsigned long long, unsigned long long, unsigned long long, EInputActionOrigin*) = 0;
    virtual unknown_ret GetGlyphForActionOrigin(EInputActionOrigin) = 0;
    virtual unknown_ret GetStringForActionOrigin(EInputActionOrigin) = 0;
    virtual unknown_ret StopAnalogActionMomentum(unsigned long long, unsigned long long) = 0;
    virtual unknown_ret GetMotionData(unsigned long long) = 0;
    virtual unknown_ret TriggerVibration(unsigned long long, unsigned short, unsigned short) = 0;
    virtual unknown_ret SetLEDColor(unsigned long long, unsigned char, unsigned char, unsigned char, unsigned int) = 0;
    virtual unknown_ret TriggerHapticPulse(unsigned long long, ESteamControllerPad, unsigned short) = 0;
    virtual unknown_ret TriggerRepeatedHapticPulse(unsigned long long, ESteamControllerPad, unsigned short, unsigned short, unsigned short, unsigned int) = 0;
    virtual unknown_ret ShowBindingPanel(unsigned long long) = 0;
    virtual unknown_ret GetInputTypeForHandle(unsigned long long) = 0;
    virtual unknown_ret GetControllerForGamepadIndex(int) = 0;
    virtual unknown_ret GetGamepadIndexForController(unsigned long long) = 0;
    virtual unknown_ret GetStringForXboxOrigin(EXboxOrigin) = 0;
    virtual unknown_ret GetGlyphForXboxOrigin(EXboxOrigin) = 0;
    virtual unknown_ret GetActionOriginFromXboxOrigin(unsigned long long, EXboxOrigin) = 0;
    virtual unknown_ret TranslateActionOrigin(ESteamInputType, EInputActionOrigin) = 0;
    virtual unknown_ret GetDeviceBindingRevision(unsigned long long, int*, int*) = 0;
    virtual unknown_ret GetRemotePlaySessionID(unsigned long long) = 0;
};
