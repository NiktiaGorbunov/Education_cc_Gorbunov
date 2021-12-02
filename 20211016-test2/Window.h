/*
 * Window.h
 *
 *  Created on: 14 окт. 2021 г.
 *      Author: Никита
 */

#ifndef WINDOW_H_
#define WINDOW_H_

#include <memory>
#include <SDL2/SDL.h>



class Window
{
public:
	static constexpr int DEFAULT_HEIGHT = 700;
	static constexpr int DEFAULT_WIDTH = 700;

protected:
	std::shared_ptr<SDL_Window> _window;
	std::shared_ptr<SDL_Renderer> _renderer;
	int _width, _height;

public:
	Window(int w = DEFAULT_HEIGHT, int h = DEFAULT_WIDTH);
	virtual ~Window(){}

	virtual void handle_event(const SDL_Event &event){}
	virtual void handle_keys(const Uint8 *keys){}
	virtual void update() {}
	virtual void render() {}
	void main_loop();

	int height() const {
		return _height;
	}

	int width() const {
		return _width;
	}
};



#endif /* WINDOW_H_ */
