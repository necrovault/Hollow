#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <hollow/Logger.h>
#include <hollow/Input.h>

#include <iostream>

namespace hollow {

	enum WindowMode {
		WINDOWED,
		FULLSCREEN
	};

	namespace Window {
		void createWindow(unsigned int width, unsigned int height, std::string title);
		bool run();
		GLFWwindow* getWindowPointer();
		unsigned int getWidth();
		unsigned int getHeight();
		std::string getTitle();
		void setWidth(unsigned int newWidth);
		void setHeight(unsigned int newHeight);
		void backgroundColor();
		void setMode(const WindowMode& winMode);
		void toggleFullscreen();
		void handleEvents();
		void setVsync(bool newVsync);
		bool getVsync();
		void close();
		void destroy();
		
		void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	};
}

