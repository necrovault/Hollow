#include <hollow/Window.h>

using namespace hollow;

namespace {
	GLFWwindow* window;
	const GLFWvidmode* mode;
	GLFWmonitor* monitor;
	WindowMode windowMode;
	unsigned int currentWidth = 1280;
	unsigned int currentHeight = 720;
	unsigned int windowedWidth = 1280;
	unsigned int windowedHeight = 720;
	unsigned int fullscreenWidth;
	unsigned int fullscreenHeight;
	unsigned int winPosX = 100;
	unsigned int winPosY = 100;
	std::string title;
	bool running = true;
	bool vsync = true;
}

void Window::createWindow(unsigned int width, unsigned int height, std::string title) {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	monitor = glfwGetPrimaryMonitor();
	mode = glfwGetVideoMode(monitor);

	glfwWindowHint(GLFW_RED_BITS, mode->redBits);
	glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
	glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
	glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

	fullscreenWidth = mode->width;
	fullscreenHeight = mode->height;

	

	window = glfwCreateWindow(windowedWidth, windowedHeight, title.c_str(), NULL, NULL);
	if (window == NULL) {
		throw std::runtime_error("failed to create window");
	}

	glfwSwapInterval(vsync ? 1 : 0);

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		throw std::runtime_error("failed to initialize glad");
	}

	
	glEnable(GL_DEPTH_TEST);
}

void Window::setMode(const WindowMode& winMode) {
	if (winMode == WindowMode::WINDOWED) {
		currentWidth = windowedWidth;
		currentHeight = windowedHeight;
		glfwSetWindowMonitor(window, nullptr, winPosX, winPosY, windowedWidth, windowedHeight, 0);
		glfwSetWindowPos(window, winPosX, winPosY);
		std::cout << "WINDOWED\n";
	}
	else if (winMode == WindowMode::FULLSCREEN) {
		currentWidth = fullscreenWidth;
		currentHeight = fullscreenHeight;
		glfwSetWindowMonitor(window, monitor, 0, 0, currentWidth, currentHeight, mode->refreshRate);
		std::cout << "FULLSCREEN\n";
	}

	windowMode = winMode;
}

void Window::toggleFullscreen() {
	if (Input::isKeyPressed(HOLLOW_KEY_F)) {
		if (windowMode == WindowMode::FULLSCREEN) {
			setMode(WindowMode::WINDOWED);
		}
		else {
			setMode(WindowMode::FULLSCREEN);
		}
	}

}

bool Window::run() {
	running = !glfwWindowShouldClose(window);
	if (Input::isKeyPressed(HOLLOW_KEY_ESCAPE)) {
		running = false;
	}

	return running;
}

GLFWwindow* Window::getWindowPointer() {
	return window;
}

unsigned int Window::getWidth() {
	return currentWidth;
}

unsigned int Window::getHeight() {
	return currentHeight;
}

std::string Window::getTitle() {
	return title;
}

void Window::setWidth(unsigned int newWidth) {
	currentWidth = newWidth;
}

void Window::setHeight(unsigned int newHeight) {
	currentHeight = newHeight;
}

void Window::backgroundColor() {
	glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::handleEvents() {
	toggleFullscreen();

	glfwSwapBuffers(window);
	glfwPollEvents();
}

void Window::close() {
	glfwSetWindowShouldClose(window, true);
	running = false;
}

void Window::destroy() {
	glfwDestroyWindow(window);
}

void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

bool Window::getVsync() {
	return vsync;
}

void Window::setVsync(bool newVsync) {
	vsync = newVsync;
}