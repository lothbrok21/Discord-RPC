#include "pch.h"
#include <time.h>
#include <chrono>

static int64_t eptime = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();

const char* Web = "www.yourwebsite.com";
const char* Logo = "logo";
const char* CharName = NULL;
int MapID = -1;
int Level = 0;
int Job = -1;



const char* getMapName(int MapID) {
    switch (MapID) {
    case 0: return "D-Water Borderland";
    case 1: return "Erina";
    case 2: return "Reikeuseu";
    case 3: return "D-Water Dungeon-1";
    case 4: return "D-Water Dungeon-1 Lich's Room";
    case 5: return "Cornwell's Ruin";
    case 6: return "Cornwell's Ruin (Asmodeus's Room)";
    case 7: return "Argilla Ruin";
    case 8: return "Argilla Ruin (Knight's Room)";
    case 9: return "D-Water Dungeon 2 Level 1";
    case 10: return "D-Water Dungeon 2 Level 2";
    case 11: return "Kimuraku Room";
    case 12: return "Cloron's Lair Level 1";
    case 13: return "Cloron's Lair level 2";
    case 14: return "Cloron's Lair level 3 - Cloron Dragon";
    case 15: return "Fantasma's Lair Level 1";
    case 16: return "Fantasma's Lair Level 2";
    case 17: return "Fantasma's Lair Level 3 - Fantasma Dragon";
    case 18: return "Proelium Frontier";
    case 19: return "Willieoseu";
    case 20: return "Keuraijen";
    case 21: return "Maitreyan";
    case 22: return "Maitreyan Level 2";
    case 23: return "Aidion Neckria";
    case 24: return "Aidion Neckria Level 2";
    case 25: return "Elimental Cave";
    case 26: return "Ruber Chaos";
    case 27: return "Ruber Chaos - Level 2";
    case 28: return "Adellia";
    case 29: return "Adeurian";
    case 30: return "Cantabilian";
    case 31: return "Temple of Pharos";
    case 32: return "Maze of Rapioru";
    case 33: return "Senechio Cave";
    case 34: return "Kalamus's House";
    case 35: return "Apulune";
    case 36: return "Iris";
    case 37: return "Cave of Stigma";
    case 38: return "Alurizen Ruin";
    case 39: return "Underground Stadium";
    case 40: return "Arena";
    case 41: return "Prison";
    case 42: return "Auction House";
    case 43: return "Skulleron";
    case 44: return "Astenes";
    case 45: return "Deep Desert-1";
    case 46: return "Deep Desert-2";
    case 47: return "Stable Erde";
    case 48: return "Cryptic One's Throne";
    case 49: return "Cryptic One's Throne";
    case 50: return "Guild Ranking Battle map (GRB)";
    case 51: return "Guild House";
    case 52: return "Guild House";
    case 53: return "Guild Management Office";
    case 54: return "Guild Management Office";
    case 55: return "Sky City Level 1";
    case 56: return "Sky City Level 2";
    case 57: return "Sky City Level 3";
    case 58: return "Seraphim Room";
    case 59: return "Senechio Cave 2";
    case 60: return "Elimental Cave 2";
    case 61: return "Cave of Stigma 2";
    case 62: return "Kalamus's House 2";
    case 63: return "Aurizen Ruin 2";
    case 64: return "Oblivio Insula";
    case 68: return "Valdemar Regnum";
    case 69: return "Palaion Regnum";
    case 70: return "Kanos Illium";
    }
    return "";
}

const char* getJob(int Job) {
    switch (Job) {
    case 0: return "fighter";
    case 1: return "defender";
    case 2: return "ranger";
    case 3: return "archer";
    case 4: return "mage";
    case 5: return "priest";
    }
    return "";
}

const char* getCharLevel(int Level) {
    switch (Level) {
    case 1: return "Lv.1";
    case 2: return "Lv.2";
    case 3: return "Lv.3";
    case 4: return "Lv.4";
    case 5: return "Lv.5";
    case 6: return "Lv.6";
    case 7: return "Lv.7";
    case 8: return "Lv.8";
    case 9: return "Lv.9";
    case 10: return "Lv.10";
    case 11: return "Lv.11";
    case 12: return "Lv.12";
    case 13: return "Lv.13";
    case 14: return "Lv.14";
    case 15: return "Lv.15";
    case 16: return "Lv.16";
    case 17: return "Lv.17";
    case 18: return "Lv.18";
    case 19: return "Lv.19";
    case 20: return "Lv.20";
    case 21: return "Lv.21";
    case 22: return "Lv.22";
    case 23: return "Lv.23";
    case 24: return "Lv.24";
    case 25: return "Lv.25";
    case 26: return "Lv.26";
    case 27: return "Lv.27";
    case 28: return "Lv.28";
    case 29: return "Lv.29";
    case 30: return "Lv.30";
    case 31: return "Lv.31";
    case 32: return "Lv.32";
    case 33: return "Lv.33";
    case 34: return "Lv.34";
    case 35: return "Lv.35";
    case 36: return "Lv.36";
    case 37: return "Lv.37";
    case 38: return "Lv.38";
    case 39: return "Lv.39";
    case 40: return "Lv.40";
    case 41: return "Lv.41";
    case 42: return "Lv.42";
    case 43: return "Lv.43";
    case 44: return "Lv.44";
    case 45: return "Lv.45";
    case 46: return "Lv.46";
    case 47: return "Lv.47";
    case 48: return "Lv.48";
    case 49: return "Lv.49";
    case 50: return "Lv.50";
    case 51: return "Lv.51";
    case 52: return "Lv.52";
    case 53: return "Lv.53";
    case 54: return "Lv.54";
    case 55: return "Lv.55";
    case 56: return "Lv.56";
    case 57: return "Lv.57";
    case 58: return "Lv.58";
    case 59: return "Lv.59";
    case 60: return "Lv.60";
    case 61: return "Lv.61";
    case 62: return "Lv.62";
    case 63: return "Lv.63";
    case 64: return "Lv.64";
    case 65: return "Lv.65";
    case 66: return "Lv.66";
    case 67: return "Lv.67";
    case 68: return "Lv.68";
    case 69: return "Lv.69";
    case 70: return "Lv.70";
    case 71: return "Lv.71";
    case 72: return "Lv.72";
    case 73: return "Lv.73";
    case 74: return "Lv.74";
    case 75: return "Lv.75";
    case 76: return "Lv.76";
    case 77: return "Lv.77";
    case 78: return "Lv.78";
    case 79: return "Lv.79";
    case 80: return "Lv.80";

    }
}


void Data() {
    Level = (int)*reinterpret_cast<short*>(0x8655F8);
    if (Level != 0) {
        CharName = reinterpret_cast<char*>(0x868DBE);
        MapID = (int)*reinterpret_cast<short*>(0x8666C4);
        Job = (int)*reinterpret_cast<short*>(0x867D92);
    }
    else
    {
        CharName = "Character Select Screen";
        MapID = -1;
        Job = -1;
    }
}



void Initialize()
{
    DiscordEventHandlers Handle;
    memset(&Handle, 0, sizeof(Handle));
    Discord_Initialize("774244560444456980", &Handle, 1, NULL); // Your RPC Client ID
}

void Update()
{
    DiscordRichPresence discordPresence;
    memset(&discordPresence, 0, sizeof(discordPresence));
    discordPresence.state = getMapName(MapID); // Map Name
    discordPresence.details = CharName; // Char Name
    discordPresence.startTimestamp = eptime; // Elapsed Time
    discordPresence.largeImageKey = Logo; // Big Image
    discordPresence.largeImageText = Web; // Big Image Text
    discordPresence.smallImageKey = getJob(Job); // Small Image
    discordPresence.smallImageText = getCharLevel(Level); // Small Image Text
    Discord_UpdatePresence(&discordPresence);
}

void UpdateData() {
    while (true) {
        Update();
        Data();
        Sleep(1000);
    }
}

void Discord() {
    CreateThread(NULL, NULL, LPTHREAD_START_ROUTINE(UpdateData), NULL, 0, 0);
    CreateThread(NULL, NULL, LPTHREAD_START_ROUTINE(Initialize), NULL, 0, 0);
}
