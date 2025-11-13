#include <hollow/FileManager.h>

std::string hollow::FileManager::readShaderFile(std::string shaderPath) {
    std::string shaderCode;
    std::fstream shaderFile;

    shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        shaderFile.open(shaderPath);
        std::stringstream shaderStream;
        shaderStream << shaderFile.rdbuf();
        shaderCode = shaderStream.str();
    }
    catch (std::ifstream::failure& e) {
        Logger::log(ERROR, "Failed to read shader file\n");
        std::cout << e.what();
    }

    return shaderCode;
}
