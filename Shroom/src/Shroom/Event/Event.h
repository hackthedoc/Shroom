#pragma once

#include "Shroom/Core/Types.h"

namespace Shroom {

    class Event {
    public:
        enum class Type {
            None = 0,
            WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
            AppTick, AppUpdate, AppRender,
            KeyPressed, KeyReleased, KeyTyped,
            MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled,
        };

        enum Category : int32 {
            CategoryNone = 0,
            CategoryApplication = 1 << 1,
            CategoryInput = 1 << 2,
            CategoryKeyboard = 1 << 3,
            CategoryMouse = 1 << 4,
            CategoryMouseButton = 1 << 5,
        };

        #define EVENT_CLASS_TYPE(type) static Type GetStaticType() { return Type::type; } \
                                    virtual Type GetEventType() const override { return GetStaticType(); } \
                                    virtual const char* GetName() const override { return #type; }
        
        #define EVENT_CLASS_CATEGORY(category) virtual int32 GetCategoryFlags() const override { return (category); }

    public:
        virtual ~Event() = default;

        virtual Type GetEventType() const = 0;
        virtual const char* GetName() const = 0;
        virtual int32 GetCategoryFlags() const = 0;

        virtual String ToString() const { return GetName(); }

        bool IsInCategory(Category category) {
            return GetCategoryFlags() & category;
        }

    public:
        bool Handled = false;
    };

    inline std::ostream& operator<<(std::ostream& os, const Event& e) {
        return os << e.ToString();
    }

    class EventDispatcher {
    public:
        explicit EventDispatcher(Event& event) : m_Event(event) {}

        template<typename EventType, typename EventFunction>
        bool Dispatch(const EventFunction& function) {
            if (m_Event.GetEventType() == EventType::GetStaticType()) {
                m_Event.Handled |= function(static_cast<EventType&>(m_Event));
                return true;
            }
            return false;
        }

    private:
        Event& m_Event;
    };

} // namespace Shroom
