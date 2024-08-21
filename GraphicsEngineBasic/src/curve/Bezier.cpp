/*
 *  GraphicsEngineBasic
 *  Author: Mohamad El mansour
 *  Version: 2023-11-09
 */
#include "Bezier.hpp"


extern GLint winWidth, winHeight;

Bezier::Bezier() {
	reset();
}

void Bezier::reset() {
	nCtrlPts = 0;
	nPts = 26;
}


/*  Compute Bezier point at u, and output in Point *bezPt */
void Bezier::computeBezPt(GLfloat u, GLint nCtrlPts, Point ctrlPts[], Point *bezPt)
{
	double b[nCtrlPts], x=0, y=0, z=0, r;
	int n = nCtrlPts - 1;

	if (u > .99999) {bezPt->set(ctrlPts[nCtrlPts-1].x,ctrlPts[nCtrlPts-1].y,ctrlPts[nCtrlPts-1].z);
	}else {
		r = u/(1-u);
		b[0] = pow( 1.0-u, n);

		for (int i=1; i<=n; ++i) {
			b[i] = b[i-1] * (n-i+1) / i * r;
		}

		for (int i=0; i<=n; ++i) {
			x = x + b[i]*ctrlPts[i].x;
			y = y + b[i]*ctrlPts[i].y;
			z = z + b[i]*ctrlPts[i].z;
		}

		bezPt->set(x,y,z);
	}
}

/*  Compute both Bezier point and tangent at u, and output in Point bezPt and Vector bezTan respectively*/
void Bezier::computeBezPtTan(GLfloat u, GLint nCtrlPts, Point ctrlPts[],Point *bezPt, Vector *bezTan)
{
	int n = nCtrlPts-1,n1=nCtrlPts-2;
	double b[n], x=0, y=0, z=0, r;


	if (u > .99999) {bezTan->set(ctrlPts[nCtrlPts].x -ctrlPts[nCtrlPts-1].x,ctrlPts[nCtrlPts].y -ctrlPts[nCtrlPts-1].y,ctrlPts[nCtrlPts].z-ctrlPts[nCtrlPts-1].z);}
	else {
		r = u/(1-u);
		b[0] = pow( 1.0-u, n1);
		for (int i=1; i<n; ++i) {
			b[i] = b[i-1] * (n-i) / i * r;
		}
		for (int i=0; i<n; ++i) {
			x = x + b[i]*(ctrlPts[i+1].x-ctrlPts[i].x);
			y = y + b[i]*(ctrlPts[i+1].y-ctrlPts[i].y);
			z = z + b[i]*(ctrlPts[i+1].z-ctrlPts[i].z);
		}
		bezTan->set(n*x,n*y,n*z);
	}
}


/* call to compute the sequence of points on Bezier curve for drawing Bezier curve */
void Bezier::computeBezCurvePts() {
	GLfloat u = 0;

	for (int k = 0; k < nPts; k++) {
		u = GLfloat(k) / GLfloat(nPts-1);
		computeBezPt(u, nCtrlPts, ctrlPts,&Pts[k]);
	}
}


/* call to compute the sequence of points and tangents on Bezier curve for mesh of rotating Bezier curve */
void Bezier::computeBezPtsTan(GLint npts, Point pts[], Vector tangents[]) {
	GLfloat u = 0;
	for (int k = 0; k < npts; k++) {
		u = GLfloat(k) / GLfloat(npts-1);
		computeBezPt( u,  nCtrlPts,  ctrlPts, &pts[k]);
		computeBezPtTan(u, nCtrlPts, ctrlPts, &pts[k],  &tangents[k]);
	}
}


void Bezier::drawCPts() {
	glPointSize(3.0);
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POINTS);
	for (int i = 0; i < nCtrlPts; i++) {
		glVertex2f(ctrlPts[i].x, ctrlPts[i].y);
	}
	glEnd();
}

/* display Control points in 2D view */
void Bezier::displayCPts() {
	set2DView(-winWidth / 2, winWidth / 2, -winHeight / 2, winHeight / 2);
	drawCPts();
}

/* display Control points and curve in 2D view */
void Bezier::display() {
	set2DView(-winWidth / 2, winWidth / 2, -winHeight / 2, winHeight / 2);
	drawCPts();
	drawCurve();
}

