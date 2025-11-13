#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <hollow/Logger.h>
#include <hollow/Input.h>

#include <iostream>

namespace hollow {
	class Window {
	public:
		static void createWindow(unsigned int width, unsigned int height, std::string title);
		static bool run();
		static GLFWwindow* getWindowPointer();
		static unsigned int getWidth();
		static unsigned int getHeight();
		static std::string getTitle();
		static void setWidth(unsigned int newWidth);
		static void setHeight(unsigned int newHeight);
		static void backgroundColor();
		static void swapBuffersPollEvents();
		static void close();
		static void destroy();

	private:
		static bool _running;
		static unsigned int _screenWidth;
		static unsigned int _screenHeight;
		static std::string _title;
		static GLFWwindow* _window;
		static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	};

}


