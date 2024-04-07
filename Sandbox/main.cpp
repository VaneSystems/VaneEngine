#include <iostream>

#include <Vane/Core/Application.hpp>
#include <Vane/Core/Logger.hpp>
#include <Vane/Platform/Platform.hpp>
#include <Vane/EntryPoint.hpp>

class Game : public Vane::Application {
public:
    Game(const Vane::ApplicationConfig &config) :
        Vane::Application(config) {}

    void onInit() override { VDEBUG("game Initialized 2"); }

    void onShutdown() override { VDEBUG("onShutdown called..."); }

    void onUpdate(f32 ms) override {
        // VDEBUG("onUpdate called...");
    }
};

Vane::Application *Vane::CreateApplication(int argc, char **argv) {
    const ApplicationConfig config = {
            .startPosX = 100,
            .startPosY = 100,
            .windowWidth = 500,
            .windowHeight = 500,
            .name = "Vane Sandbox",
    };

    const auto app = new Game(config);

    return app;
}
