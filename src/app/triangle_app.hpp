#pragma once

#include <interfaces/vulkan_app.hpp>

#include <string>
#include <memory>

class GLFWwindow;

class TriangleApp : public VulkanApp
{
public:
    TriangleApp(uint32_t w = 800, uint32_t h = 600, const std::string &windowName = "Vulkan Window");

    void Run() override;

private:
    void initApplication();

    void mainLoop();

    void cleanup();

private:
    std::shared_ptr<GLFWwindow> window_;
    const uint32_t w_;
    const uint32_t h_;
    const std::string windowName_;
};
