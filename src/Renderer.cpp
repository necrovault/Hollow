#include <hollow/Renderer.h>

using namespace hollow;

unsigned int Renderer::screenWidth = Window::getWidth();
unsigned int Renderer::screenHeight = Window::getHeight();
std::string title = Window::getTitle();

void hollow::Renderer::init() {

	glm::vec3 cameraPosition(0.0f, 0.0f, -6.0f);


	// systems initialization
	Logger::init();
	Window::createWindow(screenWidth, screenHeight, title);
	Input::init();
	//std::cout << "OpenGL version: " << glGetString(GL_VERSION) << "\n";
	//std::cout << "Graphics version: " << glGetString(GL_RENDERER) << "\n";
}

void hollow::Renderer::run() {

	const char* vertexPath = "src/vendor/shaders/shader.vert";
	const char* fragmentPath = "src/vendor/shaders/shader.frag";

	const char* lightVertex = "src/vendor/shaders/light.vert";
	const char* lightFragment = "src/vendor/shaders/light.frag";

	glm::vec3 lightPos(1.2f, 1.0f, 2.0f);
	glm::vec3 viewPos(0.0f, 0.0f, -6.0f);
	glm::vec3 camPosition(0.0f, 0.0f, 3.0f);

	Shader triangleTest(vertexPath, fragmentPath);
	Shader lightTest(lightVertex, lightFragment);
	Camera camera(camPosition);

	std::vector<float> vertices = {
		 // vertices          // normals
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
		 0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,

		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
	};


	// model
	Utils::VAO vao;
	Utils::VBO vbo;
	
	Utils::createVAO(vao);
	Utils::createVBO(vbo, vertices);
	Utils::bindVAO(vao);
	Utils::bindVBO(vbo, vertices);
	Utils::vertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	Utils::vertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	Utils::unbindVAO();

	glm::vec3 cubePositions[] = {
	   glm::vec3(0.0f,  0.0f,  0.0f),
	   glm::vec3(2.0f,  5.0f, -15.0f),
	   glm::vec3(-1.5f, -2.2f, -2.5f),
	   glm::vec3(-3.8f, -2.0f, -12.3f),
	   glm::vec3(2.4f, -0.4f, -3.5f),
	   glm::vec3(-1.7f,  3.0f, -7.5f),
	   glm::vec3(1.3f, -2.0f, -2.5f),
	   glm::vec3(1.5f,  2.0f, -2.5f),
	   glm::vec3(1.5f,  0.2f, -1.5f),
	   glm::vec3(-1.3f,  1.0f, -1.5f)
	};


	// light 
	Utils::VAO lightVAO;

	Utils::createVAO(lightVAO);
	Utils::bindVAO(lightVAO);
	Utils::bindVBO(vbo, vertices);
	Utils::vertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);


	glDisable(GL_CULL_FACE);

	while (Window::run()) {
		Input::update();
		camera.processInput();
		Window::backgroundColor();

		// model
		triangleTest.use();
		triangleTest.setVec3("light.position", lightPos);
		triangleTest.setVec3("viewPos", camPosition);



		// light properties
		triangleTest.setVec3("light.ambient", 0.2f, 0.2f, 0.2f);
		triangleTest.setVec3("light.diffuse", 0.5f, 0.5f, 0.5f);
		triangleTest.setVec3("light.specular", 1.0f, 1.0f, 1.0f);
		triangleTest.setFloat("light.constant", 1.0f);
		triangleTest.setFloat("light.linear", 0.09f);
		triangleTest.setFloat("light.quadratic", 0.032f);

		// material properties
		triangleTest.setVec3("material.ambient", 1.0f, 0.0f, 0.0f);
		triangleTest.setVec3("material.diffuse", 1.0f, 0.0f, 0.0f);
		triangleTest.setVec3("material.specular", 1.0f, 0.0f, 0.0f);
		triangleTest.setFloat("material.shininess", 32.0f);

		//glm::mat4 model = glm::mat4(1.0f);
		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 projection = glm::mat4(1.0f);


		//model = glm::rotate(model, glm::radians((float)glfwGetTime() * 100), glm::vec3(1.0f, 1.0f, 2.0f));
		view = camera.getViewMatrix();
		projection = glm::perspective(glm::radians(camera.Zoom), (float)Renderer::screenWidth / (float)Renderer::screenHeight, 0.1f, 100.0f);

		triangleTest.setMat4("view", view);
		triangleTest.setMat4("projection", projection);

		for (int i = 0; i < 10; i++) {
			glm::mat4 model = glm::mat4(1.0f);
			model = glm::translate(model, cubePositions[i]);
			//model = glm::rotate(model, glm::radians((float)glfwGetTime() * 100), glm::vec3(1.0f, 1.0f, 0.0f));
			triangleTest.setMat4("model", model);
			Utils::bindVAO(vao);
			glDrawArrays(GL_TRIANGLES, 0, 36);
		}



		

		// light
		lightTest.use();
		lightTest.setMat4("projection", projection);
		lightTest.setMat4("view", view);

		glm::mat4 model = glm::mat4(1.0f);
		model = glm::mat4(1.0f);
		model = glm::translate(model, lightPos);
		model = glm::scale(model, glm::vec3(0.2f));
		lightTest.setMat4("model", model);

		Utils::bindVAO(lightVAO);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		Window::handleEvents();
	}

	Utils::deleteVBO(vbo);
	Utils::deleteVAO(vao);
}

void hollow::Renderer::shutDown() {
	Logger::log(INFO, "Shutting down...\n");
	Window::destroy();
}
