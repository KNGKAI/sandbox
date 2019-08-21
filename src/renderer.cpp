#include "renderer.h"
#include "sandbox.h"
#include <fstream>

GLFWwindow *Renderer::_window = nullptr;

Vector3 Renderer::sun = Vector3(-0.3, -0.4, 0.2);

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

void Renderer::renderSceneObject(IEntity *object)
{
	Vector3 a;
	Vector3 b;
	Vector3 c;
	Vector3 d;
	Vector3 sun;
	double t;

	if (object->mesh.enabled)
	{
		glColor3f(object->mesh.color.x, object->mesh.color.y, object->mesh.color.z);
		for (int j = 0; j < object->mesh.triangles.length(); j += 3)
		{
			d = object->transform.position - Camera::transform.position;
			a = Vector3::Rotate(
				Vector3::Rotate(
					object->mesh.verticies.get(object->mesh.triangles.get(j)),
					object->transform.rotation) + d,
				Camera::transform.rotation);
			b = Vector3::Rotate(
				Vector3::Rotate(
					object->mesh.verticies.get(object->mesh.triangles.get(j + 1)),
					object->transform.rotation) + d,
				Camera::transform.rotation);
			c = Vector3::Rotate(
				Vector3::Rotate(
					object->mesh.verticies.get(object->mesh.triangles.get(j + 2)),
					object->transform.rotation) + d,
				Camera::transform.rotation);
			d = Vector3::TriangleNormal(a, b, c);
			t = Vector3::angleBetween(d, Renderer::sun) / 180;
			a = Vector3::ToScreenSpace(a);
			b = Vector3::ToScreenSpace(b);
			c = Vector3::ToScreenSpace(c);
			d = Vector3::TriangleNormal(a, b, c);
			if (d.z < 0)
			{
				switch (object->mesh.renderType)
				{
				case RENDER_NONE: break;
				case RENDER_STANDARD:
					glColor3f(object->mesh.color.x * t, object->mesh.color.y * t, object->mesh.color.z * t);
					glBegin(GL_TRIANGLE_FAN);
					glVertex2f((GLfloat)a.x, (GLfloat)a.y);
					glVertex2f((GLfloat)b.x, (GLfloat)b.y);
					glVertex2f((GLfloat)c.x, (GLfloat)c.y);
					glEnd();
					break;
				case RENDER_WIRE:
					glBegin(GL_LINES);
					glVertex2f((GLfloat)a.x, (GLfloat)a.y);
					glVertex2f((GLfloat)b.x, (GLfloat)b.y);
					glEnd();
					glBegin(GL_LINES);
					glVertex2f((GLfloat)b.x, (GLfloat)b.y);
					glVertex2f((GLfloat)c.x, (GLfloat)c.y);
					glEnd();
					glBegin(GL_LINES);
					glVertex2f((GLfloat)c.x, (GLfloat)c.y);
					glVertex2f((GLfloat)a.x, (GLfloat)a.y);
					glEnd();
					break;
				default: break;
				}
			}
		}
	}
}

void Renderer::renderSceneObjects()
{
	List<IEntity *> *objects;

	objects = Sandbox::scene()->objects();
	for (int i = 0; i < objects->length(); i++)
	{
		Renderer::renderSceneObject(objects->get(i));
	}
}

void Renderer::renderSceneGrid()
{
	Vector3 a;
	Vector3 b;
	int raduis;

	raduis = 8;
	glColor3f(0.5, 0.5, 0.5);
	for (int x = -raduis; x <= raduis; x++)
	{
		a.x = x;
		b.x = x;
		a.y = 0;
		b.y = 0;
		a.z = -raduis;
		b.z = raduis;
		a = Vector3::ToScreenSpace(Vector3::Rotate(a - Camera::transform.position, Camera::transform.rotation));
		b = Vector3::ToScreenSpace(Vector3::Rotate(b - Camera::transform.position, Camera::transform.rotation));
		glBegin(GL_LINES);
		glVertex2f((GLfloat)a.x, (GLfloat)a.y);
		glVertex2f((GLfloat)b.x, (GLfloat)b.y);
		glEnd();
	}
	for (int y = -raduis; y <= raduis; y++)
	{
		a.x = -raduis;
		b.x = raduis;
		a.y = 0;
		b.y = 0;
		a.z = y;
		b.z = y;
		a = Vector3::ToScreenSpace(Vector3::Rotate(a - Camera::transform.position, Camera::transform.rotation));
		b = Vector3::ToScreenSpace(Vector3::Rotate(b - Camera::transform.position, Camera::transform.rotation));
		glBegin(GL_LINES);
		glVertex2f((GLfloat)a.x, (GLfloat)a.y);
		glVertex2f((GLfloat)b.x, (GLfloat)b.y);
		glEnd();
	}
	a = Vector3::ToScreenSpace(Vector3::Rotate(Vector3(0, 0, 0)- Camera::transform.position, Camera::transform.rotation));
	b = Vector3::ToScreenSpace(Vector3::Rotate(Vector3::Normalized(Renderer::sun) - Camera::transform.position, Camera::transform.rotation));
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f((GLfloat)a.x, (GLfloat)a.y);
	glVertex2f((GLfloat)b.x, (GLfloat)b.y);
	glEnd();

}

void Renderer::renderScene()
{
	Renderer::renderSceneGrid();
	Renderer::renderSceneObjects();
}

void Renderer::renderGUIDebug()
{
	bool a = false;
	std::string type;

	ImGui::Begin("Debug", &a);
	ImGui::Text(("FPS: " + std::to_string((int)(1 / Sandbox::deltaTime()))).c_str());
	ImGui::Text(("Delta Time: " + std::to_string(Sandbox::deltaTime())).c_str());
	ImGui::Text("-----");
	ImGui::Text("Scene");
	ImGui::Text(("\tName: " + Sandbox::scene()->name()).c_str());
	ImGui::Text(("\tCamera:\n\t\tpos x:" + std::to_string(Camera::transform.position.x) + "pos y : " + std::to_string(Camera::transform.position.y) + " pos z : " + std::to_string(Camera::transform.position.z) + "\n\t\trot x:" + std::to_string(Camera::transform.rotation.x) + " rot y : " + std::to_string(Camera::transform.rotation.y) + " rot z : " + std::to_string(Camera::transform.rotation.z) + "\n\t\tsur x : " + std::to_string(Camera::surface.x) + " sur y : " + std::to_string(Camera::surface.y)).c_str());
	ImGui::Text("Objects:");;
	for (int i = 0; i < Sandbox::scene()->objects()->length(); i++)
	{
		IEntity *obj = Sandbox::scene()->objects()->get(i);
		if (ImGui::BeginMenu(obj->name().c_str(), true))
		{
			ImGui::Text(("pos x:" + std::to_string(obj->transform.position.x) + ":y:" + std::to_string(obj->transform.position.y) + ":z:" + std::to_string(obj->transform.position.z)).c_str());
			ImGui::Text(("rot x:" + std::to_string(obj->transform.rotation.x) + ":y:" + std::to_string(obj->transform.rotation.y) + ":z:" + std::to_string(obj->transform.rotation.z)).c_str());
			if (obj->rigidbody.enabled)
			{
				ImGui::Text("Rigidbody");
				ImGui::Text(("mass:" + std::to_string(obj->rigidbody.mass)).c_str());
				ImGui::Text(("vel x:" + std::to_string(obj->rigidbody.velocity.x) + ":y:" + std::to_string(obj->rigidbody.velocity.y) + ":z:" + std::to_string(obj->rigidbody.velocity.z)).c_str());
			}
			ImGui::EndMenu();
		}
	}
	std::string keys = "Keys: ";
	for (int j = 0; j < Input::keys()->length(); j++) { keys += std::to_string(Input::keys()->get(j)->val) + " (" + std::to_string(Input::keys()->get(j)->state) + "), "; }
	ImGui::Text(keys.c_str());
	ImGui::End();
}

void Renderer::renderGUI()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    Renderer::renderGUIDebug();
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
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
#if __APPLE__ // GL 3.2 + GLSL 150
    const char* glsl_version = "#version 150";
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
#else // GL 3.0 + GLSL 130
    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only
#endif
    Renderer::_window = glfwCreateWindow(1280, 720, "Sandbox", NULL, NULL);
    if (!Renderer::window())
    {
        Renderer::destroy();
        std::cout << "GLFW window error" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(Renderer::window());
#ifndef __APPLE__
    glewInit();    
    ImGui::CreateContext();
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(Renderer::window(), true);
    ImGui_ImplOpenGL3_Init(glsl_version);
#endif
}

void Renderer::render()
{
	if (glfwWindowShouldClose(Renderer::window())) { std::exit(0); }
    glClear(GL_COLOR_BUFFER_BIT);
    Renderer::input();
    Renderer::renderScene();
#ifndef __APPLE__
    Renderer::renderGUI();
#endif
    glfwSwapBuffers(Renderer::window());
    glfwPollEvents();
}

void Renderer::destroy()
{
    glfwDestroyWindow(Renderer::window());
    glfwTerminate();
#ifndef __APPLE__
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
#endif
}

GLFWwindow *Renderer::window() { return (Renderer::_window); }
