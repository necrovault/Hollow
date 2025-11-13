#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <hollow/Window.h>
#include <hollow/Keycodes.h>

#include <iostream>

namespace hollow {

	struct KeyStates {
		// key states
		bool _keyPressed[400];
		bool _keyReleased[400];
		bool _keyDown[400];
		bool _keyDownLastFrame[400];
	};

	struct MouseStates {
		// mouse states
		bool firstMouse;
		float lastX;
		float lastY;
		double _mouseOffsetX;
		double _mouseOffsetY;
		bool _mouseCaptured;
		bool _mousePressed[10];
		bool _mouseReleased[10];
		bool _mouseDown[10];
		bool _mouseDownLastFrame[10];
	};
	
	namespace Input {
		void init();
		void update();
		
		// keyboard 
		bool isKeyPressed(unsigned int key);
		bool isKeyReleased(unsigned int key);
		bool isKeyDown(unsigned int key);
		bool isKeyDownLastFrame(unsigned int key);

		// mouse
		bool isMouseButtonPressed(unsigned int button);
		bool isMouseButtonReleased(unsigned int button);
		bool isMouseButtonDown(unsigned int button);
		bool isMouseButtonDownLastFrame(unsigned int button);
		bool isMouseCaptured();
		void getMousePosition(double* xPos, double* yPos);
		void setMousePosition(double* xPos, double* ypos);

		extern KeyStates keyStates;
		extern MouseStates mouseStates;

		extern GLFWwindow* window;
	}


}

