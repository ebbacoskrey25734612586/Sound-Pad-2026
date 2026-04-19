#include <iostream>
#include <windows.h>
#include "include/wasapi_handler.hpp"

// ASO: Virtual Audio Injector Node
int main() {
    SetConsoleTitleA("Acoustic Orchestrator: Signal Bridge");
    
    std::cout << "[SYSTEM] Initializing Virtual Audio Driver..." << std::endl;
    
    if (!Audio::InitializeBridge()) {
        std::cerr << "[!] Error: Virtual device not found. Please reinstall drivers." << std::endl;
        return 1;
    }

    std::cout << "[SUCCESS] Audio bridge active. Awaiting hotkey trigger..." << std::endl;

    while (true) {
        if (Audio::CheckGlobalHotkeys()) {
            Audio::StreamSampleToBuffer("sample_01.wav");
        }
        Sleep(10);
    }
    return 0;
}
