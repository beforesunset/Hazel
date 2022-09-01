#pragma once

#ifdef HZ_PLATFORM_WINDOWS
	#ifdef HZ_BUILD_DLL
		#define HAZEL_API __declspec(dllexport) 
	#else
		#define HAZEL_API __declspec(dllimport)
	#endif
#else
	#error Hazel only support windows;
#endif

#ifdef HZ_ENABLE_ASSERTS
	#define HZ_ASSERT(x, ...) {if(!x) { HZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define HZ_CORE_ASSERT(x, ...) {if(!x) { HZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#endif
#define HZ_ASSERT(x, ...)
#define HZ_CORE_ASSERT(x, ...)

#ifdef HZ_PLATFORM_WINDOWS
	#include <Windows.h>
#endif

#define BIT(x) 1 << x

#define HZ_BIND_FN(fn) std::bind(&fn, this, std::placeholders::_1)