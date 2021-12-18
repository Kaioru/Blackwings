#include <windows.h>
#include <iostream>

#include "Config.h"

std::string Config::Host;
std::uint16_t Config::Port;

void Config::Initialize() {
    char* sHost = new char[255];

    GetPrivateProfileString("Connection", "Host", "127.0.0.1", sHost, 255, ".\\Blackwings.ini");

    Host = sHost;
    Port = GetPrivateProfileInt("Connection", "Port", 8484, ".\\Blackwings.ini");
}