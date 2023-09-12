#version 450 core

layout(location=0) in vec2 vertPos;
layout(location=1) in vec2 vertTex;

out vec2 texCoord;

void main(){
    texCoord=vertTex;
    gl_Position=vec4(vertPos.xy,0,1);
}