#include <Shroom.h>
#include <Shroom/Core/EntryPoint.h>

class SandboxApp : public Shroom::Application {};

Shroom::Application* CreateApplication() {
    return new SandboxApp();
}
