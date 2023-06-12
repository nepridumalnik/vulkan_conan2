#pragma once

class GlfwContext
{
public:
    ~GlfwContext();

    static GlfwContext &Instance();

private:
    GlfwContext();
};
