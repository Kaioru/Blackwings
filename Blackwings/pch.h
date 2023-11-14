// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

#include "framework.h"

#include <detours/detours.h>

#pragma comment(lib, "d3d9.lib")

#include <d3d9.h>
#include <dxsdk-d3dx/d3dx9.h>
#include <imgui.h>
#include <imgui_impl_dx9.h>
#include <imgui_impl_win32.h>

#ifndef _DEBUG
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_OFF
#else
#include <iostream>
#endif

#include <fmt/format.h>
#include <spdlog/spdlog.h>

#include "CWvsContext.h"
#include "CInputSystem.h"

#include "comip.h"
#include "comdef.h"

#include "IWzSerialize.h"
#include "IWzArchive.h"
#include "IWzShape2D.h"
#include "IWzVector2D.h"
#include "IWzGr2DLayer.h"
#include "IWzCanvas.h"
#include "IWzRawCanvasAllocator.h"
#include "IWzRawCanvas.h"
#include "IWzProperty.h"
#include "IWzFont.h"
#include "IWzResMan.h"
#include "IWzUOL.h"
#include "IWzGr2D.h"
#include "IWzSound.h"
#include "IWzSoundState.h"
#include "IWzNameSpace.h"
#include "IWzNameSpaceProperty.h"
#include "IWzWritableNameSpace.h"
#include "IWzFileSystem.h"
#include "IWzSeekableArchive.h"
#include "IWzPackage.h"
#include "IWzNameSpaceWriter.h"
#include "IWzPackageWriter.h"
#include "IWzConvex2D.h"
#include "IWzPolyShape2D.h"
#include "IWzList.h"

#include "config.h"
#include "memory.h"
#include "patches.h"
#include "game.h"

#endif
