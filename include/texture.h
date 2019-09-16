#ifndef TEXTURE_H
#define TEXTURE_H

#include <stb_image.h>

#include "system.h"

#define DIFFUSE_TEXTURE "texture_diffuse"
#define SPECULAR_TEXTURE "texture_diffuse"
#define NORMAL_TEXTURE "texture_diffuse"
#define HEIGHT_TEXTURE "texture_diffuse"

class Texture
{
	private:
		static List<Texture>	_loadedTexture;
        static Texture			_defaultTexture;

		static unsigned int fromFile(string path);
		static GLenum		getFormat(int comp);
	public:
		Texture();
		Texture(string path, string type);
		~Texture();
		
		unsigned int	id;
		string			type;
		string			path;
		
		static void		init();
		static Texture	load(string path, string type);
		static Texture	defaultTexture();
};

#endif