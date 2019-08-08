//#include <iostream>

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
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) { }
    else if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) { }
    else if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) { }
    else if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) { }
    else if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) { }
    else if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) { }
    else if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS) { }
    else if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS) { }
    else if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS) { }
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

    bool b = false;
    ImGui::Begin("Debug", &b);
    ImGui::Text(("Delta Time: " + std::to_string(this->deltaTime())).c_str());
    ImGui::End();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
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
    this->window = glfwCreateWindow(1280, 720, "Sandbox", NULL, NULL);
    if (!window)
    {
        this->closeWindow();
        std::cout << "GLFW window error" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(this->window);
    glewInit();
    
    ImGui::CreateContext();
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(this->window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
}

void Sandbox::closeWindow()
{
    glfwDestroyWindow(this->window);
    glfwTerminate();

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void Sandbox::render()
{
    double t;

    t = this->time();
    glfwPollEvents();
    this->renderClear();
    this->renderBackground();
    this->renderGUI();
    glFlush();
    glfwSwapBuffers(this->window);
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
