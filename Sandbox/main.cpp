#include <iostream>

#include <Core/Application.hpp>
#include <Core/Logger.hpp>
#include <Platform/Platform.hpp>
#include <EntryPoint.hpp>

class Game : public Vane::Application {
public:
    Game(const Vane::ApplicationConfig& config) : Vane::Application(config) {}

    void onInit() override {
        VDEBUG("game Initialized 2");
    }

    void onShutdown() override {
        VDEBUG("onShutdown called...");
    }

    void onUpdate(f32 ms) override {
        // VDEBUG("onUpdate called...");
    }
};

Vane::Application* Vane::CreateApplication(int argc, char** argv) {
    ApplicationConfig config;
    config.name = "Vane Sandbox";
    config.windowHeight = 500;
    config.windowWidth = 500;
    config.startPosX = 100;
    config.startPosY = 100;

    auto app = new Game(config);

    return app;
}
