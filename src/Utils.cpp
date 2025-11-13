#include <hollow/Utils.h>

void hollow::Utils::createVAO(VAO& vao) {
	glGenVertexArrays(1, &vao.ID);
}

void hollow::Utils::bindVAO(VAO& vao) {
	glBindVertexArray(vao.ID);
}

void hollow::Utils::vertexAttribPointer(GLuint layout, GLint nrComp, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer) {
	glVertexAttribPointer(layout, nrComp, type, normalized, stride, pointer);
	glEnableVertexAttribArray(layout);
}

void hollow::Utils::unbindVAO() {
	glBindVertexArray(0);
}

void hollow::Utils::deleteVAO(VAO& vao) {
	glDeleteVertexArrays(1, &vao.ID);
}

void hollow::Utils::createVBO(VBO& vbo, const std::vector<Vertex> vertices) {
	glGenBuffers(1, &vbo.ID);
}

void hollow::Utils::createVBO(VBO& vbo, const std::vector<float> vertices) {
	glGenBuffers(1, &vbo.ID);
}

void hollow::Utils::bindVBO(VBO& vbo, const std::vector<Vertex> vertices) {
	glBindBuffer(GL_ARRAY_BUFFER, vbo.ID);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);
}

void hollow::Utils::bindVBO(VBO& vbo, const std::vector<float> vertices) {
	glBindBuffer(GL_ARRAY_BUFFER, vbo.ID);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
}

void hollow::Utils::unbindVBO() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void hollow::Utils::deleteVBO(VBO& vbo) {
	glDeleteBuffers(1, &vbo.ID);
}

void hollow::Utils::createEBO(EBO& ebo, const std::vector<unsigned int> indices) {
	glGenBuffers(1, &ebo.ID);
}

void hollow::Utils::bindEBO(EBO& ebo, const std::vector<unsigned int> indices) {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo.ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(indices), &indices[0], GL_STATIC_DRAW);
}

void hollow::Utils::unbindEBO() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void hollow::Utils::deleteEBO(EBO& ebo) {
	glDeleteBuffers(1, &ebo.ID);
}
