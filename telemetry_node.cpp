#include <iostream>
#include <windows.h>
#include "include/spatial_vectors.hpp"

// TPT: Telemetry Node v2.6
int main() {
    SetConsoleTitleA("Tactical Telemetry: Research Node");
    
    std::cout << "[SYSTEM] Initializing Spatial Data Bridge..." << std::endl;
    
    // Establishing bridge to tactical simulation
    if (!Spatial::ConnectToSimulation()) {
        std::cerr << "[!] Error: Simulation environment not detected." << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "[*] Monitoring Spatial Vectors and Input Sync..." << std::endl;
    
    while (true) {
        Spatial::ProcessEntityVectors();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    return 0;
}