/*
 * HouseWindow.cpp
 *
 *  Created on: 4 дек. 2021 г.
 *      Author: Никита
 */

#include "HouseWindow.h"
#include <memory>


HouseWindow::HouseWindow()
:Window (WINDOW_WIDTH, WINDOW_HEIGHT),
 _house_model("House.txt")
{
	SDL_SetWindowTitle(_window.get(), "House Window");
}

void HouseWindow::update() {
	_angle += 0.1;
}

void HouseWindow::render() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(6.0, 6.0, 4.5,
			  0.0, 0.0, 2.0,
			  0.0, 0.0, 1.0);
	glRotated(_angle, 0.0, 0.0, 1.0);

	Texture::disable();



//	_cylinder_texture.bind();
//	draw_prism(16, 1, 2); // рисование призмы
//	draw_cylinder(12, 1, 2); // рисование цилиндра
//	_cone_texture.bind();
//	draw_pyramid(24, 1, 2); //рисование квандрата
//	draw_cone(16, 1, 2); //рисованик консуа
//	_earth_texture.bind();
//	draw_disco_ball(16, 8, 2.0); // рисование диско-шара
//	draw_sphere(24, 8, 2.0);

// рисование текстурированного домика
//	_house_texture.bind();
//	_house_model.draw();

	/*
	 *  плосколсть / кривая повезрность белого цвета
	 *  в центре ёлка, ствол - цилиндр, ветки - конусы
	 *  вокруг ёлки несколько снеговиков: 3 сферы, нос - конус, руки - цилиндры
	 *
	 */

	//снеговик
//	glDisable(GL_LIGHTING);
//	glEnable(GL_LIGHTING);

	glBegin(GL_QUADS);
	glNormal3d(0.0, 0.0, 1.0);
	for(int i = -15; i < 15; ++i){
		for(int j = -15; j <= 15; ++j){
				glVertex3d(j+0, j+0, 0.0);
				glVertex3d(j+1, j+0, 0.0);
				glVertex3d(j+1, j+1, 0.0);
				glVertex3d(j+0, j+1, 0.0);
			}
	}
	glEnd();


	glPushMatrix();

	glTranslated(0.0, 0.0, 0.75);
	draw_sphere(16, 10, 1.0);
	glTranslated(0.0, 0.0, 1.25);
	draw_sphere(12, 8, 0.7);
	glTranslated(0.0, 0.0, 0.9);
	draw_sphere(10, 6, 0.4);
	glRotated(90.0, 0.0, 1.0, 0.0);
	draw_cone(8, 0.1, 1.0);
	glPopMatrix();
}

void HouseWindow::setupGL() {

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0); //отвечает за освещение

	glClearColor(0.1f, 0.25f, 0.45f, 1.0f);

	double aspect_ratio = double(width()) / double(height());

	glMatrixMode(GL_PROJECTION);
	gluPerspective(45.0, aspect_ratio, 0.1, 20.0);
	glMatrixMode(GL_MODELVIEW);
}
