#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

uniform mat4 u_modelTransformMatrix;
uniform mat4 u_projectionMatrix;

out vec3 ourColor;

void main()
{
    vec4 model = vec4(aPos, 1.0);
    vec4 newPosition = u_modelTransformMatrix * model;
    gl_Position = u_projectionMatrix * newPosition;
    ourColor = aColor;
}