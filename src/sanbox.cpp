#include <iostream>

#include "sandbox.h"

Sandbox::Sandbox()
{
    this->openWindow();
    return;
}

Sandbox::~Sandbox()
{
    this->closeWindow();
    return;
}

void Sandbox::input()
{
    if (glfwGetKey(this->_window, GLFW_KEY_ESCAPE) == GLFW_PRESS) { std::exit(0); }
}

void Sandbox::renderClear()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void Sandbox::renderBackground()
{
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(-1.0, -1.0);
    glVertex2f(1.0, -1.0);
    glVertex2f(1.0, 1.0);
    glVertex2f(-1.0, 1.0);
    glEnd();
}

void Sandbox::renderGUI()
{

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    this->renderDebug();
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void Sandbox::renderDebug()
{
    bool a = false;
    std::string type;

    ImGui::Begin("Debug", &a);
    ImGui::Text(("FPS: " + std::to_string((int)(1 / this->deltaTime()))).c_str());
    ImGui::Text(("Delta Time: " + std::to_string(this->deltaTime())).c_str());
    ImGui::Text("-----");
    ImGui::Text("Scene");
    ImGui::Text(("\tName: " + this->_scene->name()).c_str());
    ImGui::Text("\tObjects:");
    for (int i = 0; i < this->_scene->objects()->length(); i++)
    {
        type = "-unknown-";
        switch (this->_scene->objects()->get(i).type())
        {
            case T_Object: type = "Object"; break;
            case T_Transform: type = "Tranform"; break;
            case T_Mesh: type = "Mesh"; break;
        }
        ImGui::Text(("\t\t" + type + " name: " + this->_scene->objects()->get(i).name()).c_str());
    }
    ImGui::End();
}

void Sandbox::openWindow()
{
    if (!glfwInit())
    {
        std::cout << "GLFW init error" << std::endl;
        std::exit(EXIT_FAILURE);
    }
#if __APPLE__
    // GL 3.2 + GLSL 150
    const char* glsl_version = "#version 150";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
#else
    // GL 3.0 + GLSL 130
    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only
#endif
    this->_window = glfwCreateWindow(1280, 720, "Sandbox", NULL, NULL);
    if (!this->_window)
    {
        this->closeWindow();
        std::cout << "GLFW window error" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(this->_window);
    glewInit();    
    ImGui::CreateContext();
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(this->_window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
}

void Sandbox::closeWindow()
{
    glfwDestroyWindow(this->_window);
    glfwTerminate();
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void Sandbox::process(Scene *scene)
{
    double t;

    t = this->time();
    glfwPollEvents();
    this->_scene = scene;
    this->input();
    this->renderClear();
    this->renderBackground();
    this->renderGUI();
    glFlush();
    glfwSwapBuffers(this->_window);
    this->_deltaTime = this->time() - t;
}

double Sandbox::time()
{
    return (glfwGetTime());
}

double Sandbox::deltaTime()
{
    return (this->_deltaTime);
}
