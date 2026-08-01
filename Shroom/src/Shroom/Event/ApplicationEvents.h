#pragma once

#include "Shroom/Event/Event.h"

namespace Shroom {

    class ApplicationTickEvent : public Event {
    public:
        ApplicationTickEvent() = default;

        EVENT_CLASS_TYPE(AppTick);
        EVENT_CLASS_CATEGORY(CategoryApplication);
    };

    class ApplicationUpdateEvent : public Event {
    public:
        ApplicationUpdateEvent() = default;

        EVENT_CLASS_TYPE(AppUpdate);
        EVENT_CLASS_CATEGORY(CategoryApplication);
    };

    class ApplicationRenderEvent : public Event {
    public:
        ApplicationRenderEvent() = default;

        EVENT_CLASS_TYPE(AppRender);
        EVENT_CLASS_CATEGORY(CategoryApplication);
    };

} // namespace Shroom
