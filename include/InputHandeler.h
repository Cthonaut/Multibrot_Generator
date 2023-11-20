#ifndef __InputHandeler_H_
#define __InputHandeler_H_

#include<GLFW/glfw3.h>
#include<iostream>

class InputHandeler
{
	GLFWwindow* window;

public:
	float zoom;
	float pos[2];
	float res[2];
	double mouse_pos[2];

	InputHandeler(GLFWwindow* win);
	void InputHaldeling(double dt, float width, float height);
private:
	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
	void processInput_keyboard(GLFWwindow* window, float* pos, double dt);
	void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
};

#endif