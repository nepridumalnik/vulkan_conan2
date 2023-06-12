#include <app/triangle_app.hpp>

#include <app/glfw_context.hpp>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

TriangleApp::TriangleApp(uint32_t w, uint32_t h, const std::string &windowName)
    : w_{w}, h_{h}, windowName_{windowName}
{
    GlfwContext::Instance();
}

void TriangleApp::Run()
{
    initApplication();
    mainLoop();
    cleanup();
}

void TriangleApp::initApplication()
{
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
}

void TriangleApp::mainLoop()
{
    window_ =
        std::shared_ptr<GLFWwindow>(
            glfwCreateWindow(w_, h_, windowName_.c_str(), nullptr, nullptr),
            glfwDestroyWindow);

    while (!glfwWindowShouldClose(window_.get()))
    {
        glfwPollEvents();
    }
}

void TriangleApp::cleanup()
{
    window_.reset();
}
