#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <vector>
#include <iostream>

#define MAX_BONE_INFLUENCE 4;

namespace hollow {
	namespace Utils {
		struct Vertex {
			glm::vec3 Position;
			glm::vec3 Normal;
			glm::vec3 TexCoords;
			glm::vec2 Tangent;
			glm::vec3 Bitangent;
			//int BoneID[MAX_BONE_INFLUENCE];
			//float Weights[MAX_BONE_INFLUENCE];
		};

		struct VAO {
			GLuint ID = 0;
		};

		struct VBO {
			GLuint ID = 0;
			std::vector<float> vertices;
		};

		struct EBO {
			GLuint ID = 0;
			std::vector<unsigned int> indices;
		};

		// VAO
		void createVAO(VAO& vao);
		void bindVAO(VAO& vao);
		void vertexAttribPointer(GLuint layout, GLint nrComp, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer);
		void unbindVAO();
		void deleteVAO(VAO& vao);

		// VBO
		void createVBO(VBO& vbo, const std::vector<Vertex> vertices);
		void createVBO(VBO& vbo, const std::vector<float> vertices);
		void bindVBO(VBO& vbo, const std::vector<Vertex> vertices);
		void bindVBO(VBO& vbo, const std::vector<float> vertices);
		void unbindVBO();
		void deleteVBO(VBO& vbo);

		// EBO
		void createEBO(EBO& ebo, const std::vector<unsigned int> indices);
		void bindEBO(EBO& ebo, const std::vector<unsigned int> indices);
		void unbindEBO();
		void deleteEBO(EBO& ebo);

	}
}

