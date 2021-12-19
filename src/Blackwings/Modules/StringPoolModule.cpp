#include <windows.h>
#include <map>
#include <string>
#include "detours/detours.h"

#include "StringPoolModule.h"
#include "../Game/StringPool.h"
#include "../Game/Addresses.h"
#include "../Config.h"

std::map<int, std::string> g_mStringPool;

auto oGetString = reinterpret_cast<pGetString>(ADDR_STRINGPOOL__GETSTRING);

ZXString<char>* __fastcall hkGetString(StringPool* pThis, void* edx, ZXString<char>* result, unsigned int nIdx, char formal) {
    if (g_mStringPool.count(nIdx) > 0) {
        auto szEntry = g_mStringPool[nIdx];
        result->Assign(szEntry.c_str(), -1);
        return result;
    }

    return oGetString(pThis, edx, result, nIdx, formal);
}

void StringPoolModule::Initialize() {
    g_mStringPool[909] = "[Welcome] Welcome to Mushroom game!!";
    g_mStringPool[910] = "[Tip]";
}

void StringPoolModule::Attach() {
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourAttach((PVOID*)&oGetString, (PVOID)hkGetString);
    DetourTransactionCommit();
}

void StringPoolModule::Detach() {
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourDetach((PVOID*)&oGetString, (PVOID)hkGetString);
    DetourTransactionCommit();
}
