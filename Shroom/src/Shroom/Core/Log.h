#pragma once

#include "Shroom/Core/Memory.h" 

#include <spdlog/spdlog.h>

namespace Shroom {

class Log {
public:
    static void Init();

    static Shared<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }

private:
    inline static Shared<spdlog::logger> s_CoreLogger;
};

} // namespace Shroom

#define SHROOM_CORE_INFO(...) ::Shroom::Log::GetCoreLogger()->info(__VA_ARGS__)
