#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

uniform mat4 u_modelTransformMatrix;
uniform mat4 u_projectionMatrix;
uniform mat4 u_viewMatrix;

out vec3 ourColor;

void main()
{
    gl_Position = u_projectionMatrix * u_viewMatrix * u_modelTransformMatrix * vec4(aPos, 1.0f);
    ourColor = aColor;
}