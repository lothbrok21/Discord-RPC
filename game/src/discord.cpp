#include <chrono>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <include/main.h>
#include <util/include/util.h>
#include <discord-rpc/include/discord_register.h>
#include <discord-rpc/include/discord_rpc.h>

namespace Discord {
    std::string state;
    std::string details;
    int64_t startTimestamp = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    std::string largeImageKey;
    std::string largeImageText;
    std::string smallImageKey;
    std::string smallImageText;

    const char* userJob(int job) {
        switch (job) {
        case 0: return "fighter";
        case 1: return "defender";
        case 2: return "ranger";
        case 3: return "archer";
        case 4: return "mage";
        case 5: return "priest";
        }
        return "";
    }

    void Initialize() {
        DiscordEventHandlers handlers;
        Discord_Initialize("APPLICATION ID", &handlers, 1, nullptr);
    }

    void User() {
        const char* charName = reinterpret_cast<char*>(0x868DBE);
        UINT16* level = reinterpret_cast<UINT16*>(0x8655F8);
        UINT16* mapId = reinterpret_cast<UINT16*>(0x8666C4);
        UINT8* job = reinterpret_cast<UINT8*>(0x867D92);
        UINT32* kill = reinterpret_cast<UINT32*>(0x21FDEFC);

        std::ostringstream ossDetails;
        ossDetails << "Lv." << *level << " " << charName;
        details = ossDetails.str();

        std::ostringstream ossState;
        ossState << util::utf8_to_string(u8"Kill:") << *kill;
        state = ossState.str();

        largeImageText = "";
        largeImageKey = "rpc-image";
        smallImageKey = userJob(*job);
        smallImageText = "";
    }

    void Data() {
        DiscordRichPresence discordPresence;
        memset(&discordPresence, 0, sizeof(discordPresence));

        discordPresence.state = util::string_to_utf8(state);
        discordPresence.details = util::string_to_utf8(details);
        discordPresence.startTimestamp = startTimestamp;
        discordPresence.largeImageKey = util::string_to_utf8(largeImageKey);
        discordPresence.largeImageText = util::string_to_utf8(largeImageText);
        discordPresence.smallImageKey = util::string_to_utf8(smallImageKey);
        discordPresence.smallImageText = util::string_to_utf8(smallImageText);

        DiscordRichPresenceButton websiteButton = { .label = u8"Visit Website", .url = u8"https://your-website.com/" };
        DiscordRichPresenceButton discordButton = { .label = u8"Join Discord", .url = u8"https://discord.com/invite/" };

        discordPresence.buttons[0] = &websiteButton;
        discordPresence.buttons[1] = &discordButton;
        Discord_UpdatePresence(&discordPresence);
    }

    void Update() {
        while (true) {
            User();
            Data();
            Sleep(1000);
        }
    }
}

void hook::discord() {
    CreateThread(NULL, NULL, LPTHREAD_START_ROUTINE(Discord::Initialize), NULL, 0, 0);
    CreateThread(NULL, NULL, LPTHREAD_START_ROUTINE(Discord::Update), NULL, 0, 0);
}