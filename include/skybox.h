#ifndef SKYBOX_H
#define SKYBOX_H

#include "shader.h"

class Skybox
{
private:
    Shader shader;
    vector<std::string> faces;
    unsigned int        VAO;
    unsigned int        VBO;
    unsigned int        textureID;
    float*              vertices;
public:
    Skybox();
    ~Skybox();
    void render();
};


#endif