#include <string>
#include "config.h" 
#include "game.hpp"


int main()
{
	Game *g = new Game();
	g->Init();
	return g->Run();
	return 0;
}