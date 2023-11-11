#include "pch.h"

#define CONFIG_FILE_PATH "./Blackwings.ini"

LPSTR   Config::ConnectionHost;
USHORT  Config::ConnectionPort;

void Config::Read() {
    GetPrivateProfileStringA("Connection", "Host", "127.0.0.1", ConnectionHost, 255, CONFIG_FILE_PATH);
    ConnectionPort = GetPrivateProfileIntA("Connection", "Port", 8484, CONFIG_FILE_PATH);
}
