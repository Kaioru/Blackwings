# Blackwings [![Build](https://github.com/Kaioru/Blackwings/actions/workflows/build.yaml/badge.svg)](https://github.com/Kaioru/Blackwings/actions/workflows/build.yaml)
..is a v.95.1 Mushroom game client

### 🎉 Features
Features of Blackwings are configurable via `Blackwings.ini`

The following are the available config options:

#### Connection
* Host - Connection host
* Port - Connection port
#### Game
* Title - Game Window Title
* LogoSkip - Enables game logo skip
* LoadMonsterBookSkip - Enables monster book load skip
* WindowImGui - Enables DirectX9 hooks for ImGui
* WindowSizing - Enables dynamic window resizing
* ResManUseFileSystem - Enables loading from .img files via the Data/ directory
* ResManUsePackage - Enables loading from .wz files (default behavior)
* ResManLoadCustom - Enables loading custom data and various features
    * Note: Ensure either ResManUseFileSystem or ResManUsePackage is set to 1
    * The file loaded will be based on the configured game title for example: `Blackwings.wz`
    * The `Overrides.img` allows for override of data nodes found in the base data (possibly works for adding new as well)
* InputJoystickDisable - Disables joystick detection to avoid unneccessary poll calls
* NetMsgCustom - Enables overriding OnPacket methods for custom packet handling
* NetMsgCustomProtocol - Enables handling of Blackwings network protocol
    * BWSEND_INIT - Sent during every login stage connection

### ✨ Usage

#### Prerequisites
* An installation of v.95.1 Mushroom game
* A working copy of a v.95.1 localhost

#### Download a release
1. Check the [releases](https://github.com/Kaioru/Blackwings/releases) tab and download a release!
    * Note: Debug builds contain additional debugging tools and logging

#### Copy release contents
2. Copy contents of the release to your Mushroom game folder with the localhost
    * `Blackwings.dll`, `Blackwings.ini`, and other `*.dll` files (if any)

#### Method 1: Using the injector
3. Copy `Blackwings Launcher.exe` to your Mushroom game folder
4. Rename your localhost to `MapleStoryU.exe`
5. Run `Blackwings Launcher.exe`
    * It should run as administrator by default, if not do it manually

#### Method 2: Replacing ijl15.dll
3. Rename `ijl15.dll` to `ijl15_orig.dll`
4. Rename `Blackwings.dll` to `ijl15.dll`
5. Set `ijl15 = 1` under Export in `Blackwings.ini`

#### Method 3: Modifying imports of client
3. Open the localhost in CFF Explorer
4. Select `Import Adder` in the left tab
5. Select `Add` and locate `Blackwings.dll`
6. Select `00000001 - NoOp` in the Exported Functions tab
7. Select the `Import By Name` button
8. Select `Rebuild Import Table`
9. Save the file via the toolbar `File -> Save`

#### Update configurations
10. Modify the `Blackwings.ini` file to the appropriate settings

#### Running the localhost
11. Run the localhost executable and `Blackwings` will be automatically injected

### 🔨 Building
* Note: Blackwings can only be built on a Windows machine as it is a Win32 lib!

#### MSBuild / Visual Studio
1. [Install and setup vcpkg](https://vcpkg.io/en/getting-started.html)
2. Use the `msbuild` command or build in Visual Studio
