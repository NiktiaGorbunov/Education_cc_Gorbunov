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


class HouseWindow: public Window {
private:
	Model _house_model;
	Texture _house_texture {"house_texture.png"};
	double _angle = 0.0;
public:
	static constexpr int WINDOW_WIDTH = 1080;
	static constexpr int WINDOW_HEIGHT = 720;

	virtual void update() override;
	virtual void render() override;
	virtual void setupGL() override;

public:
	HouseWindow();
	virtual ~HouseWindow() = default;
};

#endif /* HOUSEWINDOW_H_ */
