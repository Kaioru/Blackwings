#include "pch.h"

#define CONFIG_FILE_PATH "./Blackwings.ini"

LPSTR   Config::ConnectionHost;
USHORT  Config::ConnectionPort;

LPSTR   Config::GameTitle;
BOOL    Config::GameWindowSizing;

VOID Config::Read() {
    LPSTR sHost = new char[255];

    GetPrivateProfileStringA("Connection", "Host", "127.0.0.1", sHost, 255, CONFIG_FILE_PATH);

    ConnectionHost = sHost;
    ConnectionPort = GetPrivateProfileIntA("Connection", "Port", 8484, CONFIG_FILE_PATH);

    LPSTR sTitle = new char[255];

    GetPrivateProfileStringA("Game", "Title", "Blackwings", sTitle, 255, CONFIG_FILE_PATH);

    GameTitle = sTitle;
    GameWindowSizing = GetPrivateProfileIntA("Game", "GameWindowSizing", 1, CONFIG_FILE_PATH);
}
