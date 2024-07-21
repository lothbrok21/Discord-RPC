#pragma once
#include <string>

namespace util
{
    typedef void* Address;
    typedef void* Buffer;
    typedef unsigned char Byte;
    typedef void* Function;

    template<class Data>
    Data deserialize(Byte* buffer, int offset)
    {
        Data data{};
        memcpy(&data, &buffer[offset], sizeof(Data));
        return data;
    }
    int detour(Address addr, Function func, int size);
    int write_memory(Address addr, Function func, int size);
    int write_memory(Address addr, Byte value, int count);
    int jump(Address addr, Address destAddr, int size);
    const char8_t* string_to_utf8(const std::string& str);
    std::string utf8_to_string(const char8_t* utf8Chars);
    bool IsMouseInArea(UINT32 buttonLeft, UINT32 buttonRight, UINT32 buttonUp, UINT32 buttonDown, UINT32 mouseX, UINT32 mouseY);
    bool readINI(const std::string& section, const std::string& key);
    UINT32 textAlign(const std::string& text, UINT32 posX);
    void Log(const std::string& message);
}
