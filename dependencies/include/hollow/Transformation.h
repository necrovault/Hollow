#pragma once

#include <glm/common.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace hollow {
	class Transformation {
	public:
		Transformation();
		~Transformation();

		void rotate(glm::vec3 value);
		void translate(glm::vec3 value);
		void scale(glm::vec3 value);
	private:
		glm::mat4 transform;
	};
}

