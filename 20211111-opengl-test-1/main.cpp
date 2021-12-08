/*
 * main.cpp
 *
 *  Created on: 11 нояб. 2021 г.
 *      Author: Никита
 */


#include <iostream>
#include <stdexcept>

#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>

//#include "MyWindow.h" задача с часами
#include "HouseWindow.h"  //домик


int main(int, char **)
{
	SDL_Init(SDL_INIT_EVERYTHING);
		try{
//			MyWindow w;   задача с часами
			HouseWindow w; //домик

			w.main_loop();
		}catch (const std::exception &e){
			std::cerr << "Произошла ошибка:\n" << e.what() << std::endl;
			exit(1);
		}

	return 0;
}
