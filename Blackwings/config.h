#pragma once

class Config {
public:
    static LPSTR    ConnectionHost;
    static USHORT   ConnectionPort;

    static LPSTR    GameTitle;
    static BOOL     GameLogoSkip;
    static BOOL     GameWindowImGui;
    static BOOL     GameWindowSizing;
    static BOOL     GameResManFileSystem;
    static BOOL     GameResManHotfix;
    static BOOL     GameTemplateLazyLoad;
    static BOOL     GameInputJoystickDisable;

    static VOID Read();
};
