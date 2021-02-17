#ifndef PCH_H
#define PCH_H
#define WIN32_LEAN_AND_MEAN    

#include <windows.h>
#include <iostream>
#include <string>
#include <wininet.h>
#include <fstream>
#include <algorithm>
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <tchar.h>
#include <math.h>
#include <stdlib.h>
#include <direct.h>
#include <fcntl.h>
#include <io.h>
#include <vector>
#include <rpc.h>
#include <rpcdce.h>
#include <iomanip>
#include <cstdlib>
#include <tlhelp32.h>
#include <process.h>
#include <shellapi.h>
#include "winsock.h"
#include <sstream>
#include "../Source/discord/include/discord_register.h"
#include "../Source/discord/include/discord_rpc.h"

BOOL Hook(void* pAddr, void* pNAddr, int len = 5);

#endif 

extern  "C"  __declspec(dllexport) void __cdecl Main();

void Discord();

class Shaiya
{
public:
	int Discord;
};
extern Shaiya DLL;



