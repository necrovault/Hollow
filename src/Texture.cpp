#include <hollow/Texture.h>

using namespace hollow;

void hollow::Texture::create(TextureData& texture) {
	glGenTextures(1, &texture.ID);	
}

void hollow::Texture::bind(TextureData& texture) {
	glBindTexture(GL_TEXTURE_2D, texture.ID);
}

void hollow::Texture::unbind() {
	glBindTexture(GL_TEXTURE_2D, 0);
}

void hollow::Texture::destroy(TextureData& texture) {
	glDeleteTextures(1, &texture.ID);
}

void hollow::Texture::uploadTextureData(GLenum format, int width, int height, unsigned char* data) {
	glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);
}

void hollow::Texture::setTextureParameters() {
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

unsigned int hollow::Texture::readTexture(const char* texturePath, const std::string& directory, bool gamma) {
	std::string filename = std::string(texturePath);
	filename = directory + '/' + filename;
	
	unsigned int textureID = 0;
	int width, height, nrComponents;
	unsigned char* data = stbi_load(filename.c_str(), &width, &height, &nrComponents, 0);

	if (data) {
		GLenum format;
		if (nrComponents == 1)
			format = GL_RED;
		else if (nrComponents == 3)
			format = GL_RGB;
		else if (nrComponents == 4)
			format = GL_RGBA;

		Texture::TextureData texture;

		Texture::create(texture);
		Texture::bind(texture);

		Texture::uploadTextureData(format, width, height, data);
		Texture::setTextureParameters();

		textureID = texture.ID;

		stbi_image_free(data);
	}
	else {
		Logger::log(ERROR, "Failed to load texture at path: ");
		std::cout << filename << "\n";
		stbi_image_free(data);
	}

	return textureID;
}
