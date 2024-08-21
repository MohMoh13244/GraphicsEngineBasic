/*
 *  GraphicsEngineBasic
 *  Author: Mohamad El mansour
 *  Version: 2023-11-09
 */

#ifndef SPHERE_H
#define SPHERE_H

#define PI 3.14159

#include <windows.h>
#include <GL/glut.h>
#include "../Shape.hpp"

class Sphere: public Shape {
public:
	GLdouble radius; // radius
	GLint splices, stacks;
	GLfloat r, g, b; //radius, red, green, blue
	GLuint textureID;
	GLUquadric *quad;
	Sphere(GLdouble);
	void setTextureID(GLuint id);
	void draw();
};

#endif
