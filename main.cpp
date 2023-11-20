#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include <math.h>
#include <vector>

#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "ShaderClass.h"
#include "InputHandeler.h"

int resolution[2]{1920,1080};
uint frame_rate{60};

std::vector<GLfloat> vertices =
{
	 1.0f, 1.0f,
	-1.0f, 1.0f,
	-1.0f,-1.0f,
	 1.0f,-1.0f
};

std::vector<GLuint> indices =
{
	0, 1, 2,
	0, 2, 3
};

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

int main()
{
	glfwInit();// Initialize GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow* window = glfwCreateWindow(resolution[0], resolution[1], "Multibrot_Generator", NULL, NULL);
	if (window == NULL)// Error check
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);// Introduce the window into the current context

	//Load GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	
	glViewport(0, 0, resolution[0], resolution[1]);// Specify the viewport
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	//shader
	Shader shaderProgram("default.vert", "default.frag");
	
	//VAO EBO AND EBO
	VAO VAO1;
	VAO1.Bind();
	VBO VBO1(vertices);
	EBO EBO1(indices);
	VAO1.LinkVBO(VBO1, 0, 2, GL_FLOAT, 2 * sizeof(float), (void*)0);
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	GLuint resID = glGetUniformLocation(shaderProgram.ID, "resolution");
	GLuint posID = glGetUniformLocation(shaderProgram.ID, "pos");
	GLuint powID = glGetUniformLocation(shaderProgram.ID, "power");
	GLuint zoomID = glGetUniformLocation(shaderProgram.ID, "zoom");

	InputHandeler Input(window);

	//Main varialbes
	float power[2]{3,0};

	//Main loop
	while (!glfwWindowShouldClose(window))
	{
		double time = glfwGetTime();
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		shaderProgram.Activate();
		VAO1.Bind();
		glfwGetFramebufferSize(window, &resolution[0], &resolution[1]);

		glUniform2f(resID, resolution[0], resolution[1]);
		glUniform2f(posID, Input.pos[0], Input.pos[1]);
		glUniform2f(powID, power[0], power[1]);
		glUniform1f(zoomID, Input.zoom);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		double delta_time = glfwGetTime() - time;
		while(1/delta_time > frame_rate){delta_time = glfwGetTime() - time;}

		//Input Handeling
		Input.InputHaldeling(delta_time, resolution[0], resolution[1]);

		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	// closing statements
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	shaderProgram.Delete();
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}