#include <iostream>
#include <memory>

#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>

#include "WindowWithRectangles.h"



int main(int, char**)
{

	std::cout << "Program started!" << std::endl;
	SDL_Init(SDL_INIT_EVERYTHING);

	WindowWithRectangles window1;


	window1.main_loop();

	std::cout << "Program started!" << std::endl;

	return 0;
}
