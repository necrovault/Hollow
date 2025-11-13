#include <hollow/Shader.h>

using namespace hollow;

Shader::Shader(std::string vertexPath, std::string fragmentPath) {
	this->vertexPath = vertexPath;
	this->fragmentPath = fragmentPath;
	this->ID = load();
}


Shader::~Shader() {
	glDeleteProgram(ID);
}

void Shader::use() {
	glUseProgram(ID);
}

int Shader::load() {
	std::string vertexCode = FileManager::readShaderFile(vertexPath);
	std::string fragmentCode = FileManager::readShaderFile(fragmentPath);

	const char* vertexSource = vertexCode.c_str();
	const char* fragmentSource = fragmentCode.c_str();

	unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vertexSource, NULL);
	glCompileShader(vertex);
	checkForErrors(vertex, "VERTEX");

	unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fragmentSource, NULL);
	glCompileShader(fragment);
	checkForErrors(fragment, "FRAGMENT");

	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	glLinkProgram(ID);
	checkForErrors(ID, "PROGRAM");

	glDeleteShader(vertex);
	glDeleteShader(fragment);

	return ID;
}

void hollow::Shader::setBool(const std::string name, bool value) const {
	glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void hollow::Shader::setInt(const std::string name, int value) const {
	glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void hollow::Shader::setFloat(const std::string name, float value) const {
	glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

void hollow::Shader::setVec2(const std::string name, glm::vec2 vector) const {
	glUniform2fv(glGetUniformLocation(ID, name.c_str()), 1, &vector[0]);
}

void hollow::Shader::setVec2(const std::string name, float x, float y) const {
	glUniform2f(glGetUniformLocation(ID, name.c_str()), x, y);
}

void hollow::Shader::setVec3(const std::string name, glm::vec3 vector) const {
	glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &vector[0]);
}

void hollow::Shader::setVec3(const std::string name, float x, float y, float z) const {
	glUniform3f(glGetUniformLocation(ID, name.c_str()), x, y, z);
}

void hollow::Shader::setVec4(const std::string name, glm::vec4 vector) const {
	glUniform4fv(glGetUniformLocation(ID, name.c_str()), 1, &vector[0]);
}

void hollow::Shader::setVec4(const std::string name, float x, float y, float z, float w) const {
	glUniform4f(glGetUniformLocation(ID, name.c_str()), x, y, z, w);
}

void hollow::Shader::setMat2(const std::string name, glm::mat2 matrix) const {
	glUniformMatrix2fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &matrix[0][0]);
}

void hollow::Shader::setMat3(const std::string name, glm::mat3 matrix) const {
	glUniformMatrix3fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &matrix[0][0]);
}

void hollow::Shader::setMat4(const std::string name, glm::mat4 matrix) const {
	glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &matrix[0][0]);
}

void Shader::checkForErrors(GLuint shader, std::string type) {
	GLint success;
	GLchar infoLog[1024];

	if (type != "PROGRAM") {
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			Logger::log(ERROR, "Failed to compile shader of type: ");
			std::cout << type << "\n";
		}
	}
	else {
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			Logger::log(ERROR, "Failed to link shader program\n");
			std::cout << type << "\n";
		}
	}
}