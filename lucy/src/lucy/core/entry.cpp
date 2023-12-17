#include <lucy/core/game.h>

int main()
{
  auto game = Lucy::createGame();
  
  game->start();

  game->run();

  game->shutdown();

  return 0;
}