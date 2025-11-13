

#include <hollow/Renderer.h>
#include <iostream>

using namespace hollow;


/*

 ▄█    █▄   ▄█████▄   ▄█        ▄█        ▄█████▄   ▄█     █▄
███    ███ ███   ███ ███       ███       ███   ███ ███     ███
███    ███ ███   ███ ███       ███       ███   ███ ███     ███
███▄▄▄▄███ ███   ███ ███       ███       ███   ███ ███     ███
███▀▀▀▀███ ███   ███ ███       ███       ███   ███ ███  ▄  ███
███    ███ ███   ███ ███       ███       ███   ███ ███ ███ ███
███    ███ ███   ███ ███▌    ▄ ███▌    ▄ ███   ███ ███████████
 ▀█    █▀   ▀█████▀  █████▄▄██ █████▄▄██  ▀█████▀   ▀█▀▀▀▀▀█▀

*/

int main()
{
	
	try {
		Renderer::init();
		Renderer::run();
	}
	catch (std::ifstream::failure& e) {
		std::cerr << e.what();
		return EXIT_FAILURE;
	}
	
	Renderer::shutDown();
	
	return EXIT_SUCCESS;
}