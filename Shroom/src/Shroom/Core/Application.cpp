#include "Application.h"

namespace Shroom {

Application::Application() {
    SHROOM_CORE_INFO("Application created");
}

Application::~Application() {
    SHROOM_CORE_INFO("Application destroyed");
}

void Application::Run() {
    SHROOM_CORE_INFO("Application running");
}

} // namespace Shroom
