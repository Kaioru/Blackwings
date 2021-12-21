#include <windows.h>
#include <stdio.h>
#include "GameMemoryModule.h"

#include "../Game/Addresses.h"
#include "../Utils/Memory.h"

void GameMemoryModule::PatchTotalDamageMax(double value) {
    Memory::Write<double>(ADDR_MEM_TOTAL_DAMAGE_MAX, value);
}
