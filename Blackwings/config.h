#pragma once

class Config {
public:
    static LPSTR    ConnectionHost;
    static USHORT   ConnectionPort;

    static LPSTR    GameTitle;

    static VOID Read();
};
