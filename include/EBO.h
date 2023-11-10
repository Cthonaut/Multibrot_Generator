#ifndef EBO_H_
#define EBO_H_

#include <glad/glad.h>

class EBO
{
	GLuint ID;
	
public:

	EBO(GLuint* indices, GLsizeiptr size);

	void Bind();
	void Unbind();
	void Delete();
};

#endif

