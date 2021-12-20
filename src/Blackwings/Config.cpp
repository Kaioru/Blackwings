#include <windows.h>
#include <iostream>

#include "Config.h"

#define CONFIG_LOAD_FROM_FILE   true
#define CONFIG_FILE_PATH        "./Blackwings.ini"

#define CONFIG_CONNECTION_HOST  "127.0.0.1"
#define CONFIG_CONNECTION_PORT  8484
#define CONFIG_GAME_TITLE       "Blackwings"

ConfigConnection Config::Connection;
ConfigGame Config::Game;

void Config::Initialize() {
#if CONFIG_LOAD_FROM_FILE
    char* sHost = new char[255];

    GetPrivateProfileString("Connection", "Host", CONFIG_CONNECTION_HOST, sHost, 255, CONFIG_FILE_PATH);

    Connection.Host = sHost;
    Connection.Port = GetPrivateProfileInt("Connection", "Port", CONFIG_CONNECTION_PORT, CONFIG_FILE_PATH);

    char* sTitle = new char[255];

    GetPrivateProfileString("Game", "Title", CONFIG_GAME_TITLE, sTitle, 255, CONFIG_FILE_PATH);

    Game.Title = sTitle;
#else
    Connection.Host = CONFIG_CONNECTION_HOST;
    Connection.Port = CONFIG_CONNECTION_PORT;
    Game.Title = CONFIG_GAME_TITLE;
#endif
}
