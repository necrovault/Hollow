#include <hollow/Window.h>

using namespace hollow;

bool Window::_running = true;
GLFWwindow* Window::_window = nullptr;
unsigned int Window::_screenWidth = 1280;
unsigned int Window::_screenHeight = 720;
std::string Window::_title = "Hollow Renderer";

void hollow::Window::createWindow(unsigned int width, unsigned int height, std::string title) {
	if (!glfwInit()) {
		Logger::log(ERROR, "Failed to initialize glfw\n");
		glfwTerminate();
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	_window = glfwCreateWindow(_screenWidth, _screenHeight, _title.c_str(), NULL, NULL);

	if (!_window) {
		Logger::log(ERROR, "Failed to create window\n");
		glfwTerminate();
	}

	glfwMakeContextCurrent(_window);
	glfwSetFramebufferSizeCallback(_window, framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		Logger::log(ERROR, "Failed to initialize glad\n");
		glfwTerminate();
	}

	glEnable(GL_DEPTH_TEST);

}

bool hollow::Window::run() {
	_running = !glfwWindowShouldClose(_window);

	if (Input::isKeyPressed(HOLLOW_KEY_ESCAPE))
		_running = false;

	return _running;
}

GLFWwindow* hollow::Window::getWindowPointer() {
	return _window;
}

unsigned int hollow::Window::getWidth() {
	return _screenWidth;
}

unsigned int hollow::Window::getHeight() {
	return _screenHeight;
}

std::string hollow::Window::getTitle() {
	return _title;
}

void hollow::Window::setWidth(unsigned int newWidth) {
	_screenWidth = newWidth;
}

void hollow::Window::setHeight(unsigned int newHeight) {
	_screenHeight = newHeight;
}

void hollow::Window::backgroundColor() {
	glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void hollow::Window::swapBuffersPollEvents() {
	glfwSwapBuffers(_window);
	glfwPollEvents();
}

void hollow::Window::close() {
	glfwSetWindowShouldClose(_window, true);
	_running = false;
}

void hollow::Window::destroy() {
	glfwDestroyWindow(_window);
}

void hollow::Window::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}
