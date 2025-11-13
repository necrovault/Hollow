#include <hollow/Timer.h>

using namespace hollow;

float Timer::deltaTime = 0.0f;
float Timer::lastFrame = 0.0f;

float Timer::getDeltaTime()
{
	float currentFrame = static_cast<float>(glfwGetTime());
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;

	return deltaTime;
}

float Timer::getLastFrame()
{
	return lastFrame;
}
