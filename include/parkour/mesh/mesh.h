#pragma once
#include <vector>
#include "parkour/shader/shader.h"
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

struct Vertex {
    glm::vec3 Position;
    glm::vec3 Color;
};

class Mesh {
    unsigned int vao, vbo;

    std::vector<Vertex> vertex;

    void setup();

    public:
    Mesh(std::vector<Vertex> vertex);
    Mesh(const Mesh&) = delete;
    Mesh& operator=(const Mesh&) = delete;
    Mesh(Mesh&&) noexcept = default;
    Mesh& operator=(Mesh&&) noexcept = default;

    void draw(Shader* shader);

    ~Mesh();
};