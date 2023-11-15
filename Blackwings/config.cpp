#include "pch.h"

#define CONFIG_FILE_PATH "./Blackwings.ini"

LPSTR   Config::ConnectionHost;
USHORT  Config::ConnectionPort;

LPSTR   Config::GameTitle;
BOOL    Config::GameLogoSkip;
BOOL    Config::GameWindowImGui;
BOOL    Config::GameWindowSizing;
BOOL    Config::GameResManUseFileSystem;
BOOL    Config::GameResManUsePackage;
BOOL    Config::GameResManLoadCustom;
BOOL    Config::GameInputJoystickDisable;

BOOL    Config::ExportIjl15;

VOID Config::Read() {
    LPSTR sHost = new char[255];

    GetPrivateProfileStringA("Connection", "Host", "127.0.0.1", sHost, 255, CONFIG_FILE_PATH);

    ConnectionHost = sHost;
    ConnectionPort = GetPrivateProfileIntA("Connection", "Port", 8484, CONFIG_FILE_PATH);

    LPSTR sTitle = new char[255];

    GetPrivateProfileStringA("Game", "Title", "Blackwings", sTitle, 255, CONFIG_FILE_PATH);

    GameTitle = sTitle;
    GameLogoSkip                = GetPrivateProfileIntA("Game", "LogoSkip", 1, CONFIG_FILE_PATH);
    GameWindowImGui             = GetPrivateProfileIntA("Game", "WindowImGui", 1, CONFIG_FILE_PATH);
    GameWindowSizing            = GetPrivateProfileIntA("Game", "WindowSizing", 1, CONFIG_FILE_PATH);
    GameResManUseFileSystem     = GetPrivateProfileIntA("Game", "ResManUseFileSystem", 0, CONFIG_FILE_PATH);
    GameResManUsePackage        = GetPrivateProfileIntA("Game", "ResManUsePackage", 0, CONFIG_FILE_PATH);
    GameResManLoadCustom        = GetPrivateProfileIntA("Game", "ResManLoadCustom", 0, CONFIG_FILE_PATH);
    GameInputJoystickDisable    = GetPrivateProfileIntA("Game", "InputJoystickDisable", 1, CONFIG_FILE_PATH);

    ExportIjl15                 = GetPrivateProfileIntA("Export", "ijl15", 0, CONFIG_FILE_PATH);
}
