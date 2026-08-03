#pragma once

#include "Shroom/Core/Types.h"

// TODO use Shroom::StreamString 
#include <sstream>

namespace Shroom {

    struct KeyPressedEvent {
        int32 KeyCode;
        bool Repeat = false;
    };

    struct KeyReleasedEvent {
        int32 KeyCode;
    };

    struct KeyTypedEvent {
        uint32 Codepoint; // decoded unicode codepoint
    };

    inline String ToString(const KeyPressedEvent& e) {
        std::stringstream ss;
        ss << "KeyPressedEvent: " << e.KeyCode << " (repeat = " << e.Repeat << ")";
        return ss.str();
    }

    inline String ToString(const KeyReleasedEvent& e) {
        std::stringstream ss;
        ss << "KeyReleasedEvent: " << e.KeyCode;
        return ss.str();
    }

    inline String ToString(const KeyTypedEvent& e) {
        std::stringstream ss;
        ss << "KeyTypedEvent: " << e.Codepoint;
        return ss.str();
    }

} // namespace Shroom
