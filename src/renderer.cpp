#include "renderer.h"
#include "sandbox.h"

GLFWwindow *Renderer::_window = nullptr;

Texture *Renderer::_defaultTexture = nullptr;

vec3 Renderer::sun = vec3(-0.3, -0.5, 0.2);

Shader Renderer::ourShader = Shader();

Shader Renderer::skybox = Shader();

float skyboxVertices[] =
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

vector<std::string> skyboxFaces(facePaths, facePaths + sizeof(facePaths) / sizeof(facePaths[0]));

unsigned int		skyboxVAO = 0;
unsigned int		skyboxVBO = 0;
unsigned int		skyboxTextureID = 0;

void Renderer::input()
{
    if (glfwGetKey(Renderer::window(), GLFW_KEY_ESCAPE) == GLFW_PRESS) { std::exit(0); }
    if (glfwGetKey(Renderer::window(), GLFW_KEY_UP) == GLFW_PRESS) { Input::press(Key_Up); }
    if (glfwGetKey(Renderer::window(), GLFW_KEY_DOWN) == GLFW_PRESS) { Input::press(Key_Down); }
    if (glfwGetKey(Renderer::window(), GLFW_KEY_LEFT) == GLFW_PRESS) { Input::press(Key_Left); }
	if (glfwGetKey(Renderer::window(), GLFW_KEY_RIGHT) == GLFW_PRESS) { Input::press(Key_Right); }
	if (glfwGetKey(Renderer::window(), GLFW_KEY_A) == GLFW_PRESS) { Input::press(Key_A); }
	if (glfwGetKey(Renderer::window(), GLFW_KEY_B) == GLFW_PRESS) { Input::press(Key_B); }
	if (glfwGetKey(Renderer::window(), GLFW_KEY_C) == GLFW_PRESS) { Input::press(Key_C); }
	if (glfwGetKey(Renderer::window(), GLFW_KEY_D) == GLFW_PRESS) { Input::press(Key_D); }
	if (glfwGetKey(Renderer::window(), GLFW_KEY_E) == GLFW_PRESS) { Input::press(Key_E); }
	if (glfwGetKey(Renderer::window(), GLFW_KEY_F) == GLFW_PRESS) { Input::press(Key_F); }
	if (glfwGetKey(Renderer::window(), GLFW_KEY_G) == GLFW_PRESS) { Input::press(Key_G); }
	if (glfwGetKey(Renderer::window(), GLFW_KEY_H) == GLFW_PRESS) { Input::press(Key_H); }
	if (glfwGetKey(Renderer::window(), GLFW_KEY_I) == GLFW_PRESS) { Input::press(Key_I); }
	if (glfwGetKey(Renderer::window(), GLFW_KEY_J) == GLFW_PRESS) { Input::press(Key_J); }
	if (glfwGetKey(Renderer::window(), GLFW_KEY_K) == GLFW_PRESS) { Input::press(Key_K); }
	if (glfwGetKey(Renderer::window(), GLFW_KEY_L) == GLFW_PRESS) { Input::press(Key_L); }
	if (glfwGetKey(Renderer::window(), GLFW_KEY_M) == GLFW_PRESS) { Input::press(Key_M); }
	if (glfwGetKey(Renderer::window(), GLFW_KEY_N) == GLFW_PRESS) { Input::press(Key_N); }
	if (glfwGetKey(Renderer::window(), GLFW_KEY_O) == GLFW_PRESS) { Input::press(Key_O); }
	if (glfwGetKey(Renderer::window(), GLFW_KEY_P) == GLFW_PRESS) { Input::press(Key_P); }
	if (glfwGetKey(Renderer::window(), GLFW_KEY_Q) == GLFW_PRESS) { Input::press(Key_Q); }
	if (glfwGetKey(Renderer::window(), GLFW_KEY_R) == GLFW_PRESS) { Input::press(Key_R); }
	if (glfwGetKey(Renderer::window(), GLFW_KEY_S) == GLFW_PRESS) { Input::press(Key_S); }
	if (glfwGetKey(Renderer::window(), GLFW_KEY_T) == GLFW_PRESS) { Input::press(Key_T); }
	if (glfwGetKey(Renderer::window(), GLFW_KEY_U) == GLFW_PRESS) { Input::press(Key_U); }
	if (glfwGetKey(Renderer::window(), GLFW_KEY_V) == GLFW_PRESS) { Input::press(Key_V); }
	if (glfwGetKey(Renderer::window(), GLFW_KEY_W) == GLFW_PRESS) { Input::press(Key_W); }
	if (glfwGetKey(Renderer::window(), GLFW_KEY_X) == GLFW_PRESS) { Input::press(Key_X); }
	if (glfwGetKey(Renderer::window(), GLFW_KEY_Y) == GLFW_PRESS) { Input::press(Key_Y); }
	if (glfwGetKey(Renderer::window(), GLFW_KEY_Z) == GLFW_PRESS) { Input::press(Key_Z); }
}

void Renderer::renderSceneObject(IObject *object, Shader *shader)
{
	if (object->model.enabled)
	{
		Camera* camera;
		mat4 projection;
		mat4 view;
		mat4 model;

		camera = Sandbox::scene()->camera();
		projection = perspective(radians(camera->zoom), (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT, camera->nearPlane, camera->farPlane);
		view = camera->GetViewMatrix();
		model = mat4(1.0f);
		model = translate(model, object->transform.position);
		model = rotate(model, radians(object->transform.rotation.x), vec3(1.0f, 0.0f, 0.0f));
		model = rotate(model, radians(object->transform.rotation.y), vec3(0.0f, 1.0f, 0.0f));
		model = rotate(model, radians(object->transform.rotation.z), vec3(0.0f, 0.0f, 1.0f));
		model = scale(model, object->transform.scale);
		shader->use();
		shader->setMat4("projection", projection);
		shader->setMat4("view", view);
		shader->setMat4("model", model);
		object->model.Draw(*shader);
	}
}

void Renderer::renderSceneObjects()
{
	IObject* object;

	ourShader.use();
	ourShader.setVec3("light.direction", sun);
	ourShader.setVec3("light.ambient", 0.5f, 0.5f, 0.5f);
	ourShader.setVec3("light.diffuse", 0.5f, 0.5f, 0.5f);
	ourShader.setVec3("light.specular", 1.0f, 1.0f, 1.0f);
	ourShader.setInt("material.diffuse", 0);
	ourShader.setInt("material.specular", 1);
	ourShader.setFloat("material.shininess", 32.0f);
	ourShader.setVec3("viewPos", Sandbox::scene()->camera()->transform.position);
	for (auto i = Sandbox::scene()->objects()->begin(); i != Sandbox::scene()->objects()->end(); i++)
	{
		object = (*i);
		if (object->enabled) { Renderer::renderSceneObject(object, &ourShader); }
	}
}

void Renderer::renderSceneSkybox()
{
	Camera* camera;
	mat4 model;
	mat4 view;
	mat4 projection;

	camera = Sandbox::scene()->camera();
	model = mat4(1.0f);
	view = mat4(mat3(camera->GetViewMatrix()));
	projection = perspective(radians(camera->zoom), (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT, camera->nearPlane, camera->farPlane);
	skybox.use();
	skybox.setInt("skybox", 0);
	skybox.setMat4("view", view);
	skybox.setMat4("projection", projection);
	GL(glBindVertexArray(skyboxVAO));
	GL(glActiveTexture(GL_TEXTURE0));
	GL(glBindTexture(GL_TEXTURE_CUBE_MAP, skyboxTextureID));
	GL(glDrawArrays(GL_TRIANGLES, 0, 36));
	GL(glBindVertexArray(0));
}

void Renderer::renderScene()
{
	Renderer::renderSceneSkybox();
	Renderer::renderSceneObjects();
}

void Renderer::renderGUI()
{
	//
}

void Renderer::initSkybox()
{
	int	width;
	int	height;
	int	nrChannels;

	Renderer::skybox = Shader("assets/shaders/skybox.vs", "assets/shaders/skybox.fs");
	GL(glGenVertexArrays(1, &skyboxVAO));
	GL(glGenBuffers(1, &skyboxVBO));
	GL(glBindVertexArray(skyboxVAO));
	GL(glBindBuffer(GL_ARRAY_BUFFER, skyboxVBO));
	GL(glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW));
	GL(glEnableVertexAttribArray(0));
	GL(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0));
	GL(glGenTextures(1, &skyboxTextureID));
	GL(glBindTexture(GL_TEXTURE_CUBE_MAP, skyboxTextureID));
	for (unsigned int i = 0; i < skyboxFaces.size(); i++)
	{
		unsigned char* data = stbi_load(skyboxFaces[i].c_str(), &width, &height, &nrChannels, 0);
		if (data)
		{
			GL(glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data));
			stbi_image_free(data);
		}
		else
		{
			std::cout << "Cubemap texture failed to load at path: " << skyboxFaces[i] << std::endl;
			stbi_image_free(data);
		}
	}
	GL(glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
	GL(glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
	GL(glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
	GL(glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));
	GL(glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE));
}

void Renderer::init()
{
    if (!glfwInit())
    {
        cout << "GLFW init error" << endl;
        exit(EXIT_FAILURE);
    }
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    Renderer::_window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Sandbox", NULL, NULL);
    if (!Renderer::window())
    {
        Renderer::destroy();
        cout << "GLFW window error" << endl;
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(Renderer::window());
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        cout << "GLAD load error" << endl;
        exit(EXIT_FAILURE);
    }
	GL(glEnable(GL_DEPTH_TEST));
	GL(glDepthMask(GL_TRUE));
	GL(glDepthFunc(GL_LEQUAL));
	GL(glDepthRange(0.0f, 1.0f));
	Renderer::initSkybox();
	Renderer::initTexture();
	cout << "OpenGL v." << glGetString(GL_VERSION) << endl;

	//DEBUG
	Renderer::ourShader = Shader("assets/shaders/shader.vs", "assets/shaders/shader.fs");
}

void Renderer::render()
{
	if (glfwWindowShouldClose(Renderer::window())) { exit(0); }
	GL(glClearColor(0.0f, 0.0f, 0.0f, 0.0f));
	GL(glClearDepth(1.0f));
	GL(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
    Renderer::input();
    Renderer::renderScene();
    Renderer::renderGUI();
    glfwSwapBuffers(Renderer::window());
    glfwPollEvents();
}

void Renderer::destroy()
{
    glfwDestroyWindow(Renderer::window());
    glfwTerminate();
}

GLFWwindow *Renderer::window() { return (Renderer::_window); }

Texture *Renderer::defaultTexture() { return (Renderer::_defaultTexture); }
