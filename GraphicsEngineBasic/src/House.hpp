/*
 *  GraphicsEngineBasic
 *  Author: Mohamad El mansour
 *  Version: 2023-11-09
 */

#ifndef HOUSE_HPP_
#define HOUSE_HPP_

#include <GL/glut.h>

#include "Cube.hpp"
#include "Pyramid.hpp"


class House: public Shape{
protected:
	Pyramid* pyramid;
	Cube* cube;

public:
	~House();
	House();
	void draw();
};



#endif /* House_HPP_ */
