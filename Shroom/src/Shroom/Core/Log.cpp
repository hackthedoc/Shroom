#include "Log.h"

#include <spdlog/common.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/spdlog-inl.h>

namespace Shroom {

void Log::Init() {
    // Config CoreLogger
    std::vector<spdlog::sink_ptr> coreSinks {
        Share<spdlog::sinks::stdout_color_sink_mt>(),
        Share<spdlog::sinks::rotating_file_sink_mt>("logs/shroom_core.log", 5 * 1024 * 1024, 3)    
    };
    coreSinks[0]->set_pattern("%^[%T] %n: %v%$");
    coreSinks[1]->set_pattern("[%T] [%l] %n: %v");

    s_CoreLogger = Share<spdlog::logger>("SHROOM", coreSinks.begin(), coreSinks.end());
    s_CoreLogger->set_level(spdlog::level::trace);
    s_CoreLogger->flush_on(spdlog::level::err);

    // Config ClientLogger
    std::vector<spdlog::sink_ptr> clientSinks {
        Share<spdlog::sinks::stdout_color_sink_mt>(),
        Share<spdlog::sinks::rotating_file_sink_mt>("logs/app.log", 5 * 1024 * 1024, 3)    
    };
    clientSinks[0]->set_pattern("%^[%T] %n: %v%$");
    clientSinks[1]->set_pattern("[%T] [%l] %n: %v");

    s_ClientLogger = Share<spdlog::logger>("SHROOM", clientSinks.begin(), clientSinks.end());
    s_ClientLogger->set_level(spdlog::level::trace);
    s_ClientLogger->flush_on(spdlog::level::err);

    // Register loggers
    spdlog::register_logger(s_CoreLogger);
    spdlog::register_logger(s_ClientLogger);

    SHROOM_CORE_INFO("Logger initialised");
}

} // namespace Shroom
