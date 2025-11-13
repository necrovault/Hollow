#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace hollow {

	struct Timer{
		static float getDeltaTime();
		static float getLastFrame();

	private:
		static float deltaTime;
		static float lastFrame;

	};
}

