/*
 * mian.cc
 *
 *  Created on: 23 окт. 2021 г.
 *      Author: Никита
 */

#include <iostream>
#include <stdexcept>
#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>

#include "MazeWindow.h"


int main(int, char**)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	try{
		MazeWindow w;
		w.main_loop();

	}catch(const std::exception &e){
		std::cerr <<"Произошла ошибка:\n"<< e.what()<<std::endl;
		return 1;
	}catch(...){
		std::cerr << "Произошла неизвестная ошибка!" << std::endl;
		return 1;
	}
	return 0;
}


