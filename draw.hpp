#ifndef draw_hpp
#define draw_hpp

#include<GLFW/glfw3.h>
#include "camera.hpp"

void drawcube(GLuint id, float s);
void draw(Camera camera, unsigned int cuboID[3]);
void resize(int w, int h);

#endif