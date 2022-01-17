/*
 * HouseWindow.h
 *
 *  Created on: 4 дек. 2021 г.
 *      Author: Никита
 */

#ifndef HOUSEWINDOW_H_
#define HOUSEWINDOW_H_

#include "Window.h"
#include "Model.h"
#include "Texture.h"
#include "Primitives.h"
#include "Player.h"


class HouseWindow: public Window {
private:
	Model _house_model;
	Texture _house_texture {"house_texture.png"};
	Texture _cylinder_texture {"cylinder_template.png"};
	Texture _cone_texture {"con_template.png"};
	Texture _earth_texture {"earth_daymap.jpg"};
	Texture _stars_texture {"stars.jpg"};
	Texture _moon_texture {"moon.jpg"};

	double _angle = 0.0;
	Player _player {glm::vec3(3.f, 3.f, 3.0f), 0.f, 1.6f};


public:
	static constexpr int WINDOW_WIDTH = 1080;
	static constexpr int WINDOW_HEIGHT = 720;

	virtual void handle_keys(const Uint8 *keys);
	virtual void handle_event(const SDL_Event &event) override;
	virtual void update() override;
	virtual void render() override;
	virtual void setupGL() override;


public:
	HouseWindow();
	virtual ~HouseWindow() = default;
};

#endif /* HOUSEWINDOW_H_ */
