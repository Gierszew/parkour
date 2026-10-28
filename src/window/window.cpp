#include "parkour/window/window.h"

void Window::proccessInput() {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

Window::Window() {
    glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_X11); // for my system
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);  // 3.3 version OpenGL
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Parkour", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create a window" << std::endl;
        glfwTerminate();
        throw std::runtime_error("Failed to create window");
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

    // init glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        throw std::runtime_error("Failed to init GLAD");
    }

    glEnable(GL_DEPTH_TEST);

    shader = new Shader("shaders/simple.vs", "shaders/simple.frag");
    std::vector<Vertex> simpleTriangle = {
        {glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)}, // (0,0,0) R
        {glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)}, // (0,1,0) G
        {glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f)} // (-1,0,0)B
    };
    simpleMesh = new Mesh(shader, simpleTriangle);
}

void Window::draw() {
    simpleMesh->draw();
}

void Window::run() {
    while (!glfwWindowShouldClose(window)) {
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        proccessInput();
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        draw();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

Window::~Window() {
    if (window) glfwDestroyWindow(window);
    glfwTerminate();
}