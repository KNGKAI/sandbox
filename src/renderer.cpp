#include "renderer.h"
#include "sandbox.h"
#include "filesystem.h"

GLFWwindow *Renderer::_window = nullptr;

vec3 Renderer::sun = vec3(-0.3, -0.4, 0.2);

Shader Renderer::ourShader("shaders/fragment.shader", "shaders/vertex.shader");

Model Renderer::ourModel(FileSystem::getPath("mesh/cugbe.obj"));

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

void Renderer::renderSceneObject(const IObject &object, const Shader &shader)
{
	if (object.model.enabled)
	{
		//
	}
}

void Renderer::renderSceneObjects()
{
	IObject *obj;

	for (auto i = Sandbox::scene()->objects()->begin(); i != Sandbox::scene()->objects()->begin(); i++)
	{
		obj = *i;
	}
	
}

void Renderer::renderScene()
{
	//Renderer::ourModel.Draw(Renderer::ourShader);
	//Renderer::renderSceneObjects();
}

void Renderer::renderGUI()
{
	//
}

int Renderer::compileShader(const std::string &src, unsigned int type)
{
	unsigned int i = glCreateShader(type);
	const char *s = src.c_str();
	glShaderSource(i, 1, &s, nullptr);
	glCompileShader(i);
	return (i);
}

unsigned int Renderer::createShader(const std::string &vertexShader, const std::string &fragShader)
{
	unsigned int program = glCreateProgram();
	unsigned int vs = Renderer::compileShader(vertexShader, GL_VERTEX_SHADER);
	unsigned int fs = Renderer::compileShader(fragShader, GL_FRAGMENT_SHADER);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);
	glDeleteShader(vs);
	glDeleteShader(fs);
	return (program);
}

std::string Renderer::loadShader(const std::string path)
{
	std::ifstream file(path);
	std::string shader;
	std::string line;

	shader = "";
	while (std::getline(file, line)) { shader += line + "\n"; }
	return (shader);
}

void Renderer::init()
{
    if (!glfwInit())
    {
        std::cout << "GLFW init error" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    Renderer::_window = glfwCreateWindow(1280, 720, "Sandbox", NULL, NULL);
    if (!Renderer::window())
    {
        Renderer::destroy();
        std::cout << "GLFW window error" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(Renderer::window());
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "GLAD error" << std::endl;
        std::exit(0);
    }
}

void Renderer::render()
{
	if (glfwWindowShouldClose(Renderer::window())) { std::exit(0); }
    glClear(GL_COLOR_BUFFER_BIT);
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
