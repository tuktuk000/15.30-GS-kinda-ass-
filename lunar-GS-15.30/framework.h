#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>
#include <thread>
#include <iostream>
#include <vector>
#include <memory>
#include  <string>
#include "SDK/SDK.hpp"
using namespace SDK;
#include "MinHook.h"

inline uint64 ImageBase = uint64(GetModuleHandle(0));


    namespace Addresses {
        inline uint64_t Step = 0x3897380;
        inline uint64_t StepExplicitProperty = 0x38973b0;
        inline uint64_t CreateNetDriver = 0x5285050;
        inline uint64_t InitListen = 0x118fd70;
        inline uint64_t SetWorld = 0x4feeb90;
        inline uint64_t GetNetMode = 0x52ec180;
        inline uint64_t TickFlush = 0x4ff0070;
        inline uint64_t ServerReplicateActors = 0x176c2e0;
        inline uint64_t GetMaxTickRate = 0x528bed0;
        inline uint64_t DispatchRequest = 0x105d5b0;
        inline uint64_t Realloc = 0x35a15a0;
        inline uint64_t StaticFindObject = 0x38bfc10;
        inline uint64_t StaticLoadObject = 0x38c1a30;
        inline uint64_t GIsClient = 0x96bc1cc;
        inline uint64_t GameSessionPatch = 0x21803e5;
        inline uint64_t EncryptionPatch = 0x52ee7ee;
        inline std::vector<uint64_t> NullFuncs = { 0x2746000, 0x4e87860 };
        inline std::vector<uint64_t> RetTrueFuncs = {  };
    };

    namespace Funcs {
        inline auto CreateNetDriver = (SDK::UNetDriver * (*)(SDK::UEngine*, SDK::UWorld*, SDK::FName)) (ImageBase + Addresses::CreateNetDriver);
        inline auto InitListen = (bool (*)(SDK::UNetDriver*, SDK::UWorld*, SDK::FURL&, bool, UC::FString)) (ImageBase + Addresses::InitListen);
        inline auto SetWorld = (void (*)(SDK::UNetDriver*, SDK::UWorld*)) (ImageBase + Addresses::SetWorld);
        inline auto ServerReplicateActors = (void (*)(SDK::UReplicationDriver*, float)) (ImageBase + Addresses::ServerReplicateActors);
        inline auto Realloc = (void* (*)(void*, __int64, unsigned int)) (ImageBase + Addresses::Realloc);
        inline auto StaticFindObject = (SDK::UObject * (*)(SDK::UClass*, SDK::UObject*, const wchar_t*, bool)) (ImageBase + Addresses::StaticFindObject);
        inline auto StaticLoadObject = (SDK::UObject * (*)(SDK::UClass*, SDK::UObject*, const wchar_t*, const wchar_t*, uint32_t, SDK::UObject*, bool)) (ImageBase + Addresses::StaticLoadObject);
    };
static void Hook(uint64 Address, void* Detour, void** OG)
{
    MH_CreateHook(LPVOID(Address), Detour, OG);
    MH_EnableHook(LPVOID(Address));
}