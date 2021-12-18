#include <iostream>

class Config {
public:
    static std::string Host;
    static std::uint16_t Port;

    static void Initialize();
};