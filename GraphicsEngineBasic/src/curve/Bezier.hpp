/*
 *  GraphicsEngineBasic
 *  Author: Mohamad El mansour
 *  Version: 2023-11-09
 */


#ifndef BEZIER_H
#define BEZIER_H

#include <GL/glut.h>
#include "../Point.hpp"
#include "../Vector.hpp"
#include <math.h>
#include "../curve/Curve.hpp"

class Bezier : public Curve {
public:
	GLint nCtrlPts;       // number of Bezier curve control points
	Point ctrlPts[10];    // array to store control points, up to 10 points

	Bezier();
	void reset();
	void computeBezPt(GLfloat u, GLint nCtrlPts, Point ctrlPts[],Point *bezPt);
	void computeBezCurvePts();
	void drawCPts();
	void displayCPts();
	void display();
	/* will be used be rotation */
	void computeBezPtTan(GLfloat u, GLint nCtrlPts, Point ctrlPts[],Point *bezPt, Vector *bezTan);
	void computeBezPtsTan(GLint npts, Point pts[], Vector tangents[]);


};

#endif
