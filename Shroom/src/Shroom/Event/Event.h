#pragma once

#include "Shroom/Core/Types.h"

#include "Shroom/Event/ApplicationEvents.h"
#include "Shroom/Event/KeyEvents.h"
#include "Shroom/Event/MouseEvents.h"
#include "Shroom/Event/WindowEvents.h"

#include <ostream>
#include <variant>

namespace Shroom {

    enum class EventCategory : uint32 {
        None = 0,
        Application = 1u << 0,
        Input = 1u << 1,
        Keyboard = 1u << 2,
        Mouse = 1u << 3,
        MouseButton = 1u << 4,
    };

    constexpr EventCategory operator|(EventCategory a, EventCategory b) {
        return static_cast<EventCategory>(static_cast<uint32>(a) | static_cast<uint32>(b));
    }

    constexpr uint32 operator&(EventCategory a, EventCategory b) {
        return static_cast<uint32>(a) & static_cast<uint32>(b);
    }

    using EventVariant = std::variant<
        AppTickEvent, AppUpdateEvent, AppRenderEvent,
        WindowCloseEvent, WindowResizeEvent, WindowFocusEvent, WindowLostFocusEvent, WindowMovedEvent,
        KeyPressedEvent, KeyReleasedEvent, KeyTypedEvent,
        MouseMovedEvent, MouseScrolledEvent, MouseButtonPressedEvent, MouseButtonReleasedEvent
    >;

    class Event {
    public:
        Event(EventVariant data, EventCategory categories) : m_Data(std::move(data)), m_Categories(categories) {}
    
        template<typename T>
        bool Is() const { return std::holds_alternative<T>(m_Data); }

        template<typename T>
        T& Get() { return std::get<T>(m_Data); }

        template<typename T>
        const T& Get() const { return std::get<T>(m_Data); }

        bool IsInCategory(EventCategory category) const {
            return (m_Categories | category) != EventCategory::None;
        }

        String ToString() const {
            return std::visit([](auto&& e) { return Shroom::ToString(e); }, m_Data);
        }

        const EventVariant Data() const { return m_Data; }

        bool Handled = false;
    
    private:
        EventVariant m_Data;
        EventCategory m_Categories;
    };

    class EventDispatcher {
    public:
        explicit EventDispatcher(Event& event) : m_Event(event) {}  

        template<typename T, typename Func>
        bool Dispatch(Func&& func) {
            if (m_Event.Is<T>()) {
                m_Event.Handled |= func(m_Event.Get<T>());
                return true;
            }
            return false;
        }

    private:
        Event& m_Event;
    };

    inline std::ostream& operator<<(std::ostream& os, const Event& e) {
        return os << e.ToString();
    }

} // namespace Shroom
