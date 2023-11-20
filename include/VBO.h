#ifndef VBO_H_
#define VBO_H_

#include <glad/glad.h>
#include <vector>

class VBO
{
	GLuint ID;
	public:

		VBO(std::vector<GLfloat>& vertices);

		void Bind();
		void Unbind();
		void Delete();
};

#endif

