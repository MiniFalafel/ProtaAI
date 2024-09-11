#pragma once

#include <iostream>
#include <format>

namespace prota
{

	enum LogLevel
	{
		None	= 0,
		ERROR	= 1,
		WARN	= 2,
		INFO	= 3
	};

	class Log
	{	// Nothing but static methods

		// Log level
		static LogLevel s_Level;

		// Stream to log to
		static std::ostream* s_Stream;

	public:

		// SETTERS
		static inline void SetLogLevel(LogLevel lvl) { s_Level = lvl; }
		static inline void SetOutputStream(std::ostream* stream) { s_Stream = stream; }
		// GETTER
		static inline LogLevel GetLogLevel() { return s_Level; }
		static inline const std::ostream& GetOutputStream() { return *s_Stream; }

		// Logging methods
		static inline void LOG(std::string tag, std::string message, LogLevel lvl)
		{	// Check the log level
			if (lvl > s_Level)
				return;

			// cout with tag
			*s_Stream << std::format("[{}]: {}\n", tag, message);

		}
	};

	// DEFINES FOR QUICK LOGGING STUFF
#define P_LOG_ERROR(msg) prota::Log::LOG("ERROR", msg, prota::LogLevel::ERROR); __debugbreak();
#define P_LOG_WARN(msg) prota::Log::LOG("WARN", msg, prota::LogLevel::WARN);
#define P_LOG_INFO(msg) prota::Log::LOG("INFO", msg, prota::LogLevel::INFO);

#define P_ASSERT(x, msg) if (!(x)) { prota::Log::LOG("ASSERTION_ERROR", msg, prota::LogLevel::ERROR); __debugbreak(); }

}
