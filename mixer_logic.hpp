#pragma once
#include <vector>

namespace Audio {
    bool InitializeBridge();
    bool CheckGlobalHotkeys();
    void StreamSampleToBuffer(const char* filePath);

    // Advanced normalization logic
    inline float NormalizeGain(float inputLevel, float targetDb) {
        float ratio = pow(10, (targetDb / 20.0f));
        return inputLevel * ratio;
    }
}
