/*
 * main.cc
 *
 *  Created on: 14 окт. 2021 г.
 *      Author: Никита
 */


#include <iostream>
#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>

#include "BirdWindow.h"


int main(int, char**)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	BirdWindow window1;

	std::cout <<"Program started!" << std::endl;

	window1.main_loop();

	std::cout <<"Program ended!" << std::endl;

	return 0;
}

