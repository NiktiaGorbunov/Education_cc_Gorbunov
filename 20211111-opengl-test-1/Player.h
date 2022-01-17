/*
 * Player.h
 *
 *  Created on: 17 янв. 2022 г.
 *      Author: Никита
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <glm/glm.hpp>
#include "Primitives.h"

class Player
{
public:
	static constexpr float DEFAULT_DISTANCE = 0.1;
	static constexpr float TURN_ANGLE = 0.0025;

protected:
	glm::vec3 _position {};
	float     _phi; //горизонтальный угол поворота
	float     _theta; //вертикальный угол наклона
	bool      _fly; //режим полета


public:
	Player(const glm::vec3 start, float phi, float theta)
	: _position(start), _phi(phi), _theta(theta), _fly(false){}

	virtual ~Player() = default;

	inline auto &position() const {return _position;}
	inline auto center() const
	{
		return position() + sph2cart(glm::vec3(1.0f, _phi, _theta)); //точка наблюдателя + вектор взгляда
	}

	bool fly_enabled() const {return _fly;}
	bool set_fly (bool mode) { _fly = mode; }
	void toggle_fly() {_fly = not _fly;}

	void move_forward(float dist = DEFAULT_DISTANCE);
	void move_backward(float dist = DEFAULT_DISTANCE);
	void move_left(float dist = DEFAULT_DISTANCE);
	void move_right(float dist = DEFAULT_DISTANCE);
	void turn_phi (float angle);
	void turn_theta (float angle);

};

#endif /* PLAYER_H_ */
