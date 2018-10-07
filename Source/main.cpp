#include <iostream>
#include <GL/glew.h>

#if ENABLE_VULKAN
    #include <vulkan/vulkan.h>
#endif

int main(int argc, char **argv)
{
    std::cout << "Hello Meson\n";
    return 0;
}
