#include <iostream>

#ifdef BUILD_SHARED
#	if defined(WINDOWS)
#		define API __declspec(dllexport)
#	elif defined(LINUX)
#		define API __attribute__((visibility("default")))
#	endif
#else
#	define API
#endif

API void sayHi();
