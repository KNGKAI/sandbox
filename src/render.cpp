#include <iostream>
#include "render.h"
#include "sandbox.h"

Render::Render() { return; }

Render::~Render() { return; }

GLFWwindow *Render::_window = nullptr;

void Render::input()
{
    if (glfwGetKey(Render::window(), GLFW_KEY_ESCAPE) == GLFW_PRESS) { std::exit(0); }
    if (glfwGetKey(Render::window(), GLFW_KEY_UP) == GLFW_PRESS) { Input::press(Key_Up); }
    if (glfwGetKey(Render::window(), GLFW_KEY_DOWN) == GLFW_PRESS) { Input::press(Key_Down); }
    if (glfwGetKey(Render::window(), GLFW_KEY_LEFT) == GLFW_PRESS) { Input::press(Key_Left); }
    if (glfwGetKey(Render::window(), GLFW_KEY_RIGHT) == GLFW_PRESS) { Input::press(Key_Right); }
}

void Render::renderGUI()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    Render::renderDebug();
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void Render::renderDebug()
{
    bool a = false;
    std::string type;

    ImGui::Begin("Debug", &a);
    ImGui::Text(("FPS: " + std::to_string((int)(1 / Sandbox::deltaTime()))).c_str());
    ImGui::Text(("Delta Time: " + std::to_string(Sandbox::deltaTime())).c_str());
    ImGui::Text("-----");
    ImGui::Text("Scene");
    ImGui::Text(("\tName: " + Sandbox::scene()->name()).c_str());
    ImGui::Text("\tObjects:");
    for (int i = 0; i < Sandbox::scene()->objects()->length(); i++)
    {
        type = "-unknown-";
        switch (Sandbox::scene()->objects()->get(i).type())
        {
            case T_Object: type = "Object"; break;
            case T_Transform: type = "Tranform"; break;
            case T_Mesh: type = "Mesh"; break;
        }
        ImGui::Text(("\t\t" + type + " name: " + Sandbox::scene()->objects()->get(i).name()).c_str());
    }
    std::string keys = "Keys: ";
    for (int j = 0; j < Input::keys()->length(); j++)
    {
        keys += std::to_string(Input::keys()->get(j)->val) + " (" + std::to_string(Input::keys()->get(j)->state) + "), ";
    }
    ImGui::Text(keys.c_str());
    ImGui::End();
}

void Render::init()
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
    Render::_window = glfwCreateWindow(1280, 720, "Sandbox", NULL, NULL);
    if (!Render::window())
    {
        Render::destroy();
        std::cout << "GLFW window error" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(Render::window());
    glewInit();    
    ImGui::CreateContext();
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(Render::window(), true);
    ImGui_ImplOpenGL3_Init(glsl_version);
}

void Render::render()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glfwPollEvents();
    Render::input();
    Render::renderGUI();
    glFlush();
    glfwSwapBuffers(Render::window());
}

void Render::destroy()
{
    glfwDestroyWindow(Render::window());
    glfwTerminate();
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

GLFWwindow *Render::window()
{
    return (Render::_window);
}
