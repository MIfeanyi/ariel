#include <string>
#include "config.h"
#include "menustate.hpp"
#include "game.hpp"

Game g;
MenuState Menu;

int main()
{
	Menu.Init();
	g.Init();
	g.mStates.AddState(0,Menu);
	g.mStates.SwitchState(0);
	return g.Run();
}