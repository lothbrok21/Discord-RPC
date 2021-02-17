#include "pch.h"
Shaiya DLL;
extern  "C"  __declspec(dllexport) void __cdecl Main()
{
    DLL.Discord = 1;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        Main();
        if (DLL.Discord == 1)
        {            
            Discord();           
        }
      
      
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

