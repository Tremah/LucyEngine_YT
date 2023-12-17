#pragma once

#include <vector>
#include <memory>

#include <lucy/core/window.h>
#include <lucy/core/layer.h>

namespace Lucy
{
  class Game
  {
  public:
    Game(const std::string name) : name_{name} {}

    //Setup glfw, glad and create the window
    void start();

    //Run the main loop until the window is closed (ESC or close button)
    void run();

    //Destroy the window
    void shutdown();

    void addLayer(Layer* layer);

  private:
    bool running_ = false;
    std::string name_{};
    Window window_{1600, 900, "LucyEngine"};

    std::vector<Layer*> layers_; 


  };

  std::unique_ptr<Game> createGame();
}
