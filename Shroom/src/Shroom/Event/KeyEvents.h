#pragma once

#include "Shroom/Event/Event.h"

// TODO use Shroom::StreamString 
#include <sstream>

namespace Shroom {

    class KeyEvent : public Event {
    public:
        int32 GetKeyCode() const { return m_KeyCode; }

        EVENT_CLASS_CATEGORY(CategoryKeyboard | CategoryInput);

    protected:
        explicit KeyEvent(const int32 keycode) : m_KeyCode(keycode) {}
    
    protected:
        int32 m_KeyCode;
    };

    class KeyPressedEvent : public KeyEvent {
    public:
        KeyPressedEvent(const int32 keycode, const bool isRepeat = false) : KeyEvent(keycode), m_IsRepeat(isRepeat) {}

        inline bool IsRepeat() const { return m_IsRepeat; }

        String ToString() const override {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_KeyCode << "(repeats = " << m_IsRepeat << ")";
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyPressed)

    private:
        bool m_IsRepeat;
    };

    class KeyReleasedEvent : KeyEvent {
    public:
        KeyReleasedEvent(const int32 keycode) : KeyEvent(keycode) {}

        String ToString() const override {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << m_KeyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyReleased)
    };

    class KeyTypedEvent : KeyEvent {
    public:
        KeyTypedEvent(const int32 keycode) : KeyEvent(keycode) {}

        String ToString() const override {
            std::stringstream ss;
            ss << "KeyTypedEvent: " << m_KeyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyTyped)
    };

} // namespace Shroom
