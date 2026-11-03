#pragma once
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <parkour/shader/shader.h>
#include <parkour/mesh/mesh.h>
#include <parkour/camera/camera.h>
#include <iostream>
#include <vector>
#include <memory>

class Window {
    private:
    GLFWwindow* window = nullptr;
    std::unique_ptr<Shader> shader;
    std::unique_ptr<Mesh> simpleMesh;
    Camera camera;

    const int SCR_WIDTH = 640, SCR_HEIGHT = 480;
    float lastX = SCR_WIDTH / 2.0f, lastY = SCR_HEIGHT / 2.0f;
    bool firstMouse = true;
    int width = SCR_WIDTH, height = SCR_HEIGHT;

    float deltaTime = 0.0f, lastFrame = 0.0f;

   static void framebufferSizeCallback(GLFWwindow* window, int w, int h) {
        glViewport(0, 0, w, h);
        auto* self = static_cast<Window*>(glfwGetWindowUserPointer(window));
        if (self) {
            self->width  = w;
            self->height = h;
        }
    }

    static void mouse_callback(GLFWwindow* window, double xposIn, double yposIn) {
        auto* self = static_cast<Window*>(glfwGetWindowUserPointer(window));
        if (!self) return;
        
        float xpos = static_cast<float>(xposIn);
        float ypos = static_cast<float>(yposIn);

        if (self->firstMouse)
        {
            self->lastX = xpos;
            self->lastY = ypos;
            self->firstMouse = false;
        }
    
        float xoffset = xpos - self->lastX;
        float yoffset = self->lastY - ypos;
    
        self->lastX = xpos;
        self->lastY = ypos;
    
        self->camera.ProcessMouseMovement(xoffset, yoffset);
    }

    static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
        auto* self = static_cast<Window*>(glfwGetWindowUserPointer(window));
        if (!self) return;

        self->camera.ProcessMouseScroll(static_cast<float>(yoffset));
    }

    void processInput();

    public:
    Window();

    void transform();
    void draw();
    void run();

    ~Window();
};