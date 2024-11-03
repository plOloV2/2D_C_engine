#include <GLFW/glfw3.h>
#include <stdio.h>

#define MIN_WINDOWS_HEIGHT 600
#define MIN_WINDOWS_WIDTH 600


void errorCallback(int error, const char* description) {
    fprintf(stderr, "Error: %s\n", description);
}

GLFWwindow* windowCreation(){
    // Initialize GLFW
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return NULL;
    }

    glfwSetErrorCallback(errorCallback);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Get the primary monitor
    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    if (!monitor) {
        fprintf(stderr, "Failed to get primary monitor\n");
        glfwTerminate();
        return NULL;
    }

    // Get monitor video mode for resolution
    const GLFWvidmode* mode = glfwGetVideoMode(monitor);
    if (!mode) {
        fprintf(stderr, "Failed to get video mode\n");
        glfwTerminate();
        return NULL;
    }

    if(mode->height < MIN_WINDOWS_HEIGHT || mode->width < MIN_WINDOWS_WIDTH)
        return NULL;

    // Create a fullscreen window
    GLFWwindow* window = glfwCreateWindow(mode->width, mode->height, "PUR game", monitor, NULL);
    if (!window) {
        fprintf(stderr, "Failed to create window\n");
        glfwTerminate();
        return NULL;
    }

}