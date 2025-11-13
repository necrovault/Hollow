#pragma once

#include <glad/glad.h>

#include <glm/common.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <hollow/Logger.h>
#include <hollow/FileManager.h>

#include <string>
#include <iostream>

namespace hollow {
	class Shader {
	public:
		Shader(const std::string vertexPath, std::string fragmentPath);
		~Shader();

		void use();
		int load();
		
		// utility functions
		void setBool(const std::string name, bool value) const;
		void setInt(const std::string name, int value) const;
		void setFloat(const std::string name, float value) const;
		void setVec2(const std::string name, glm::vec2 vector) const;
		void setVec2(const std::string name, float x, float y) const;
		void setVec3(const std::string name, glm::vec3 vector) const;
		void setVec3(const std::string name, float x, float y, float z) const;
		void setVec4(const std::string name, glm::vec4 vector) const;
		void setVec4(const std::string name, float x, float y, float z, float w) const;
		void setMat2(const std::string name, glm::mat2 matrix) const;
		void setMat3(const std::string name, glm::mat3 matrix) const;
		void setMat4(const std::string name, glm::mat4 matrix) const;

		unsigned int ID;
		std::string vertexPath;
		std::string fragmentPath;

	private:
		void checkForErrors(GLuint shader, std::string type);
	};
}

