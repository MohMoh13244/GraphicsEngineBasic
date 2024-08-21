/*
 *  GraphicsEngineBasic
 *  Author: Mohamad El mansour
 *  Version: 2023-11-09
 */


#ifndef LIGHT_HPP_
#define LIGHT_HPP_

#include <GL/glut.h>
#include "Shape.hpp"

class Light: public Shape {
public:
	GLfloat I, Rd; /* point light intensity and reflection diffusion */
	GLfloat size; /* radius of sphere to represent the size of light for rendering */
	GLboolean on;

	Light();
	void reset();
	void draw();
	void LightReset();
	void Increment(GLfloat, GLfloat, GLfloat);
};
#endif /* LIGHT_HPP_ */
