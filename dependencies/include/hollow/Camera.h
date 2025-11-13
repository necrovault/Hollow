#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <hollow/Window.h>
#include <hollow/Shader.h>
#include <hollow/Input.h>
#include <hollow/Timer.h>

#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>


namespace hollow {
	class Camera {
	public:
		Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = -90.0f, float pitch = 0.0f);
		void processInput();
		glm::vec3 getPosition();
		glm::mat4 getViewMatrix();
		
		glm::vec3 Position;
		glm::vec3 Front;
		glm::vec3 Up;
		glm::vec3 Right;
		glm::vec3 WorldUp;

		float Yaw;
		float Pitch;

		float Speed;
		float Sprint;
		float Sensitivity;
		float Zoom;

	private:
		void update();



	};

}

