#include <string>
#include "config.h"
#include "ariel.hpp"
#include "menustate.hpp"
#include "game.hpp"



Game g;

int main()
{
	g.Init();
	return g.Run();
}