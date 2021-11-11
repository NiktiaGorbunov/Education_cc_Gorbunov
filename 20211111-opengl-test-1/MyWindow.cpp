/*
 * MyWindow.cpp
 *
 *  Created on: 11 нояб. 2021 г.
 *      Author: Никита
 */

#include "MyWindow.h"

MyWindow::MyWindow()
:Window(WINDDOW_WIDTH, WINDDOW_HEIGHT)
{
	SDL_SetWindowTitle(_window.get(), "My OpenGL Window");

}

void MyWindow::render()
{
	glClear(GL_COLOR_BUFFER_BIT);


	glBegin(GL_TRIANGLES);
	glVertex2d(0.0, 0.9);
	glVertex2d(0.9, -0.9);
	glVertex2d(-0.9, -0.9);
	glEnd();
}

void MyWindow::setupGL()
{
	glClearColor(0.1f, 0.25f, 0.45f, 1.0f);
}
