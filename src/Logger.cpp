#include <hollow/Logger.h>

void hollow::Logger::init() {
	std::cout << "Hollow world...\n";
	std::cout << "----------------------------------------------------------------------------------------------------------------------\n";
}


void hollow::Logger::log(LogLevel level, std::string message) {
	auto logLevelToString = [](LogLevel level) {
			switch (level) {
			case LogLevel::INFO:    return "Info";
			case LogLevel::WARNING: return "Warning";
			case LogLevel::ERROR:   return "Error";
			default:                return "Unknown";
			}
		};

	std::cout << "[" << logLevelToString(level) << "] " << message << "\n";
}
