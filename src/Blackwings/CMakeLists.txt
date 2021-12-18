cmake_minimum_required (VERSION 3.8)

configure_file (Blackwings.ini Blackwings.ini COPYONLY)

add_library (Blackwings SHARED DllMain.cpp "Config.h" "Config.cpp" "Modules/WinsockModule.h" "Modules/WinsockModule.cpp")

find_path (DETOURS_INCLUDE_DIR detours)
find_library (DETOURS_INCLUDE_LIB detours)

target_include_directories (Blackwings PRIVATE ${DETOURS_INCLUDE_DIR})
target_link_libraries (Blackwings ${DETOURS_INCLUDE_LIB})
target_link_libraries (Blackwings wsock32 ws2_32)