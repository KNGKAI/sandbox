#include "renderer.h"
#include "sandbox.h"

GLFWwindow *Renderer::_window = nullptr;

void Renderer::input()
{
    if (glfwGetKey(Renderer::window(), GLFW_KEY_ESCAPE) == GLFW_PRESS) { std::exit(0); }
    if (glfwGetKey(Renderer::window(), GLFW_KEY_UP) == GLFW_PRESS) { Input::press(Key_Up); }
    if (glfwGetKey(Renderer::window(), GLFW_KEY_DOWN) == GLFW_PRESS) { Input::press(Key_Down); }
    if (glfwGetKey(Renderer::window(), GLFW_KEY_LEFT) == GLFW_PRESS) { Input::press(Key_Left); }
    if (glfwGetKey(Renderer::window(), GLFW_KEY_RIGHT) == GLFW_PRESS) { Input::press(Key_Right); }
}

void Renderer::renderScene()
{
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-1.0, -1.0);
    glVertex2f(1.0, -1.0);
    glVertex2f(-1.0, 1.0);
    glEnd();
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
    ImGui::Text("\tObjects:");
    for (int i = 0; i < Sandbox::scene()->objects()->length(); i++) { ImGui::Text(("\t\t" + Sandbox::scene()->objects()->get(i)->name()).c_str()); }
    std::string keys = "Keys: ";
    for (int j = 0; j < Input::keys()->length(); j++) { keys += std::to_string(Input::keys()->get(j)->val) + " (" + std::to_string(Input::keys()->get(j)->state) + "), "; }
    ImGui::Text(keys.c_str());
    ImGui::End();
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
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    Renderer::input();
    Renderer::renderScene();
    Renderer::renderGUI();
    glfwPollEvents();
    glfwSwapBuffers(Renderer::window());
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
