#ifndef SL_C_VERSION_HPP
#define SL_C_VERSION_HPP

#include "SL/IVersion.hpp"

namespace sl
{
	/**
	 * Version handler class.
	 */
	class CVersion : public IVersion
	{
	public:

		/**
		 * Constructor.
		 * @param aBuiltInVersion Built-in version data.
		 */
		CVersion(const sVersion& aBuiltInVersion);

		/**
		 * Destructor.
		 */
		virtual ~CVersion();

		/**
		 * Returns the current built-in version.
		 * @return Current built-in version.
		 */
		virtual const sVersion& GetBuiltInVersion() const override;

		/**
		 * Checks if a needed version is compatible with the current built-in version.
		 * @param aVersion Version data.
		 * @param aThrowException True to throw an exception if the check returns error.
		 * @return True if the needed version is compatible with the current built-in version.
		 */
		virtual bool Check(const sVersion& aVersion, const bool aThrowException = true) const override;

		/**
		 * Converts the current built-in version to string.
		 * @return Current built-in version converted to string.
		 */
		virtual const std::string& ToString() const override;

		/**
		 * Checks if a needed version is compatible with another version.
		 * @param aVersion1 Version data 1.
		 * @param aVersion2 Version data 2.
		 * @param aThrowException True to throw an exception if the check returns error.
		 * @return True if a needed version is compatible with another version.
		 */
		static bool Check(const sVersion& aVersion1, const sVersion& aVersion2, const bool aThrowException = true);

		/**
		 * Converts a version to string.
		 * @param aVersion Version data.
		 * @return Version converted to string.
		 */
		static std::string ToString(const sVersion& aVersion);

		/**
		 * Checks if a needed version is compatible with another version.
		 * @param aMajor1 Needed Major version.
		 * @param aMinor1 Needed Minor version.
		 * @param aPatch1 Needed Patch version.
		 * @param aMajor2 Another Major version.
		 * @param aMinor2 Another Minor version.
		 * @param aPatch2 Another Patch version.
		 * @param aThrowException True to throw an exception if the check returns error.
		 * @return True if a needed version is compatible with another version.
		 */
		static bool Check(const uint32_t aMajor1, const uint32_t aMinor1, const uint32_t aPatch1, const uint32_t aMajor2, const uint32_t aMinor2, const uint32_t aPatch2, const bool aThrowException = true);

		/**
		 * Converts a version to string.
		 * @param aMajor Major version.
		 * @param aMinor Minor version.
		 * @param aPatch Patch version.
		 * @param aCodename Codename.
		 * @return Version converted to string.
		 */
		static std::string ToString(const uint32_t aMajor, const uint32_t aMinor, const uint32_t aPatch, const std::string& aCodename);

	private:

		const sVersion		mBuiltInVersion;		//!< Built-in version data.
		const std::string	mString;				//!< Built-in version data converted to string.
	};

	/**
	 * Returns the pointer to the version handler class.
	 * @return Pointer to the version handler class.
	 */
	CVersion* GetVersionClass();
}

#endif