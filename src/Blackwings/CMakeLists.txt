cmake_minimum_required (VERSION 3.8)

project ("Blackwings")

file (GLOB_RECURSE BLACKWINGS_SRC CONFIGURE_DEPENDS "*.h" "*.cpp")
configure_file (Blackwings.ini Blackwings.ini COPYONLY)

add_library (${PROJECT_NAME} SHARED ${BLACKWINGS_SRC})

find_path (DETOURS_INCLUDE_DIR detours)
find_library (DETOURS_INCLUDE_LIB detours)

target_include_directories (${PROJECT_NAME} PRIVATE ${DETOURS_INCLUDE_DIR})
target_link_libraries (${PROJECT_NAME} ${DETOURS_INCLUDE_LIB})
target_link_libraries (${PROJECT_NAME} wsock32 ws2_32)
