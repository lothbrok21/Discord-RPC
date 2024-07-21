#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <include/util.h>

int util::detour(Address addr, Function func, int size) {
	if (size < 5) {
		return FALSE;
	}

	DWORD lpflOldProtect;
	if (!VirtualProtect(addr, size, PAGE_EXECUTE_READWRITE, &lpflOldProtect)) {
		return FALSE;
	}

	memset(addr, 0x90, size);
	DWORD dwAddress = ((DWORD)func - (DWORD)addr) - 5;
	*(PBYTE)addr = 0xE9;
	*(PDWORD)((DWORD)addr + 1) = dwAddress;

	DWORD flNewProtect = lpflOldProtect;
	VirtualProtect(addr, size, flNewProtect, &lpflOldProtect);
	return TRUE;
}

int util::write_memory(Address addr, Function func, int size) {
	DWORD dwOldProtect;
	VirtualProtect(addr, size, PAGE_READWRITE, &dwOldProtect);
	WriteProcessMemory(GetCurrentProcess(), addr, func, size, NULL);
	VirtualProtect(addr, size, dwOldProtect, &dwOldProtect);
	return TRUE;
}

int util::write_memory(Address addr, Byte value, int count)
{
    if (count < 1)
        return 0;

    unsigned long protect;
    if (!VirtualProtect(addr, count, PAGE_EXECUTE_READWRITE, &protect))
        return 0;

    memset(addr, value, count);
    return VirtualProtect(addr, count, protect, &protect);
}

int util::jump(Address addr, Address destAddr, int size) {
    if (size < 5) {
        return FALSE;
    }

    DWORD lpflOldProtect;
    if (!VirtualProtect(addr, size, PAGE_EXECUTE_READWRITE, &lpflOldProtect)) {
        return FALSE;
    }

    memset(addr, 0x90, size);
    DWORD dwAddress = ((DWORD)destAddr - (DWORD)addr) - 5;
    *(PBYTE)addr = 0xE9;
    *(PDWORD)((DWORD)addr + 1) = dwAddress;

    DWORD flNewProtect = lpflOldProtect;
    VirtualProtect(addr, size, flNewProtect, &lpflOldProtect);
    return TRUE;
}

const char8_t* util::string_to_utf8(const std::string& str) {
    return reinterpret_cast<const char8_t*>(str.c_str());
}

std::string util::utf8_to_string(const char8_t* utf8Chars) {
    return std::string(reinterpret_cast<const char*>(utf8Chars));
}

bool util::IsMouseInArea(UINT32 buttonLeft, UINT32 buttonRight, UINT32 buttonUp, UINT32 buttonDown, UINT32 mouseX, UINT32 mouseY) {
	return (mouseX >= buttonLeft && mouseX <= buttonRight && mouseY >= buttonUp && mouseY <= buttonDown);
}

bool util::readINI(const std::string& section, const std::string& key) {
	char buffer[255];
	GetPrivateProfileStringA(section.c_str(), key.c_str(), "FALSE", buffer, sizeof(buffer), ".\\CONFIG.ini");
	return (std::string(buffer) == "TRUE"); 
} 

UINT32 util::textAlign(const std::string& text, UINT32 posX) {
	int textLength = text.length();
	return posX - (textLength * 2.5f);
}

void util::Log(const std::string& message) {
	std::ofstream logFile("log.txt", std::ios_base::app);
	if (logFile.is_open()) {
		logFile << message << std::endl;
		logFile.close();
	}
}