#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexture;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 ourColor;
out vec3 bNormal;
out vec3 FragPos;
out vec2 TextureCoord;

void main()
{
    gl_Position = projection * view * model * vec4(aPos, 1.0); 
    ourColor = vec3(1.0,0.0,0.0);
    bNormal = mat3(transpose(inverse(model))) * aNormal;
    FragPos = vec3(model * vec4(aPos, 1.0));
    TextureCoord = aTexture;
}