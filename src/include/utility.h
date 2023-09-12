#ifndef UTILITY_H
#define UTILITY_H

#include "T0.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdint.h>

//creates a window and makes it current opengl context
GLFWwindow* cm_CreateWindow(int width, int height, const char* name);
//needs error message return //char* error

#endif