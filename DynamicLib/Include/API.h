#ifndef API_H
#define API_H

#define MAJOR_VERSION	0
#define MINOR_VERSION	0
#define PATCH_VERSION	0
#define CODENAME		"FIRST VERSION"

/*
* Checks if a needed version is compatible with another version.
*/
#define CHECK_VERSION(aMajor1, aMinor1, aPatch1, aMajor2, aMinor2, aPatch2) (aMajor1 == aMajor2 && aMinor1 <= aMinor2 && aPatch1 <= aPatch2)

/*
* Compile-time and runtime version control macros.
*/
#define DLIB_CHECK_COMPILE_TIME_VERSION(aMajor, aMinor, aPatch) static_assert(CHECK_VERSION(aMajor, aMinor, aPatch, MAJOR_VERSION, MINOR_VERSION, PATCH_VERSION), "Version dependency error")
#define DLIB_CHECK_RUNTIME_VERSION(aMajor, aMinor, aPatch) dlib::GetVersion()->Check(aMajor, aMinor, aPatch);
#define DLIB_CHECK_VERSION(aMajor, aMinor, aPatch) DLIB_CHECK_COMPILE_TIME_VERSION(aMajor, aMinor, aPatch); DLIB_CHECK_RUNTIME_VERSION(aMajor, aMinor, aPatch)

#include "IVersion.h"
#include "IClass1.h"
#include "IClass2.h"
#include "IFuckinClass.h"
#include "IGame.h"

// Steam API export macro
#if defined( _WIN32 )
#if defined( API_EXPORTS )
#define S_API extern "C" __declspec( dllexport ) 
#elif defined( API_NODLL )
#define S_API extern "C"
#else
#define S_API extern "C" __declspec( dllimport ) 
#endif // API_EXPORTS
#elif defined( __linux__ )
#if defined( API_EXPORTS )
#define S_API extern "C" __attribute__ ((visibility("default"))) 
#else
#define S_API extern "C" 
#endif // API_EXPORTS
#else // !WIN32
#if defined( API_EXPORTS )
#define S_API extern "C"  
#else
#define S_API extern "C" 
#endif // API_EXPORTS
#endif

namespace dlib
{
	S_API void Init();
	S_API void Close();
	S_API IVersion* GetVersion();
	S_API IClass1* GetClass1();
	S_API IClass2* GetClass2();
	S_API IFuckingClass* GetFuckinClass();
	S_API void SetGame(IGame* const apGame);
}

#endif
