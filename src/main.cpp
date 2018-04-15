#include <string>
#include "config.h"
#include "ariel.hpp"
#include "menustate.hpp"
#include "game.hpp"

Ariel::App Game; 
MenuState Menu;

int main(){
  Menu.Init();
  Menu.SetName("Menu");
  Game.Init("Ariel",640,480,false);
  Game.MState.AddState(Menu);
  Game.MState.SwitchState("Menu");
  Game.Run();
  return 0;
}