#define GLM_ENABLE_EXPERIMENTAL
#pragma once

#include "stb_image.h"

#include <iostream>

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "shader_s_shader.h"
#include "shader_s.h"
#include "glm/gtc/matrix_transform.hpp"

#include "glm/mat4x4.hpp"

#include <memory>
#include <vector>

class Sphere
{
private:

    unsigned int m_VAO;
    unsigned int m_VBO;
    int m_numVertices;

    std::vector<float> vertices;
    std::vector<float> indices;

    float x, y, z;

    unsigned int m_Texture;

public:
    glm::mat4 model;
    Shader m_Shader;

    glm::mat4 view;
    glm::mat4 projection;
    
    Sphere(const float r, const char* vsFile, const char* fsFile, glm::mat4 model, glm::mat4 view, glm::mat4 projection, std::string texFile);
    ~Sphere();
    void initBuffer(int numRows, int numCols, float radius);
    void initTexture(std::string texName);
    void render();
    void initBySphericalCoords(float radius, float pitch, float heading);
};
