#include "Log.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace Shroom {

void Log::Init() {
    s_CoreLogger = spdlog::stdout_color_mt("SHROOM");
    s_CoreLogger->set_pattern("%^[%T] %n: %v%$");
}

} // namespace Shroom
