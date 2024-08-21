/*
 *  GraphicsEngineBasic
 *  Author: Mohamad El mansour
 *  Version: 2023-11-09
 */

#include "Solar.hpp"


Solar::Solar() {
	sun = new Sphere(1.0);
	sun->translate(0, 0, 0);
	sun->r = 1.0;
	sun->g = 0.0;
	sun->b = 0.0;

	earth = new Sphere(0.25);
	earth->translate(0, 2, 0);
	earth->r = 0.0;
	earth->g = 1.0;
	earth->b = 0.0;

	moon = new Sphere(0.1);
	moon->translate(0, 2.4, 0);
	moon->r = 0.0;
	moon->g = 0.0;
	moon->b = 1.0;
}

void Solar::draw() { /*1: wire, 4: bitmap */
	glColor3f(1, 1, 1);
	sun->draw();
	earth->draw();
	moon->draw();
}

void Solar::reset() {
//
}


