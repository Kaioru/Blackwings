#pragma once

class Config {
public:
    static LPSTR    ConnectionHost;
    static USHORT   ConnectionPort;

    static LPSTR    GameTitle;
    static BOOL     GameLogoSkip;
    static BOOL     GameWindowImGui;
    static BOOL     GameWindowSizing;
    static BOOL     GameResManUseFileSystem;
    static BOOL     GameResManUsePackage;
    static BOOL     GameResManLoadCustom;
    static BOOL     GameTemplateLazyLoad;
    static BOOL     GameInputJoystickDisable;

    static VOID Read();
};
