#include <iostream>

#include "sandbox.h"

Sandbox::Sandbox()
{
    glfwInit();
    this->window = glfwCreateWindow(500, 500, "Sandbox", NULL, NULL);
    glfwMakeContextCurrent(this->window);
    return;
}

Sandbox::~Sandbox()
{
    glfwTerminate();
    return;
}

void Sandbox::render(Mesh m)
{
    Vector3 v;

    {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.4, 0.4, 0.4);
        glBegin(GL_POLYGON);
            glVertex2f(-1.0, -1.0);
            glVertex2f(1.0, -1.0);
            glVertex2f(1.0, 1.0);
            glVertex2f(-1.0, 1.0);
        glEnd();
    }
    m.position.z += 10;
    for  (int i = 0; i < m.triangles.length() / 3; i++)
    {
        glBegin(GL_TRIANGLES);
        glColor3f(0.5,0,0);
        glVertex2f(
            this->camera.position.z / m.verticies.get(m.triangles.get(i * 3)).z * m.verticies.get(m.triangles.get(i * 3)).x + this->camera.position.x,
            this->camera.position.z / m.verticies.get(m.triangles.get(i * 3)).z * m.verticies.get(m.triangles.get(i * 3)).y + this->camera.position.y
            );
        glVertex2f(
            this->camera.position.z / m.verticies.get(m.triangles.get(i * 3 + 1)).z * m.verticies.get(m.triangles.get(i * 3 + 1)).x + this->camera.position.x,
            this->camera.position.z / m.verticies.get(m.triangles.get(i * 3 + 1)).z * m.verticies.get(m.triangles.get(i * 3 + 1)).y + this->camera.position.y
            );
        glVertex2f(
            this->camera.position.z / m.verticies.get(m.triangles.get(i * 3 + 2)).z * m.verticies.get(m.triangles.get(i * 3 + 2)).x + this->camera.position.x,
            this->camera.position.z / m.verticies.get(m.triangles.get(i * 3 + 2)).z * m.verticies.get(m.triangles.get(i * 3 + 2)).y + this->camera.position.y
            );
        glEnd();
    }
    glFlush();
    glfwSwapBuffers(window);
    glfwPollEvents(); 
}