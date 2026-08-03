#pragma once

#include "Shroom/Event/Event.h"

// TODO use Shroom::StreamString 
#include <sstream>

namespace Shroom {

    class WindowCloseEvent : public Event {
    public:
        WindowCloseEvent() = default;

        EVENT_CLASS_TYPE(WindowClose);
        EVENT_CLASS_CATEGORY(CategoryApplication);
    };

    class WindowResizeEvent : public Event {
    public:
        WindowResizeEvent(const uint32 width, const uint32 height) : m_Width(width), m_Height(height) {}

        uint32 GetWidth() const { return m_Width; }
        uint32 GetHeight() const { return m_Height; }

        String ToString() const override {
            std::stringstream ss;
            ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
            return ss.str();
        }

        EVENT_CLASS_TYPE(WindowResize);
        EVENT_CLASS_CATEGORY(CategoryApplication);

    private:
        uint32 m_Width, m_Height;
    };

    class WindowFocusEvent : public Event {
    public:
        WindowFocusEvent() = default;

        EVENT_CLASS_TYPE(WindowFocus);
        EVENT_CLASS_CATEGORY(CategoryApplication);
    };

    class WindowLostFocusEvent : public Event {
    public:
        WindowLostFocusEvent() = default;

        EVENT_CLASS_TYPE(WindowLostFocus);
        EVENT_CLASS_CATEGORY(CategoryApplication);
    };

    class WindowMovedEvent : public Event {
    public:
        WindowMovedEvent(const uint32 x, const uint32 y) : m_X(x), m_Y(y) {}

        uint32 GetX() const { return m_X; }
        uint32 GetY() const { return m_Y; }

        String ToString() const override {
            std::stringstream ss;
            ss << "WindowMovedEvent: " << m_X << ", " << m_Y;
            return ss.str();
        }

        EVENT_CLASS_TYPE(WindowMoved);
        EVENT_CLASS_CATEGORY(CategoryApplication);

    private:
        uint32 m_X, m_Y;
    };

} // namespace Shroom
