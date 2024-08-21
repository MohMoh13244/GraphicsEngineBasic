/*
 *  GraphicsEngineBasic
 *  Author: Mohamad El mansour
 *  Version: 2023-11-09
 */

#include "Light.hpp"
#include "Matrix.hpp"
#include <stdio.h>

Light::Light(){
	reset();
}

void Light::reset(){
	mc.mat[0][3] = 2.0;
	mc.mat[1][3] = 2.0;
	mc.mat[2][3] = 2.0;
	I = 1.0;
	Rd = 1.0;
	size = 0.2;
	on = true;
}

void Light::Increment(GLfloat p, GLfloat ra, GLfloat rd){
	I += p;
	if (I < 0.03) I = 0.01;
	else if (I > 0.97 ) I = 1;
}

void Light::draw(){
	if(on == true){
		glPushMatrix();
		this->ctmMultiply();
		glColor3f(I, I, I);
		glutSolidSphere(size, 20, 20);
		glPopMatrix();
	}
}
