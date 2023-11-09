#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

int main()
{

	glfwInit();// Initialize GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow* window = glfwCreateWindow(800, 800, "Multibrot_Generator", NULL, NULL);
	if (window == NULL)// Error check
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);// Introduce the window into the current context

	gladLoadGL();//Load GLAD
	glViewport(0, 0, 800, 800);// Specify the viewport
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);

	//Main loop
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	}

	// closing statements
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}