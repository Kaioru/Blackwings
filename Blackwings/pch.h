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
#endif

#include <fmt/format.h>
#include <spdlog/spdlog.h>

#include "CWvsContext.h"
#include "CInputSystem.h"

#include "Ztl_bstr_t.h";

#include "config.h"
#include "memory.h"
#include "patches.h"
#include "game.h"

#endif
