/*
 * MyWindow.h
 *
 *  Created on: 11 ����. 2021 �.
 *      Author: ������
 */

#ifndef MYWINDOW_H_
#define MYWINDOW_H_

#include "Window.h"

class MyWindow: public Window {
public:
	static constexpr int WINDDOW_WIDTH = 1080;
	static constexpr int WINDDOW_HEIGHT = 720;

	virtual void update();
	virtual void render();
	virtual void setupGL();

protected:
	double _seconds {0.0};

	void draw_clock();

public:
	MyWindow();
	virtual ~MyWindow() = default;

};

#endif /* MYWINDOW_H_ */
