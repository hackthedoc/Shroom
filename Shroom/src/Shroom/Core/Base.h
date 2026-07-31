#pragma once

#include "Shroom/Core/Types.h"
#include "Shroom/Core/Memory.h"

// Engine Version

#define SHROOM_VERSION_MAJOR 0
#define SHROOM_VERSION_MINOR 1
#define SHROOM_VERSION_PATCH 0

// Utility Macros

#define SHROOM_EXPAND_MACRO(x) x
#define SHROOM_STRINGIFY_MACRO(x) #x
#define SHROOM_STRINGIFY(x) SHROOM_STRINGIFY_MACRO(x)

#define SHROOM_BIND_EVENTS(fn) [this](auto&&... args)->decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

// Utility Files

#include "Shroom/Core/Log.h"
