#include "parkour/mesh/mesh.h"

Mesh::Mesh(Shader* shader, std::vector<Vertex> vertex) {
    this->vertex = vertex;
    this->shader = shader;

    setup();
}

void Mesh::setup() {
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glBufferData(GL_ARRAY_BUFFER, vertex.size() * sizeof(Vertex), vertex.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(Vertex), (void*)offsetof(Vertex, Position));
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, false, sizeof(Vertex), (void*)offsetof(Vertex, Color));
    glEnableVertexAttribArray(1);
}

void Mesh::draw() {
    shader->use();
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, vertex.size());
}

Mesh::~Mesh() {
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);
}