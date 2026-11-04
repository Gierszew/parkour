#define STB_IMAGE_IMPLEMENTATION
#include "parkour/window/window.h"
#include "stb_image.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <iostream>

int main() {
    Window window;
    window.run();

    int nrAttributes;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
    return 0;
}