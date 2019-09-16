#include "skybox.h"
#include "sandbox.h"

float v[] =
{
-1.0f,  1.0f, -1.0f,
-1.0f, -1.0f, -1.0f,
1.0f, -1.0f, -1.0f,
1.0f, -1.0f, -1.0f,
1.0f,  1.0f, -1.0f,
-1.0f,  1.0f, -1.0f,

-1.0f, -1.0f,  1.0f,
-1.0f, -1.0f, -1.0f,
-1.0f,  1.0f, -1.0f,
-1.0f,  1.0f, -1.0f,
-1.0f,  1.0f,  1.0f,
-1.0f, -1.0f,  1.0f,

1.0f, -1.0f, -1.0f,
1.0f, -1.0f,  1.0f,
1.0f,  1.0f,  1.0f,
1.0f,  1.0f,  1.0f,
1.0f,  1.0f, -1.0f,
1.0f, -1.0f, -1.0f,

-1.0f, -1.0f,  1.0f,
-1.0f,  1.0f,  1.0f,
1.0f,  1.0f,  1.0f,
1.0f,  1.0f,  1.0f,
1.0f, -1.0f,  1.0f,
-1.0f, -1.0f,  1.0f,

-1.0f,  1.0f, -1.0f,
1.0f,  1.0f, -1.0f,
1.0f,  1.0f,  1.0f,
1.0f,  1.0f,  1.0f,
-1.0f,  1.0f,  1.0f,
-1.0f,  1.0f, -1.0f,

-1.0f, -1.0f, -1.0f,
-1.0f, -1.0f,  1.0f,
1.0f, -1.0f, -1.0f,
1.0f, -1.0f, -1.0f,
-1.0f, -1.0f,  1.0f,
1.0f, -1.0f,  1.0f
};

string facePaths[] =
{
FileSystem::getPath("assets/textures/skybox/right.jpg"),
FileSystem::getPath("assets/textures/skybox/left.jpg"),
FileSystem::getPath("assets/textures/skybox/top.jpg"),
FileSystem::getPath("assets/textures/skybox/bottom.jpg"),
FileSystem::getPath("assets/textures/skybox/front.jpg"),
FileSystem::getPath("assets/textures/skybox/back.jpg")
};

Skybox::Skybox() : shader(Shader("assets/shaders/skybox.vs", "assets/shaders/skybox.fs"))
{
	int	width;
	int	height;
	int	nrChannels;
    vector<std::string> faces;

    faces = vector<string>(facePaths, facePaths + sizeof(facePaths) / sizeof(facePaths[0]));
	GL(glGenVertexArrays(1, &this->VAO));
	GL(glGenBuffers(1, &this->VBO));
	GL(glBindVertexArray(this->VAO));
	GL(glBindBuffer(GL_ARRAY_BUFFER, this->VBO));
	GL(glBufferData(GL_ARRAY_BUFFER, sizeof(v), &v, GL_STATIC_DRAW));
	GL(glEnableVertexAttribArray(0));
	GL(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0));
	GL(glGenTextures(1, &this->textureID));
	GL(glBindTexture(GL_TEXTURE_CUBE_MAP, this->textureID));
	for (unsigned int i = 0; i < faces.size(); i++)
	{
		unsigned char* data = Texture::getData(faces[i].c_str(), &width, &height, &nrChannels, 0);
		if (data)
		{
			GL(glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data));
			Texture::freeData(data);
		}
		else
		{
            errorMessage("skybox cubemap texture failed to load at path: " + faces[i]);
			Texture::freeData(data);
		}
	}
	GL(glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
	GL(glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
	GL(glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
	GL(glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));
	GL(glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE));
	message("skybox loaded");
}

Skybox::~Skybox()
{
    return;
}

void Skybox::render()
{
    Camera* camera;
	mat4 model;
	mat4 view;
	mat4 projection;

	camera = Sandbox::scene()->camera();
	model = mat4(1.0f);
	view = mat4(mat3(camera->GetViewMatrix()));
	projection = perspective(radians(camera->zoom), (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT, camera->nearPlane, camera->farPlane);
	this->shader.use();
	this->shader.setInt("skybox", 0);
	this->shader.setMat4("view", view);
	this->shader.setMat4("projection", projection);
	GL(glBindVertexArray(this->VAO));
	GL(glActiveTexture(GL_TEXTURE0));
	GL(glBindTexture(GL_TEXTURE_CUBE_MAP, this->textureID));
	GL(glDrawArrays(GL_TRIANGLES, 0, 36));
	GL(glBindVertexArray(0));
}