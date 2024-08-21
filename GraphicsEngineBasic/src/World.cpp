/*
 *  GraphicsEngineBasic
 *  Author: Mohamad El mansour
 *  Version: 2023-11-09
 */
#include "World.hpp"
#include "Cube.hpp"
#include "Pyramid.hpp"
#include "House.hpp"

using namespace std;

World::World() {
	Shape *obj = NULL;

    /* add Cube into the world object list */
	obj = new Cube();
	obj->setId(1);
	obj->scaleChange(-0.2);
	objlist.push_back(obj);

	obj = new Pyramid();
	obj->setId(2);
	obj->scaleChange(-0.2);
	obj->translate(-2.5, 0, 0);
	objlist.push_back(obj);

	obj = new House();
	obj->setId(3);
	obj->scaleChange(-0.2);
	obj->translate(2.5, 0, 0);
	objlist.push_back(obj);
}

World::~World(){
	Shape *obj;
	while (!objlist.empty()) {
		obj = objlist.front();
		objlist.pop_front();
		free(obj);
	}
}

void lineSegment(float x1, float y1, float z1, float x2, float y2, float z2) {
	glBegin(GL_LINES);
	glVertex3f(x1, y1, z1);
	glVertex3f(x2, y2, z2);
	glEnd();
}

void World::draw() {
//	glColor3f(1.0, 0.0, 0.0);
//	lineSegment(-2, 0, 0, 4, 0, 0); /* x-axis in red */
// 	glColor3f(0.0, 1.0, 0.0);
//	lineSegment(0, -2, 0, 0, 4, 0); /* y-axis in green */
//	glColor3f(0.0, 0.0, 1.0);
//	lineSegment(0, 0, -2, 0, 0, 4); /* z-axis in blue */

	std::list<Shape*>::iterator it;
	for (it = objlist.begin(); it !=  objlist.end(); ++it) {
	  (*it)->draw();
    }
}

void World::reset(){
	Shape *obj = NULL;

	obj = this->searchById(1);
	obj->reset();
	obj->setScale(0.5);
	obj->translate(2.5, 0, 0);

	obj = this->searchById(2);
	obj->reset();
	obj->setScale(0.5);
	obj->translate(4, 0, 0);

	obj = this->searchById(3);
	obj->reset();
	obj->setScale(0.5);


//	std::list<Shape*>::iterator it;
//	for (it = objlist.begin(); it !=  objlist.end(); ++it) {
//	  (*it)->reset();
//  }
}

Shape* World::searchById(GLint i) {
	std::list<Shape*>::iterator it;
	for (it = objlist.begin(); it !=  objlist.end(); ++it) {
	  if ((*it)->getId() == i) return *it;
    }
	return NULL;
}

