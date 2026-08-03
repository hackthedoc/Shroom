#pragma once

#include "Shroom/Event/Event.h"

// TODO use Shroom::StreamString 
#include <sstream>

namespace Shroom {

    class MouseMovedEvent : public Event {
    public:
        MouseMovedEvent(const float32 x, const float32 y) : m_X(x), m_Y(y) {}

        inline float32 GetX() const { return m_X; }
        inline float32 GetY() const { return m_Y; }

        String ToString() const override {
            std::stringstream ss;
            ss << "MouseMovedEvent: " << m_X << ", " << m_Y;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(CategoryMouse | CategoryInput)

    private:
        float32 m_X, m_Y;
    };

    class MouseScrolledEvent : public Event {
    public:
        MouseScrolledEvent(const float32 xOffset, const float32 yOffset) : m_XOffset(xOffset), m_YOffset(yOffset) {}

        inline float32 GetXOffset() const { return m_XOffset; }
        inline float32 GetYOffset() const { return m_YOffset; }

        String ToString() const override {
            std::stringstream ss;
            ss << "MouseScrolledEvent: " << m_XOffset << ", " << m_YOffset;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(CategoryMouse | CategoryInput)

    private:
        float32 m_XOffset, m_YOffset;
    };

    class MouseButtonEvent : public Event {
    public:
        int8 GetMouseCode() const { return m_MouseCode; }

        EVENT_CLASS_CATEGORY(CategoryMouseButton | CategoryInput);

    protected:
        explicit MouseButtonEvent(const int8 mousecode) : m_MouseCode(mousecode) {}
    
    protected:
        int8 m_MouseCode;
    };

    class MouseButtonPressedEvent : public MouseButtonEvent {
    public:
        MouseButtonPressedEvent(const int8 mousecode) : MouseButtonEvent(mousecode) {}

        String ToString() const override {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << m_MouseCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    class MouseButtonReleasedEvent : MouseButtonEvent {
    public:
        MouseButtonReleasedEvent(const int8 mousecode) : MouseButtonEvent(mousecode) {}

        String ToString() const override {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent: " << m_MouseCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyReleased)
    };

} // namespace Shroom
