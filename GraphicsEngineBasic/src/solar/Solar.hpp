/*
 *  GraphicsEngineBasic
 *  Author: Mohamad El mansour
 *  Version: 2023-11-09
 */

#ifndef SOLAR_H
#define SOLAR_H

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "Sphere.hpp"

class Solar : public Shape {
protected:

public:
	Sphere *sun;
	Sphere *earth;
	Sphere *moon;
	Solar();
	void draw();
	void reset();
};

#endif
