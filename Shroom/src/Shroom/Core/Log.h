#pragma once

#include "Shroom/Core/Memory.h" 

#include <spdlog/spdlog.h>

namespace Shroom {

class Log {
public:
    static void Init();

    static Shared<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
    static Shared<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

private:
    inline static Shared<spdlog::logger> s_CoreLogger;
    inline static Shared<spdlog::logger> s_ClientLogger;
};

} // namespace Shroom

#define SHROOM_CORE_TRACE(...) ::Shroom::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SHROOM_CORE_INFO(...) ::Shroom::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SHROOM_CORE_WARN(...) ::Shroom::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SHROOM_CORE_ERROR(...) ::Shroom::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SHROOM_CORE_CRITICAL(...) ::Shroom::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define SHROOM_TRACE(...) ::Shroom::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SHROOM_INFO(...) ::Shroom::Log::GetClientLogger()->info(__VA_ARGS__)
#define SHROOM_WARN(...) ::Shroom::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SHROOM_ERROR(...) ::Shroom::Log::GetClientLogger()->error(__VA_ARGS__)
