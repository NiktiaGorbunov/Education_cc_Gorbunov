/*
 * BirdWindow.cpp
 *
 *  Created on: 16 окт. 2021 г.
 *      Author: Никита
 */
#include <cmath>

#include "BirdWindow.h"


BirdWindow::BirdWindow()
:	Window(BIRD_WINDOW_WIDTH, BIRD_WINDOW_HEIGHT),
	_bird(_renderer, "bird.png"),
	_eagle(_renderer, "eagle.png"),
	_oblako(_renderer, "oblako.png"),
	_sun(_renderer, "sun.png"),
	_background(_renderer, "bg.png"),
	_mountains(_renderer, "mountains.png", 2.0),
	_mountain(_renderer, "mountains2.png", 5.0),
	_mount(_renderer, "mount.png", 7.0)
{
	SDL_SetWindowTitle(_window.get(), "Bird");

	sun_x=0.0;
	sun_y=10.0;

	eagle_x = 50.0;
	eagle_y = 250.0;

	for(unsigned i=0; i<5; ++i)
		phase[i] = 0.0;
}

void BirdWindow::render()
{
	SDL_SetRenderDrawColor(_renderer.get(), 63, 192, 255,255);

	_background.draw(0, 0);
	_mountains.draw(0, 600 - _mountains.height(), width(), _mountains.height());
	_mountain.draw(0, 600 - _mountain.height(), width(), _mountain.height());
	_mount.draw(0, 620 - _mount.height(), width(), _mount.height());
	_sun.draw(sun_x, sun_y);
	_eagle.draw(eagle_x, eagle_y);

	for (unsigned i =0; i<3; ++i)
			_oblako.draw(clouds[i]);

	for (unsigned i =0; i<6; ++i)
				_oblako.draw(clouds[i]);

	for(unsigned i =0; i<5; ++i)
			_bird.draw(birds[i]);

}

void BirdWindow::handle_keys(const Uint8 *keys)
{
	if (keys[SDL_SCANCODE_RIGHT]) eagle_x  += 4;
	if (keys[SDL_SCANCODE_LEFT]) eagle_x  -= 4;
	if (keys[SDL_SCANCODE_DOWN]) eagle_y  += 4;
	if (keys[SDL_SCANCODE_UP]) eagle_y  -= 4;

}

void BirdWindow::update()
{
	auto pi = acos(-1.0);

	if(eagle_x >= width())
			eagle_x = 0 - _eagle.width() ;

	for (unsigned i=0; i<5; ++i){
		phase[i] += pi*(i-0.5) / 90.0;

		birds[i].x += 4.0*(i+0.5);

		if (birds[i].x >= width()) birds[i].x = - width();

		if(i<2)	birds[i].y = height() / 2 * (1 + 0.3*(i+1) * sin(phase[i])) - height() / 4;
		else birds[i].y = height() / 2 * (1 + 0.3*(i-0.5) * sin(phase[i])) - height() / 4;
	}

	for (unsigned i = 0; i < 6; ++i) {
		clouds[i].x -= clouds[i].w / 32;

		if (clouds[i].x <= - clouds[i].w) clouds[i].x = width();
	}

	sun_x+=1.0;
	if(sun_x>=width()) sun_x = 0 - _sun.width();

	_mountains.update();
	_mountain.update();
	_mount.update();
}
