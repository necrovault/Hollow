#pragma once

#include <string>
#include <iostream>

namespace hollow {
	enum LogLevel {
		INFO,
		WARNING,
		ERROR
	};

	class Logger {
	public:
		static void init();
		static void log(LogLevel level, std::string message);

	};
}