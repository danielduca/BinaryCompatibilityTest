#ifndef SHARED_LIB_API_HPP
#define SHARED_LIB_API_HPP

#include <cstdint> // Fixed width integer types - https://en.cppreference.com/w/cpp/types/integer
#include <array>

#if defined(_WIN32)
	#define SL_PUBLIC 		__declspec(dllexport)
	#define SL_PRIVATE 		__declspec(dllimport)
#elif defined(__linux__)
	#define SL_PUBLIC 		extern "C" __attribute__ ((visibility("default")))
	#define SL_PRIVATE 		extern "C"
#else
	#error "Not supported OS."
#endif

#if defined(SL_API_EXPORTS)
#define SL_API SL_PUBLIC
#else
#define SL_API SL_PRIVATE
#endif

#if defined(SL_MODULE_API_EXPORTS)
#define SL_MODULE_API SL_PUBLIC
#else
#define SL_MODULE_API SL_PRIVATE
#endif

#endif