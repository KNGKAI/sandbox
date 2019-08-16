#include "renderer.h"
#include "sandbox.h"
#include <fstream>

GLFWwindow *Renderer::_window = nullptr;

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

void Renderer::renderScene()
{
	IEntity *obj;
	List<double> v;
	int c;

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(1.0, 1.0);
    glVertex2f(1.0, -1.0);
    glVertex2f(-1.0, 1.0);
	glEnd();
	c = 0;
	glColor3f(1.0, 1.0, 1.0);
	for (int i = 0; i < Sandbox::scene()->objects()->length(); i++)
	{
		obj = Sandbox::scene()->objects()->get(i);
//		if (obj->mesh.enabled)
		{
			c += obj->mesh.triangles.length();
			for (int j = 0; j < obj->mesh.triangles.length(); j++)
			{
				Vector3 a = obj->mesh.verticies.get(obj->mesh.triangles.get(j));
				a = Vector3::Rotate(a, obj->transform.rotation) + obj->transform.position;
				a =	Vector3::ToScreenSpace(a);
				v.add(a.y);
				v.add(a.x);
				if (j % 3 == 0)
				{
					glBegin(GL_LINES);
					glVertex2f(a.x, a.y);
					a = obj->mesh.verticies.get(obj->mesh.triangles.get(j + 1));
					a = Vector3::Rotate(a, obj->transform.rotation) + obj->transform.position;
					a = Vector3::ToScreenSpace(a);
					glVertex2f(a.x, a.y);
					glEnd();
					glBegin(GL_LINES);
					glVertex2f(a.x, a.y);
					a = obj->mesh.verticies.get(obj->mesh.triangles.get(j + 2));
					a = Vector3::Rotate(a, obj->transform.rotation) + obj->transform.position;
					a = Vector3::ToScreenSpace(a);
					glVertex2f(a.x, a.y);
					glEnd();
					glBegin(GL_LINES);
					glVertex2f(a.x, a.y);
					a = obj->mesh.verticies.get(obj->mesh.triangles.get(j));
					a = Vector3::Rotate(a, obj->transform.rotation) + obj->transform.position;
					a = Vector3::ToScreenSpace(a);
					glVertex2f(a.x, a.y);
					glEnd();
				}
			}
		}
	}

	glColor4f(0.0, 0.5, 0.0, 0.5);

	double *a = v.to_array();
	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(double) * v.length(), a, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_DOUBLE, GL_FALSE, sizeof(double) * 2, 0);

	std::string vertexShader = Renderer::loadShader("shaders/vertex.shader");
	std::string fragmentShader = Renderer::loadShader("shaders/fragment.shader");
	unsigned int shader = Renderer::createShader(vertexShader, fragmentShader);
	glUseProgram(shader);

	glDrawArrays(GL_TRIANGLES, 0, c);
}

void Renderer::renderGUI()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    Renderer::renderDebug();
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void Renderer::renderDebug()
{
    bool a = false;
    std::string type;

    ImGui::Begin("Debug", &a);
    ImGui::Text(("FPS: " + std::to_string((int)(1 / Sandbox::deltaTime()))).c_str());
    ImGui::Text(("Delta Time: " + std::to_string(Sandbox::deltaTime())).c_str());
    ImGui::Text("-----");
    ImGui::Text("Scene");
	ImGui::Text(("\tName: " + Sandbox::scene()->name()).c_str());
	ImGui::Text(( "\tCamera:\n\t\tpos x:" + std::to_string(Camera::transform.position.x) + "pos y : " + std::to_string(Camera::transform.position.y) + " pos z : " + std::to_string(Camera::transform.position.z) + "\n\t\trot x:" + std::to_string(Camera::transform.rotation.x) + " rot y : " + std::to_string(Camera::transform.rotation.y) + " rot z : " + std::to_string(Camera::transform.rotation.z) + "\n\t\tsur x : " + std::to_string(Camera::surface.x) + " sur y : " + std::to_string(Camera::surface.y)).c_str());
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
	while (std::getline(file, line))
	{
		shader += line + "\n";
	}
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
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
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
    glewInit();    
    ImGui::CreateContext();
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(Renderer::window(), true);
    ImGui_ImplOpenGL3_Init(glsl_version);
}

void Renderer::render()
{
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
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

GLFWwindow *Renderer::window() { return (Renderer::_window); }
