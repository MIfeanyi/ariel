#include <string>
#include "config.h" 
#include "game.hpp"

Game g;

int main()
{
	g.Init();
	return g.Run();
}