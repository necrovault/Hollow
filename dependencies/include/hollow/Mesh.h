#pragma once

#include <glm/glm.hpp>
#include <hollow/Shader.h>
#include <hollow/Utils.h>
#include <hollow/Texture.h>

#include <vector>
#include <iostream>

#define MAX_BONE_INFLUENCE 4;

namespace hollow {
	class Mesh {
	public:
		std::vector<Utils::Vertex> vertices;
		std::vector<unsigned int> indices;
		std::vector<Texture::TextureData> textures;

		Mesh(std::vector<Utils::Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture::TextureData> textures);
		void draw(Shader& shader);
		~Mesh();

	private:
		Utils::VAO vao;
		Utils::VBO vbo;
		Utils::EBO ebo;
		void setupMesh();
	};
}

