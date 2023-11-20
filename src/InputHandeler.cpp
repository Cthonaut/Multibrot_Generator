#include "InputHandeler.h"

InputHandeler::InputHandeler(GLFWwindow* win)
{
	window = win;
	zoom = 1;
	pos[0] = 0;
	pos[1] = 0;
}

void InputHandeler::InputHaldeling(double dt, float width, float height)
{
	res[0] = width;
	res[1] = height;

	glfwSetWindowUserPointer(window, this);

    glfwSetMouseButtonCallback(window, [](GLFWwindow* win, int button, int action, int mods) {
        InputHandeler* inputHandlerInstance = static_cast<InputHandeler*>(glfwGetWindowUserPointer(win));
        if (inputHandlerInstance != nullptr) {
            inputHandlerInstance->mouse_button_callback(win, button, action, mods);
        }
    });

    glfwSetScrollCallback(window, [](GLFWwindow* win, double xoffset, double yoffset) {
        InputHandeler* inputHandlerInstance = static_cast<InputHandeler*>(glfwGetWindowUserPointer(win));
        if (inputHandlerInstance != nullptr) {
            inputHandlerInstance->scroll_callback(win, xoffset, yoffset);
        }
    });

	glfwSetCursorPosCallback(window, [](GLFWwindow* win, double xoffset, double yoffset) {
        InputHandeler* inputHandlerInstance = static_cast<InputHandeler*>(glfwGetWindowUserPointer(win));
        if (inputHandlerInstance != nullptr) {
            inputHandlerInstance->cursor_position_callback(win, xoffset, yoffset);
        }
    });

	processInput_keyboard(window, pos, dt);
}

void InputHandeler::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	mouse_pos[0] = xpos/res[0];
	mouse_pos[1] = ypos/res[1];
}


void InputHandeler::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
	}
}

void InputHandeler::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	if(zoom > 0.1 || yoffset > 0)
	{
		zoom += yoffset*zoom/8;
	}	
}

void InputHandeler::processInput_keyboard(GLFWwindow* window, float* pos, double dt)
{
	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}

	if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		pos[1] += dt/zoom;
	}
	else if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		pos[1] -= dt/zoom;
	}

	if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		pos[0] += dt/zoom;
	}
	else if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		pos[0] -= dt/zoom;
	}
}
