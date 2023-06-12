#include <app/triangle_app.hpp>

#include <stdexcept>
#include <iostream>

int main(int argc, char const *argv[])
{
    try
    {
        TriangleApp app;
        app.Run();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "Unknown error" << std::endl;
    }

    return 0;
}
