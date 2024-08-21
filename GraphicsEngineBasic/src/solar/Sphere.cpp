/*
 *  GraphicsEngineBasic
 *  Author: Mohamad El mansour
 *  Version: 2023-11-09
 */

#include "Sphere.hpp"
#include <stdio.h>
extern RenderMode renderMode;

Sphere::Sphere(GLdouble size) {
	radius = size;
	splices = 50;
	stacks = 50;
	textureID = 0;
	r=1;
	g=1;
	b=1;
	quad = gluNewQuadric();
	gluQuadricDrawStyle(quad, GLU_FILL);
	gluQuadricTexture(quad, GL_TRUE);
	gluQuadricNormals(quad, GLU_SMOOTH);
	glShadeModel(GL_FLAT);

}


void Sphere::setTextureID(GLuint id){
	textureID = id;
}

void Sphere::draw() {
	glPushMatrix();
	ctmMultiply();

	switch (renderMode) {
		case WIRE:
		case CONSTANT:
		case FLAT:
		case SMOOTH:

			glColor3f(r, g, b);
			glutSolidSphere(radius,splices,stacks);
			break;

		case TEXTURE:

			glBindTexture(GL_TEXTURE_2D, textureID);
			gluSphere(quad, radius,splices,stacks);
			break;

		case PHONE:
			// your code
			break;
	}

	glPopMatrix();
}


