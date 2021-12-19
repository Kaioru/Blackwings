#include <iostream>

struct ConfigConnection {
    std::string Host;
    std::uint16_t Port;
};

struct ConfigGame {
    std::string Title;
};

class Config {
public:
    static ConfigConnection Connection;
    static ConfigGame Game;

    static void Initialize();
};