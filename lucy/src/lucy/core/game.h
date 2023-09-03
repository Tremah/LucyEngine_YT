#pragma once

#include <lucy/core/window.h>

namespace Lucy
{
  class Game
  {
  public:
    //Setup glfw, glad and create the window
    void start();

    //Run the main loop until the window is closed (ESC or close button)
    void run();

    //Destroy the window
    void shutdown();

  private:
    bool running_ = false;
    Window window_{1600, 900, "LucyEngine"};


  };
}
