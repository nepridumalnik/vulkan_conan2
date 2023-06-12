#include <app/glfw_context.hpp>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <stdexcept>

GlfwContext::GlfwContext()
{
    if (glfwInit() != GLFW_TRUE)
    {
        throw std::runtime_error{"Failed to initializw glfw"};
    }
}

GlfwContext::~GlfwContext()
{
    glfwTerminate();
}

GlfwContext &GlfwContext::Instance()
{
    static GlfwContext context;
    return context;
}
