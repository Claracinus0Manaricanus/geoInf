#include "utility.h"

//constructors
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

//memory freeing
int freeGeoObj(struct geoObj* toFree){
    free(toFree->name);
    free(toFree->soilType);
    free(toFree->flora);
    free(toFree->image);
    return 0;
}