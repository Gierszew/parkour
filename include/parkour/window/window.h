#pragma once
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include "parkour/shader/shader.h"
#include "parkour/mesh/mesh.h"
#include <iostream>
#include <vector>

class Window {
    private:
    GLFWwindow* window = nullptr;
    Shader* shader;
    Mesh* simpleMesh;

    const int SCR_WIDTH = 640, SCR_HEIGHT = 480;

    float deltaTime, lastFrame;

    static void framebufferSizeCallback(GLFWwindow* /*window*/, int width, int height) {
        glViewport(0, 0, width, height);
    }

    void proccessInput();

    public:
    Window();

    void draw();
    void run();

    ~Window();
};