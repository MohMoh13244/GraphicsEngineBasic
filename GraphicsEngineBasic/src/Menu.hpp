/*
 *  GraphicsEngineBasic
 *  Author: Mohamad El mansour
 *  Version: 2023-11-09
 */

#ifndef MENU_HPP_
#define MENU_HPP_

#include "glsl/Angel.h"
#include <GL/glut.h>

// SimpleView1
void menu();
void mainMenu(GLint option);
void ObjSubMenu(GLint objectOption);
void MCSTransMenu(GLint transOption);
void WCSTransMenu(GLint transOption);
void VCSTransMenu(GLint transOption);
void reset();
void MCSTransform(GLint);
void WCSTransform(GLint);
void VCSTransform(GLint);

// SimpleView2
void cullMenu(GLint option);
void lightMenu(GLint option);
void lightTransform(GLint);
void shadeMenu(GLint option);
void animateMenu(GLint option);

// SimpleView3
void curveSurfaceMenu(GLint option);
void move();

#endif
