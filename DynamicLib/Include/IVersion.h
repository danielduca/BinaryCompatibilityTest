#ifndef I_VERSION_H
#define I_VERSION_H

#include <string>

namespace dlib
{
	/**
	 * Version handler interface.
	 */
	class IVersion
	{
	public:

		/**
		 * Destructor.
		 */
		virtual ~IVersion() {}

		/**
		 * Gets major version.
		 * @return Major version.
		 */
		virtual unsigned int GetMajor() const = 0;

		/**
		 * Gets minor version.
		 * @return Minor version.
		 */
		virtual unsigned int GetMinor() const = 0;

		/**
		 * Gets patch version.
		 * @return Patch version.
		 */
		virtual unsigned int GetPatch() const = 0;

		/**
		 * Gets the codename.
		 * @return Codename.
		 */
		virtual const std::string& GetCodename() const = 0;

		/**
		 * Converts current version to string.
		 * @return Current version converted to string.
		 */
		virtual const std::string& ToString() const = 0;

		/**
		 * Converts a version to string.
		 * @param aMajor Major version.
		 * @param aMinor Minor version.
		 * @param aPatch Patch version.
		 * @param aCodename Codename.
		 * @return Version converted to string.
		 */
		virtual std::string ToString(const unsigned int aMajor, const unsigned int aMinor, const unsigned int aPatch, const std::string& aCodename) const = 0;

		/**
		 * Checks if a needed version is compatible with current version.
		 * @param aMajor Needed Major version.
		 * @param aMinor Needed Minor version.
		 * @param aPatch Needed Patch version.
		 * @return True if a needed version is compatible with current version.
		 */
		virtual bool Check(const unsigned int aMajor, const unsigned int aMinor, const unsigned int aPatch, const bool aThrowException = true) const = 0;

		/**
		 * Checks if a needed version is compatible with another version.
		 * @param aMajor1 Needed Major version.
		 * @param aMinor1 Needed Minor version.
		 * @param aPatch1 Needed Patch version.
		 * @param aMajor2 Another Major version.
		 * @param aMinor2 Another Minor version.
		 * @param aPatch2 Another Patch version.
		 * @return True if a needed version is compatible with another version.
		 */
		virtual bool Check(const unsigned int aMajor1, const unsigned int aMinor1, const unsigned int aPatch1, const unsigned int aMajor2, const unsigned int aMinor2, const unsigned int aPatch2, const bool aThrowException = true) const = 0;
	};
}

#endif
