#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include <stdexcept>
#include <iostream>
#include <memory>

int main(int argc, char const *argv[])
{
    if (glfwInit() != GLFW_TRUE)
    {
        std::cerr << "Failed to initializw glfw" << std::endl;
        return -1;
    }

    try
    {
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        std::shared_ptr<GLFWwindow> window =
            std::shared_ptr<GLFWwindow>(glfwCreateWindow(800, 600, "Vulkan window", nullptr, nullptr), glfwDestroyWindow);

        uint32_t extensionsCount = 0;
        vkEnumerateInstanceExtensionProperties(nullptr, &extensionsCount, nullptr);

        while (!glfwWindowShouldClose(window.get()))
        {
            glfwPollEvents();
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "Unknown error" << std::endl;
    }

    glfwTerminate();

    return 0;
}
