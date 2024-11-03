#include "../lib/graphic.h"
#include <math.h>

GLFWwindow* window = NULL;

int main() {
    
    window = windowCreation();

    if(window == NULL)
        return 1;

    glfwMakeContextCurrent(window);

    int width, height;
    float ratio;

    while (!glfwWindowShouldClose(window)) {

        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float)height;

        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);


        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}