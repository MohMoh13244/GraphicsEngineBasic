/*
 *  GraphicsEngineBasic
 *  Author: Mohamad El mansour
 *  Version: 2023-11-09
 */

#ifndef SURFACE_H
#define SURFACE_H

#include <GL/glut.h>
#include "../curve/Curve.hpp"
#include "../Shape.hpp"
#include "../Point.hpp"
#include "../Vector.hpp"
#include <stdio.h>

#define MAXROW 73
#define MAXCOL 26

class Surface : public Shape {
public:
	GLint row; // number of rows of mesh
	GLint col; // number of columns of mesh
	Point  Pts[MAXROW][MAXCOL];    // array of mesh vertex
	Vector Normal[MAXROW][MAXCOL]; 	// array of vertex normal
	Surface();
	void reset();
	void drawSurface();
	void draw();
};

#endif
