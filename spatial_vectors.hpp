#pragma once
#include <vector>

namespace Spatial {
    struct Vector3 { float x, y, z; };
    
    bool ConnectToSimulation();
    void ProcessEntityVectors();
    
    // Predictive logic for trajectory analysis
    inline Vector3 PredictFuturePosition(Vector3 pos, Vector3 velocity, float time) {
        return { pos.x + velocity.x * time, pos.y + velocity.y * time, pos.z + velocity.z * time };
    }
}