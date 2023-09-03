#include <iostream>
#include <string>
#include <vector>

#include <lucy/core/game.h>



int main()
{    
  Lucy::Game game;

  game.start();

  game.run();

  game.shutdown();

  return 0; 
} 
