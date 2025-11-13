#pragma once

#include <hollow/Window.h>
#include <hollow/Logger.h>
#include <hollow/Input.h>
#include <hollow/Camera.h>
#include <hollow/Shader.h>
#include <hollow/Utils.h>

#include <glm/common.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>

namespace hollow {
	class Renderer {
	public:
		static void init();
		static void run();
		static void shutDown();

	private:
		static unsigned int screenWidth;
		static unsigned int screenHeight;
	};
}