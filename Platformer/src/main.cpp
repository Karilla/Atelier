#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>
#include <Application.hpp>

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{

    Application app(SCR_WIDTH, SCR_HEIGHT, "Test");

    app.run();

    return 0;
}
