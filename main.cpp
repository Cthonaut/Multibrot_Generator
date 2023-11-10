#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include <math.h>

#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "ShaderClass.h"

int resolution[2] = {1920,1080};
uint frame_rate = 60;

GLfloat vertices[] = 
{
	 1.0f, 1.0f,
	-1.0f, 1.0f,
	-1.0f,-1.0f,
	 1.0f,-1.0f
};

GLuint indices[] = 
{
	0, 1, 2,
	0, 2, 3
};

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window, float* zoom, float* pos, double dt)
{
	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
	
	if(glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS)
	{
		*zoom += *zoom*dt;
	}
	else if(glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS)
	{
		if(*zoom > 0.45f)
		{
			*zoom -= *zoom*dt;
		}
		else
		{
			*zoom = 0.43f;
		}
	}

	if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		pos[1] += dt/(*zoom);
	}
	else if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		pos[1] -= dt/(*zoom);
	}

	if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		pos[0] += dt/(*zoom);
	}
	else if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		pos[0] -= dt/(*zoom);
	}
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
	VBO VBO1(vertices, sizeof(vertices));
	EBO EBO1(indices, sizeof(indices));
	VAO1.LinkVBO(VBO1, 0, 2, GL_FLOAT, 2 * sizeof(float), (void*)0);
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	GLuint resID = glGetUniformLocation(shaderProgram.ID, "resolution");
	GLuint posID = glGetUniformLocation(shaderProgram.ID, "pos");
	GLuint zoomID = glGetUniformLocation(shaderProgram.ID, "zoom");

	//Main varialbes
	float position[2] = {0,0};
	float zoom = 1;

	//Main loop
	while (!glfwWindowShouldClose(window))
	{
		double time = glfwGetTime();
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		shaderProgram.Activate();
		VAO1.Bind();
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

		glUniform2f(resID, resolution[0], resolution[1]);
		glUniform2f(posID, position[0], position[1]);
		glUniform1f(zoomID, zoom);

		glfwGetFramebufferSize(window, &resolution[0], &resolution[1]);

		double delta_time = glfwGetTime() - time;
		while(1/delta_time > frame_rate){delta_time = glfwGetTime() - time;}
		processInput(window, &zoom, position, delta_time);
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