#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include <lucy/core/game.h>
#include <sandbox/sandbox_layer.h>

class SandboxGame : public Lucy::Game
{
public:
  SandboxGame(const std::string& name) : Game(name)
  {
    addLayer(new Sandbox::SandboxLayer{});
  }
};

std::unique_ptr<Lucy::Game> Lucy::createGame()
{
  return std::make_unique<SandboxGame>("Sandbox");
}
