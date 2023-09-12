#include "utility.h"

GLFWwindow* cm_CreateWindow(int width, int height, const char* name){
    GLFWwindow* win=glfwCreateWindow(width,height,name,NULL,NULL);
    if(win==NULL){
        return NULL;
    }else{
        glfwMakeContextCurrent(win);
        if(glewInit()!=GLEW_OK){
            glfwDestroyWindow(win);
            return NULL;
        }
    }
    return win;
}