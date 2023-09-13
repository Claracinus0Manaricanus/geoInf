#include <stdio.h>
#include "include/T0.h"//custom types
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//hello message
const char* welcome=
"Welcome to GeoInf D-V1.0\n"
"Starting program...\n\0";

int main(){
    //start
    printf("%s",welcome);

    //glfw initialization hints

    //glfw init
    if(glfwInit()==GLFW_FALSE){
        printf("ERR: glfw init failed.\n");
        return 1;
    }

    //glfw window hints //do version checks
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,5);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE,GLFW_TRUE);
    glfwWindowHint(GLFW_FLOATING,GLFW_TRUE);

    //window and context creation
    GLFWwindow* mainWindow=glfwCreateWindow(800,600,"photoViewer",NULL,NULL);
    if(mainWindow==NULL){
        printf("ERR: Window creation failed.\n");
        glfwTerminate();
        return 1;
    }else{
        glfwMakeContextCurrent(mainWindow);
        if(glewInit()!=GLEW_OK){
            printf("ERR: glew init failed.\n");
            glfwTerminate();
            return 1;
        }
    }

    //glfw settings
    glfwSwapInterval(1);

    //shaders

    //program

    //while loop for the window
    glClearColor(0.0f,0.0f,0.0f,1.0f);
    while(!glfwWindowShouldClose(mainWindow)){
        //starting frame
        glClear(GL_COLOR_BUFFER_BIT);

        //displaying frame
        glfwSwapBuffers(mainWindow);
        glfwPollEvents();
    }

    //terminating
    printf("INF: Exiting...\n");
    glfwTerminate();
    return 0;
}

/*
Graphical User Interface for geoInf project.
This program uses opengl and glfw for visuals.
It is a desktop application made for X window systems.
*/

//idea board:
//dearImGui