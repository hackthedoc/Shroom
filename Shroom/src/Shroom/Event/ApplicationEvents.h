#pragma once

#include "Shroom/Core/Types.h"

namespace Shroom {

    struct AppTickEvent {};
    struct AppUpdateEvent {};
    struct AppRenderEvent {};

    inline String ToString(const AppTickEvent&) { return "AppTickEvent"; }
    inline String ToString(const AppUpdateEvent&) { return "AppUpdateEvent"; }
    inline String ToString(const AppRenderEvent&) { return "AppRenderEvent"; }

} // namespace Shroom
