
#include <prota/util/Log.h>

int main()
{
	prota::Log::SetLogLevel(prota::LogLevel::INFO);

	INFO("Here's some cool info bro B)")
	WARN("Oh no! it's a warning!!")
	ERROR("ERROR!! ERRORR! ERR URRHHR!");

	ASSERT(false, "This, should trigger because we're asserting false");

	return 0;
}
