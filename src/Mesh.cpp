#include <hollow/Mesh.h>

hollow::Mesh::Mesh(std::vector<Utils::Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture::TextureData> textures) {
	
	this->vertices = vertices;
	this->indices = indices;
	this->textures = textures;

	setupMesh();
}

void hollow::Mesh::draw(Shader& shader) {

	unsigned int diffuseNr = 1;
	unsigned int specularNr = 1;

	for (unsigned int i = 0; i < textures.size(); i++) {
		glActiveTexture(GL_TEXTURE0 + i);

		std::string number;
		std::string name = textures[i].type;

		if (name == "textures_diffuse")
			number = std::to_string(diffuseNr++);
		else if (name == "textures_specular")
			number = std::to_string(specularNr++);

		shader.setInt(("material." + name + number).c_str(), i);
		Texture::bind(textures[i]);
	}

	glActiveTexture(GL_TEXTURE0);
	Utils::bindVAO(vao);
	glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(indices.size()), GL_UNSIGNED_INT, 0);
	Utils::unbindVAO();
}

hollow::Mesh::~Mesh() {
	
	Utils::deleteVAO(vao);
	Utils::deleteVBO(vbo);
	Utils::deleteEBO(ebo);

}


void hollow::Mesh::setupMesh() {
	
	Utils::createVAO(vao);
	Utils::createVBO(vbo, vertices);
	Utils::createEBO(ebo, indices);

	Utils::bindVAO(vao);
	Utils::bindVBO(vbo, vertices);
	Utils::bindEBO(ebo, indices);

	Utils::vertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Utils::Vertex), (void*)0);
	Utils::vertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Utils::Vertex), (void*)offsetof(Utils::Vertex, Normal));
	Utils::vertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Utils::Vertex), (void*)offsetof(Utils::Vertex, TexCoords));
	Utils::vertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Utils::Vertex), (void*)offsetof(Utils::Vertex, Tangent));
	Utils::vertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Utils::Vertex), (void*)offsetof(Utils::Vertex, Bitangent));
}
