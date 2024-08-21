/*
 *  GraphicsEngineBasic
 *  Author: Mohamad El mansour
 *  Version: 2023-11-09
 */
#include "Surface.hpp"

extern RenderMode renderMode;

Surface::Surface() {
	reset();
}

void Surface::reset() {
	row = 0;
	col = 0;
}

void Surface::drawSurface() {

	switch (renderMode) {
	case WIRE:
		for (int j = 0; j < col-1; j++) {
			for (int i = 0; i < row-1; i++) {
				glBegin(GL_LINE_LOOP);
				glVertex3f(Pts[i][j].x, Pts[i][j].y, Pts[i][j].z);
				glVertex3f(Pts[i + 1][j].x, Pts[i + 1][j].y, Pts[i + 1][j].z);
				glVertex3f(Pts[i + 1][j + 1].x, Pts[i + 1][j + 1].y, Pts[i + 1][j + 1].z);
				glVertex3f(Pts[i][j+1].x, Pts[i][j+1].y, Pts[i][j+1].z);
				glEnd();
			}
		}
		break;
	case CONSTANT:
	case FLAT:
	case SMOOTH:
		for (int j = 0; j < col-1; j++) {
			for (int i = 0; i < row-1; i++) {
				glBegin(GL_POLYGON);
				glVertex3f(Pts[i][j].x, Pts[i][j].y, Pts[i][j].z);
				glVertex3f(Pts[i + 1][j].x, Pts[i + 1][j].y, Pts[i + 1][j].z);
				glVertex3f(Pts[i + 1][j + 1].x, Pts[i + 1][j + 1].y, Pts[i + 1][j + 1].z);
				glVertex3f(Pts[i][j+1].x, Pts[i][j+1].y, Pts[i][j+1].z);
				glEnd();
			}
		}
		break;
	case PHONE:
		glPolygonMode( GL_FRONT, GL_FILL);
		glPolygonMode( GL_BACK, GL_LINE);
		// your code
		break;

	case TEXTURE:
		for (int j = 0; j < col-1; j++) {
			for (int i = 0; i < row-1; i++) {
				glBegin(GL_POLYGON);
				glVertex3f(Pts[i][j].x, Pts[i][j].y, Pts[i][j].z);
				glVertex3f(Pts[i + 1][j].x, Pts[i + 1][j].y, Pts[i + 1][j].z);
				glVertex3f(Pts[i + 1][j + 1].x, Pts[i + 1][j + 1].y, Pts[i + 1][j + 1].z);
				glVertex3f(Pts[i][j+1].x, Pts[i][j+1].y, Pts[i][j+1].z);
				glEnd();
			}
		}
		break;
		break;
	}
}

void Surface::draw() {
	glPushMatrix();
	ctmMultiply();
	glScalef(s * 0.01, s * 0.01, s * 0.01);		// to shrink the object to size of viewable
	drawSurface();
	glPopMatrix();
}

