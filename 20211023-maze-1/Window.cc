/*
 * Window.cc
 *
 *  Created on: 14 окт. 2021 г.
 *      Author: Ќикита
 */

#include "Window.h"
#include <stdexcept>

Window::Window(int w, int h)
: _width(w), _height(h)
{

	_window = std::shared_ptr<SDL_Window>(
				SDL_CreateWindow("SDL Windows", SDL_WINDOWPOS_CENTERED_DISPLAY(1),
						SDL_WINDOWPOS_CENTERED_DISPLAY(1), w, h,
						SDL_WINDOW_SHOWN), SDL_DestroyWindow);
		if (_window == nullptr) {
			throw std::runtime_error(
					std::string("Ќе могу создать окно: ")+
					std::string(SDL_GetError()));

		}

	_renderer = std::shared_ptr<SDL_Renderer>(
			SDL_CreateRenderer(_window.get(), -1,
			SDL_RENDERER_ACCELERATED| SDL_RENDERER_PRESENTVSYNC),
			SDL_DestroyRenderer);

	if (_renderer == nullptr) {
		throw std::runtime_error(
				std::string("Ќе могу создать рендерер: ")+
				std::string(SDL_GetError()));

	}
}

void Window::main_loop() {

	auto keys = SDL_GetKeyboardState(nullptr);
	SDL_Event event;
	for (;;) {
		//обработка событий
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				return;
			if (event.type==SDL_KEYDOWN){
				switch (event.key.keysym.scancode){
				case SDL_SCANCODE_ESCAPE:return;
				default:
					;
				}
			}
			handle_event(event);
		}

		handle_keys(keys);

		//изменени€ состо€ни€ событий
		update();

		//отображение текущего состо€ни€
		render();
		SDL_RenderPresent(_renderer.get());

	}
}

