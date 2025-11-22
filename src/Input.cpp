#include <hollow/Input.h>

using namespace hollow;

GLFWwindow* Input::window = nullptr;

KeyStates Input::keyStates{};
MouseStates Input::mouseStates{};

void Input::init() {
	window = Window::getWindowPointer();
}

void Input::update(){

	for (int k = 32; k < 400; k++) {
		if (glfwGetKey(window, k) == GLFW_PRESS) {
			keyStates._keyDown[k] = true;
			keyStates._keyPressed[k] = false;
		}
		else {
			keyStates._keyDown[k] = false;
			keyStates._keyPressed[k] = true;
		}

		if (keyStates._keyDown[k] && !keyStates._keyDownLastFrame[k])
			keyStates._keyPressed[k] = true;
		else
			keyStates._keyPressed[k] = false;

		keyStates._keyDownLastFrame[k] = keyStates._keyDown[k];
	}

	for (int m = 0; m < 10; m++) {
		if (glfwGetMouseButton(window, m) == GLFW_PRESS) {
			mouseStates._mouseDown[m] = true;
			mouseStates._mousePressed[m] = false;
		}
		else {
			mouseStates._mouseDown[m] = false;
			mouseStates._mousePressed[m] = true;
		}

		if (mouseStates._mouseDown[m] && !mouseStates._mouseDownLastFrame[m])
			mouseStates._mousePressed[m] = true;
		else
			mouseStates._mousePressed[m] = false;

		mouseStates._mouseDownLastFrame[m] = mouseStates._mouseDown[m];
	}

	if (isKeyPressed(HOLLOW_KEY_F2)) {
		mouseStates._mouseCaptured = !mouseStates._mouseCaptured;

		if (mouseStates._mouseCaptured) {
			glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

			double xPos, yPos;
			Input::getMousePosition(&xPos, &yPos);

			if (Input::mouseStates.firstMouse = true) {
				mouseStates.lastX = xPos;
				mouseStates.lastY = yPos;
				mouseStates.firstMouse = false;
			}

		}
		else {
			glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		}
	}

}

bool Input::isKeyPressed(unsigned int key) {
	return keyStates._keyPressed[key];
}

bool Input::isKeyReleased(unsigned int key) {
	return keyStates._keyReleased[key];
}

bool Input::isKeyDown(unsigned int key) {
	return keyStates._keyDown[key];
}

bool Input::isKeyDownLastFrame(unsigned int key) {
	return keyStates._keyDownLastFrame[key];
}

bool Input::isMouseButtonPressed(unsigned int button) {
	return mouseStates._mousePressed[button];
}

bool Input::isMouseButtonReleased(unsigned int button) {
	return mouseStates._mouseReleased[button];
}

bool Input::isMouseButtonDown(unsigned int button) {
	return mouseStates._mouseDown[button];
}

bool Input::isMouseButtonDownLastFrame(unsigned int button) {
	return mouseStates._mouseDownLastFrame[button];
}

bool Input::isMouseCaptured() {
	return mouseStates._mouseCaptured;
}

void Input::getMousePosition(double* xPos, double* yPos) {
	glfwGetCursorPos(Input::window, xPos, yPos);
}

void Input::setMousePosition(double* xPos, double* yPos) {
	glfwGetCursorPos(Input::window, xPos, yPos);
}