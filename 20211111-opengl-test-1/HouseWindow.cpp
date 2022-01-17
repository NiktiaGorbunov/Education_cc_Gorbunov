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
	SDL_SetRelativeMouseMode(SDL_TRUE);
}

void HouseWindow::update() {
	_angle += 0.1;
}

void HouseWindow::render() {

	auto eye = _player.position();
	auto center = _player.center();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(eye.x, eye.y, eye.z,
			  center.x, center.y, center.z,
			  0.0, 0.0, 1.0);

	//сделаем небо
	glPushMatrix();
	glTranslated(eye.x, eye.y, eye.z);
	glDisable(GL_LIGHTING);
	glDisable(GL_FOG);
	Texture::enable();
	_stars_texture.bind();
	draw_sphere(32, 16, 100.0);
	glEnable(GL_LIGHTING);

	//сделаем луну
	GLfloat white[4] {1.f, 1.f, 1.f, 1.f};
	GLfloat black[4] {1.f, 1.f, 1.f, 1.f};

	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, white);
	glTranslated(12.f, 12.f, 90.f );
	glRotated(45.0, 0.0f, 1.0f, 0.0f);
	_moon_texture.bind();
	draw_sphere(8, 4, 3.0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, black);

	glEnable(GL_FOG);

	glPopMatrix();


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
	 *  где-то домики поставить
	 *  вокруг ёлки несколько снеговиков: 3 сферы, нос - конус, руки - цилиндры
	 *
	 */

	//снеговик
//	glDisable(GL_LIGHTING);
//	glEnable(GL_LIGHTING);



	glBegin(GL_QUADS);
	glNormal3d(0.0, 0.0, 1.0);
	for(int i = -150; i < 150; ++i){
		for(int j = -150; j <= 150; ++j){
				glVertex3d(j+0, j+0, 0.0);
				glVertex3d(j+1, j+0, 0.0);
				glVertex3d(j+1, j+1, 0.0);
				glVertex3d(j+0, j+1, 0.0);
			}
	}
	glEnd();


	glPushMatrix();
	glRotated(_angle, 0.0, 0.0, 1.0);

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
	glEnable(GL_FOG);

//	GLfloat fog_color[4]{0.3f, 0.3f, 0.3f, 1.0f};

	glFogf(GL_FOG_END , 70.f);
	glFogf(GL_FOG_DENSITY, 0.2f);
	glFogf(GL_FOG_MODE, GL_LINEAR);
//	glFogfv(GL_FOG_COLOR, fog_color);

	glClearColor(0.1f, 0.25f, 0.45f, 1.0f);

	double aspect_ratio = double(width()) / double(height());

	glMatrixMode(GL_PROJECTION);
	gluPerspective(45.0, aspect_ratio, 0.1, 120.0);
	glMatrixMode(GL_MODELVIEW);
}

void HouseWindow::handle_event(const SDL_Event &event)
{
	switch(event.type){
	case SDL_MOUSEMOTION:
		_player.turn_phi(-event.motion.xrel * Player::TURN_ANGLE);
		_player.turn_theta(event.motion.yrel * Player::TURN_ANGLE);
		break;
	case SDL_KEYDOWN:
		if (event.key.keysym.scancode == SDL_SCANCODE_F)
			_player.toggle_fly();
		break;

	}
}

void HouseWindow::handle_keys(const Uint8 *keys)
{
	if(keys[SDL_SCANCODE_W]) _player.move_forward();
	if(keys[SDL_SCANCODE_S]) _player.move_backward();
	if(keys[SDL_SCANCODE_A]) _player.move_left();
	if(keys[SDL_SCANCODE_D]) _player.move_right();
}
