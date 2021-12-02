/*
 * BirdWindow.h
 *
 *  Created on: 16 окт. 2021 г.
 *      Author: Никита
 */

#ifndef BIRDWINDOW_H_
#define BIRDWINDOW_H_

#include "Window.h"
#include "Texture.h"
#include "LayerTexture.h"

class BirdWindow final: public Window{
private:
	Texture _bird;
	Texture _eagle;
	Texture _oblako;
	Texture _sun;
	Texture _background;

	LayerTexture _mountains;
	LayerTexture _mountain;
	LayerTexture _mount;


//	int x, y, w, h;
	double sun_x, sun_y;
	double phase[5];
	double eagle_x, eagle_y;
	static constexpr int BIRD_WINDOW_WIDTH = 800;
	static constexpr int BIRD_WINDOW_HEIGHT = 600;

	SDL_FRect birds[5] {
					{10.0, 20.0, 50.0, 50.0},
					{500.0, 400.0, 50.0, 50.0},
					{150.0, 200.0, 50.0, 50.0},
					{350.0, 108.0, 50.0, 50.0},
					{120.0, 50.0, 50.0, 50.0},
				};

	SDL_FRect clouds[6]{
			{128.0, 200.0, 128.0, 64.0},
			{356.0, 430.0, 192.0, 70.0},
			{500.0, 340.0, 1.0, 90.0},
			{50.0, 20.0, 384.0, 192.0},
			{200.0, 179.0, 480.0, 200.0},
			{20.0, 20.0, 500.0, 300.0},
	};




public:
	BirdWindow();
	virtual ~BirdWindow() = default;

	virtual void render() override;
	virtual void handle_keys(const Uint8 *keys) override;
	virtual void update() override;
};

#endif /* BIRDWINDOW_H_ */
