#ifndef SHARED_LIB_I_VERSION_HPP
#define SHARED_LIB_I_VERSION_HPP

#include "SL/API.hpp"
#include <string>

/*
* Given a version number MAJOR.MINOR.PATCH, increment the:
* 	- MAJOR version when you make incompatible API changes.
*	- MINOR version when you add functionality in a backwards compatible manner.
* 	- PATCH version when you make backwards compatible bug fixes.
*/
#define SL_MAJOR_VERSION 	1
#define SL_MINOR_VERSION 	0
#define SL_PATCH_VERSION 	1
#define SL_CODENAME			"ALPHA"

/*
* Checks if a needed version is compatible with another version.
*/
#define CHECK_VERSION(aMajor1, aMinor1, aPatch1, aMajor2, aMinor2, aPatch2) (aMajor1 == aMajor2 && (aMinor1 < aMinor2 || (aMinor1 == aMinor2 && aPatch1 <= aPatch2)))

/*
* Compile-time and runtime version control macros.
*/
#define SL_CHECK_COMPILE_TIME_VERSION(aMajor, aMinor, aPatch) static_assert(CHECK_VERSION(aMajor, aMinor, aPatch, SL_MAJOR_VERSION, SL_MINOR_VERSION, SL_PATCH_VERSION), "Version dependency error")
#define SL_CHECK_RUNTIME_VERSION(aMajor, aMinor, aPatch) d2e::GetVersion()->Check(d2e::sVersion(aMajor, aMinor, aPatch, ""));
#define SL_CHECK_VERSION(aMajor, aMinor, aPatch) SL_CHECK_COMPILE_TIME_VERSION(aMajor, aMinor, aPatch); SL_CHECK_RUNTIME_VERSION(aMajor, aMinor, aPatch)

namespace sl
{
	/**
	 * Version data.
	 */
	struct sVersion
	{
		uint32_t 		Major;		//!< Major version.
		uint32_t 		Minor;		//!< Minor version.
		uint32_t 		Patch;		//!< Patch version.
		std::string 	Codename;	//!< Codename.

		/**
		 * Constructor.
		 * @param aMajor Major version.
		 * @param aMinor Minor version.
		 * @param aPatch Patch version.
		 * @param aCodename Codename.
		 */
		sVersion(uint32_t aMajor, uint32_t aMinor, uint32_t aPatch, const std::string& aCodename) :
			Major(aMajor), Minor(aMinor), Patch(aPatch), Codename(aCodename)
		{
		}
	};

	static const sVersion VERSION(SL_MAJOR_VERSION, SL_MINOR_VERSION, SL_PATCH_VERSION, SL_CODENAME);

	/**
	 * Version handler interface.
	 */
	class IVersion
	{
	public:

		/**
		 * Returns the current built-in version.
		 * @return Current built-in version.
		 */
		virtual const sVersion& GetBuiltInVersion() const = 0;

		/**
		 * Checks if a needed version is compatible with the current built-in version.
		 * @param aVersion Version data.
		 * @param aThrowException True to throw an exception if the check returns error.
		 * @return True if the needed version is compatible with the current built-in version.
		 */
		virtual bool Check(const sVersion& aVersion, const bool aThrowException = true) const = 0;

		/**
		 * Converts the current built-in version to string.
		 * @return Current built-in version converted to string.
		 */
		virtual const std::string& ToString() const = 0;
	};

	/**
	 * Returns the pointer to the version handler interface.
	 * @return Pointer to the version handler interface.
	 */
	SL_API IVersion* GetVersion();
}

#endif