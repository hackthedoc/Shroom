#pragma once

#include "Shroom/Core/Types.h"

// TODO use Shroom::StreamString 
#include <sstream>

namespace Shroom {

    struct WindowCloseEvent {};
    struct WindowFocusEvent {};
    struct WindowLostFocusEvent {};

    struct WindowResizeEvent { 
        uint32 Width, Height;
    };

    struct WindowMovedEvent {
        int32 X, Y; // multiple monitor setups can put the window at negative coords relative to the primary monitor
    };

    inline String ToString(const WindowCloseEvent&) { return "WindowCloseEvent"; }
    inline String ToString(const WindowFocusEvent&) { return "WindowFocusEvent"; }
    inline String ToString(const WindowLostFocusEvent&) { return "WindowLostFocusEvent"; }

    inline String ToString(const WindowResizeEvent& e) {
        std::stringstream ss;
        ss << "WindowResizeEvent: " << e.Width << ", " << e.Height;
        return ss.str();
    }

    inline String ToString(const WindowMovedEvent& e) { 
        std::stringstream ss;
        ss << "WindowMovedEvent: " << e.X << ", " << e.Y;
        return ss.str();
    }

} // namespace Shroom
