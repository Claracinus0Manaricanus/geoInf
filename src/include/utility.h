#ifndef UTILITY_H
#define UTILITY_H

#include "T0.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdint.h>
#include <stdlib.h>

//constructors
GLFWwindow* cm_CreateWindow(int width, int height, const char* name);//creates a window and makes it current opengl context
//needs error message return //char* error

//memory freeing
int freeGeoObj(struct tableElement* toFree);//frees given geoObj struct

#endif

/*
utility.h supplies utilities such as window and opengl context creation.
Its usage is meant to tidy up the code thats repetitive or constant.
It also supplies functions for interface programs to use.
*/