#include "Log.h"

namespace prota
{

	// Static member setting
	LogLevel Log::s_Level = LogLevel::None;
	std::ostream* Log::s_Stream = &std::cout;

}