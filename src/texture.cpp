#include "texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

List<Texture> Texture::_loadedTexture = List<Texture>();
Texture Texture::_defaultTexture = Texture();

Texture::Texture() : id(0), path("undefined"), type("undefined") { }

Texture::Texture(string path, string type) : id(Texture::fromFile(path)), path(path), type(type)
{
    if (this->id == 0) { return; }
    message("texture loaded: " + path + ", type: " + type);
    Texture::_loadedTexture.add(*this);
}

Texture::~Texture()
{
    return;
}

unsigned int Texture::fromFile(string path)
{
    int width;
    int height;
    int components;
    string filename;
    unsigned int textureID;
    unsigned char *data;
    
    GL(glGenTextures(1, &textureID));
    filename = FileSystem::getRoot() + '/' + path;
    data = Texture::getData(filename.c_str(), &width, &height, &components, 0);
    if (data)
    {
        GLenum format = Texture::getFormat(components);

        GL(glBindTexture(GL_TEXTURE_2D, textureID));
        GL(glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data));
        GL(glGenerateMipmap(GL_TEXTURE_2D));

        GL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));
        GL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));
        GL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR));
        GL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));

        Texture::freeData(data);
    }
    else
    {
        errorMessage("texture failed to load at path: " + path);
        Texture::freeData(data);
        return (0);
    }
    return (textureID);
}

void Texture::init()
{
    string path = "assets/textures/default.png";
    string type = string(DIFFUSE_TEXTURE);
	Texture::_defaultTexture = Texture(path, type);
}

Texture Texture::load(string path, string type)
{
    for (int i = 0; i < Texture::_loadedTexture.length(); i++)
    {
        Texture texture = Texture::_loadedTexture.get(i);
        if (strcmp(texture.path.c_str(), path.c_str()) == 0 && strcmp(texture.type.c_str(), type.c_str()))
        {
            message("texture retrieved: " + path + ", type: " + type);
            return (texture);
        }
    }
    return(Texture(path, type));
}

Texture Texture::defaultTexture()
{
    return (Texture::_defaultTexture);
}

GLenum Texture::getFormat(int comp)
{
    switch (comp)
    {
        case 1: return (GL_RED); break;
        case 3: return (GL_RGB); break;
        case 4: return (GL_RGBA); break;
        default: break;
    }
    return (0);
}

unsigned char *Texture::getData(const char *filename, int *x, int *y, int *comp, int compReq)
{
    return (stbi_load(filename, x, y, comp, compReq));
}

void Texture::freeData(unsigned char *data)
{
    stbi_image_free(data);
}