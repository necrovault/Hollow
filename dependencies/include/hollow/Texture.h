#pragma once
#include <hollow/Logger.h>
#include <glad/glad.h>
#include <stb/stb_image.h>

#include <string>
#include <fstream>
#include <iostream>

namespace hollow {
	namespace Texture {
		struct TextureData {
			GLuint ID;
			std::string type;
			std::string path;

		};

		void create(TextureData& texture);
		void bind(TextureData& texture);
		void unbind();
		void destroy(TextureData& texture);
		void uploadTextureData(GLenum format, int width, int height, unsigned char* data);
		void setTextureParameters();

		unsigned int readTexture(const char* texturePath, const std::string& directory, bool gamma);

	}
}
