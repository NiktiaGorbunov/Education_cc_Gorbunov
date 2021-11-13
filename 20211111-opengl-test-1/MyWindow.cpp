/*
 * MyWindow.cpp
 *
 *  Created on: 11 нояб. 2021 г.
 *      Author: Никита
 */

#include "MyWindow.h"
#include <cmath>
#include <chrono>
#include <ctime>

/*
 * 1. Дорисовать циферблат, сделав минутные/cекундные штрихи
 * 2. Добавить минутную и часовую стрелки
 * 3. Дорисовать часы. Часы должны представлять собой параллелепипед.
 * 		Боковые грани должны иметь свои цветы
 * 	4. Вся сцена должна медленно и плавно вращаться.
 */


MyWindow::MyWindow()
:Window(WINDDOW_WIDTH, WINDDOW_HEIGHT)
{
	SDL_SetWindowTitle(_window.get(), "My OpenGL Window");

}

void MyWindow::draw_clock() {
	for (double a = 0.0; a < 360.0; a += 360.0 / 12.0) {
		glPushMatrix();
		glRotated(a, 0.0, 0.0, 1.0);
		glTranslated(0.0, 0.9, 0);
		glBegin(GL_QUADS);
		glColor3d(0.3, 1.0, 1.0);
		glVertex2d(-0.05, 0.05);
		glVertex2d(0.05, 0.05);
		glVertex2d(0.05, -0.05);
		glVertex2d(-0.05, -0.05);
		glEnd();
		glPopMatrix();
	}
	//поворот стрелки
	double seconds_angle = fmod(_seconds, 60.0) / 60.0 * 360.0;
	glRotated(seconds_angle, 0.0, 0.0, -1.0);
	glBegin(GL_QUADS);
	glColor3d(1.0, 0.0, 0.0);
	glVertex2d(0.0, 0.0);
	glVertex2d(-0.025, 0.1);
	glVertex2d(0.0, 0.9);
	glVertex2d(0.025, 0.1);
	glEnd();
}

void MyWindow::render()
{


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	glLoadIdentity();

	gluLookAt(
			3.0, 3.0, 2.0,
			0.0, 0.0, 0.0,
			0.0, 0.0, 1.0);

	glBegin(GL_QUADS);

	//верх
	glColor3d(0.3, 0.3, 0.3);
	glVertex3d(-1.0, 1.0, 0.0);
	glVertex3d(1.0, 1.0, 0.0);
	glVertex3d(1.0, -1.0, 0.0);
	glVertex3d(-1.0, -1.0, 0.0);

	//низ
	glColor3d(0.2, 0.2, 0.2);
	glVertex3d(-1.0, 1.0, -0.1);
	glVertex3d(1.0, 1.0, -0.1);
	glVertex3d(1.0, -1.0, -0.1);
	glVertex3d(-1.0, -1.0, -0.1);


	glEnd();
	glTranslated(0.0, 0.0, 0.05);

	draw_clock();
}

void MyWindow::setupGL()
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.1f, 0.25f, 0.45f, 1.0f);

	double aspect_ratio = double(width()) / double(height());

	glMatrixMode(GL_PROJECTION);
//	gluOrtho2D(-aspect_ratio, +aspect_ratio, -1, 1);
	gluPerspective(45.0, aspect_ratio, 0.1, 20.0);
	glMatrixMode(GL_MODELVIEW);
}

void MyWindow::update()
{
	auto now = std::chrono::high_resolution_clock::now();
	auto tt = std::chrono::high_resolution_clock::to_time_t(now);
	auto local_time = *localtime(&tt);

	_seconds = local_time.tm_sec + 60*local_time.tm_min + 3600 * local_time.tm_hour;
}
