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
    static BOOL     GameInputJoystickDisable;
    static BOOL     GameNetMsgCustom;
    static BOOL     GameNetMsgCustomProtocol;

    static BOOL     ExportIjl15;

    static VOID Read();
};
