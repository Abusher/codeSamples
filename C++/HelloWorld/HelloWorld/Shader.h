#ifndef  SHADER_H
#define SHADER_H

#include <glad\glad.h>

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>

	class Shader
	{
	public:
		unsigned int ID;

		Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
		void use();

		void setBool(const std::string &name, bool value) const;
		void setInt(const std::string &name, int value) const;
		void setFloat(const std::string &name, float value) const;
		void setMat4(const std::string &name, glm::mat4 value) const;
		void setVec3(const std::string &name, glm::vec3) const;
		void setVec3(const std::string &name, float, float, float) const;
	};
#endif // ! SHADER_H


