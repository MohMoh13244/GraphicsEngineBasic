/*
 *  GraphicsEngineBasic
 *  Author: Mohamad El mansour
 *  Version: 2023-11-09
 */

#ifndef CURVE_H
#define CURVE_H

#include <GL/glut.h>
#include "../Point.hpp"
#include "../Vector.hpp"
#include <math.h>

#define MAXSIZE 100

class Curve  {
protected:
	Point Pts[MAXSIZE];       // array to hold sequence of points on curve
	Vector Tangent[MAXSIZE];  // array to hold sequence of tangents of the points
public:
	GLint nPts;   // number of points for of the curve
	Curve();
    ~Curve();
	void reset();
	void drawCurve();
	void set2DView(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top);
};

#endif
