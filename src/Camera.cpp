#include <hollow/Camera.h>

using namespace hollow;

const float YAW = -90.0f;
const float PITCH = 0.0f;
const float SPEED = 2.5f;
const float SPRINT = 10.0f;
const float SENSITIVITY = 0.1f;
const float ZOOM = 45.0f;
glm::vec3 FRONT = glm::vec3(0.0f, 0.0f, -1.0f);


Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch) :
	Front(FRONT),Sprint(SPRINT), Speed(SPEED), Sensitivity(SENSITIVITY), Zoom(ZOOM) {

	Position = position;
	WorldUp = up;
	Yaw = yaw;
	Pitch = pitch;

	update();

}

glm::vec3 Camera::getPosition() {
	return Position;
}

glm::mat4 Camera::getViewMatrix() {
	return glm::lookAt(Position, Position + Front, Up);
}

void Camera::processInput() {
	float deltaTime = Timer::getDeltaTime();
	float speed = Input::isKeyDown(HOLLOW_KEY_LEFT_CONTROL) ? Sprint: Speed;
	float velocity = speed * deltaTime;

	// keyboard input
	if (Input::isKeyDown(HOLLOW_KEY_W)) {
		Position += Front * velocity;
	}
	if (Input::isKeyDown(HOLLOW_KEY_S)) {
		Position -= Front * velocity;
	}
	if (Input::isKeyDown(HOLLOW_KEY_A)) {
		Position -= Right * velocity;
	}
	if (Input::isKeyDown(HOLLOW_KEY_D)) {
		Position += Right * velocity;
	}
	if (Input::isKeyDown(HOLLOW_KEY_SPACE)) {
		Position += Up * velocity;
	}
	if (Input::isKeyDown(HOLLOW_KEY_LEFT_SHIFT)) {
		Position -= Up * velocity;
	}

	// mouse input
	if (!Input::isMouseCaptured()) return;

	double xPos, yPos;
	Input::getMousePosition(&xPos, &yPos);


	if (Input::mouseStates.firstMouse) {
		Input::mouseStates.lastX = xPos;
		Input::mouseStates.lastY = yPos;
		Input::mouseStates.firstMouse = false;
	}

	float xoffset = Sensitivity * (xPos - Input::mouseStates.lastX);
	float yoffset = Sensitivity * (Input::mouseStates.lastY - yPos);

	Input::mouseStates.lastX = xPos;
	Input::mouseStates.lastY = yPos;

	Yaw += xoffset;
	Pitch += yoffset;

	if (Pitch > 89.0f)
		Pitch = 89.0f;
	if (Pitch < -89.0f)
		Pitch = -89.0f;


	update();

}

void Camera::update() {
	glm::vec3 front;

	front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
	front.y = sin(glm::radians(Pitch));
	front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));

	Front = glm::normalize(front);
	Right = glm::normalize(glm::cross(Front, WorldUp));
	Up = glm::normalize(glm::cross(Right, Front));
}