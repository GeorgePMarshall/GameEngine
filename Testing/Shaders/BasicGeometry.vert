#version 400 core

layout (location = 0) in vec4 position; 


uniform mat4 projectionView;
uniform mat4 transform;

void main()
{
    gl_Position = projectionView * transform * position;
}
