#include <iostream>
#include <string>
#include <vector>

#include <lucy/core/game.h>
#include <sandbox/sandbox_layer.h>

int main()
{
  Lucy::Game game;

  game.addLayer(new Sandbox::SandboxLayer{});

  game.start();

  game.run();

  game.shutdown();

  return 0;
}
