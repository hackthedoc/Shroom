#pragma once

#include "Shroom/Core/Types.h"

// TODO use Shroom::StreamString 
#include <sstream>

namespace Shroom {

    struct MouseMovedEvent {
        float32 X, Y;
    };

    struct MouseScrolledEvent {
        float32 XOffset, YOffset;
    };

    struct MouseButtonPressedEvent {
        int8 MouseCode;
    };

    struct MouseButtonReleasedEvent {
        int8 MouseCode;
    };

    inline String ToString(const MouseMovedEvent& e) {
        std::stringstream ss;
        ss << "MouseMovedEvent: " << e.X << ", " << e.Y;
        return ss.str();
    }

    inline String ToString(const MouseScrolledEvent& e) {
        std::stringstream ss;
        ss << "MouseScrolledEvent: " << e.XOffset << ", " << e.YOffset;
        return ss.str();
    }

    inline String ToString(const MouseButtonPressedEvent& e) {
        std::stringstream ss;
        ss << "MouseButtonPressedEvent: " << e.MouseCode;
        return ss.str();
    }

    inline String ToString(const MouseButtonReleasedEvent& e) {
        std::stringstream ss;
        ss << "MouseButtonReleasedEvent: " << e.MouseCode;
        return ss.str();
    }

} // namespace Shroom
