#include <windows.h>
#include <iostream>

#include "Config.h"

#define DEFAULT_CONFIG_FILE "./Blackwings.ini"

ConfigConnection Config::Connection;
ConfigGame Config::Game;

void Config::Initialize() {
    char* sHost = new char[255];

    GetPrivateProfileString("Connection", "Host", "127.0.0.1", sHost, 255, DEFAULT_CONFIG_FILE);

    Connection.Host = sHost;
    Connection.Port = GetPrivateProfileInt("Connection", "Port", 8484, DEFAULT_CONFIG_FILE);

    char* sTitle = new char[255];

    GetPrivateProfileString("Game", "Title", "Blackwings", sTitle, 255, DEFAULT_CONFIG_FILE);

    Game.Title = sTitle;
}