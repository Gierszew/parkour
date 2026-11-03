#pragma once
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include "parkour/shader/shader.h"
#include "parkour/mesh/mesh.h"
#include <iostream>
#include <vector>
#include <memory>

class Window {
    private:
    GLFWwindow* window = nullptr;
    std::unique_ptr<Shader> shader;
    std::unique_ptr<Mesh> simpleMesh;

    const int SCR_WIDTH = 640, SCR_HEIGHT = 480;
    int width = SCR_WIDTH, height = SCR_HEIGHT;

    float deltaTime = 0.0f, lastFrame = 0.0f;

    static void framebufferSizeCallback(GLFWwindow* /*window*/, int width, int height) {
        glViewport(0, 0, width, height);
        width = width;
        height = height;
    }

    void proccessInput();

    public:
    Window();

    void transform();
    void draw();
    void run();

    ~Window();
};