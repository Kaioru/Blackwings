#pragma once

class Config {
public:
    static LPSTR    ConnectionHost;
    static USHORT   ConnectionPort;

    static LPSTR    GameTitle;
    static BOOL     GameLogoSkip;
    static BOOL     GameWindowSizing;

    static VOID Read();
};
