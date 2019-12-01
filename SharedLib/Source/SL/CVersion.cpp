#include "CVersion.hpp"
#include <stdexcept>
#include <sstream>

namespace
{
	/**
	 * Constantes.
	 */
	const sl::sVersion		EMPTY_VERSION(0, 0, 0, "");
}

namespace sl
{
	CVersion::CVersion(const sVersion& aBuiltInVersion) :
		mBuiltInVersion(aBuiltInVersion),
		mString(ToString(aBuiltInVersion))
	{
	}

	CVersion::~CVersion()
	{
	}

	const sVersion& CVersion::GetBuiltInVersion() const
	{
		return mBuiltInVersion;
	}

	bool CVersion::Check(const sVersion& aVersion, const bool aThrowException) const
	{
		return Check(aVersion, mBuiltInVersion, aThrowException);
	}

	const std::string& CVersion::ToString() const
	{
		return mString;
	}

	bool CVersion::Check(const sVersion& aVersion1, const sVersion& aVersion2, const bool aThrowException)
	{
		return Check(
			aVersion1.Major, aVersion1.Minor, aVersion1.Patch,
			aVersion2.Major, aVersion2.Minor, aVersion2.Patch
		);
	}

	std::string CVersion::ToString(const sVersion& aVersion)
	{
		return ToString(aVersion.Major, aVersion.Minor, aVersion.Patch, aVersion.Codename);
	}

	bool CVersion::Check(const uint32_t aMajor1, const uint32_t aMinor1, const uint32_t aPatch1, const uint32_t aMajor2, const uint32_t aMinor2, const uint32_t aPatch2, const bool aThrowException)
	{
		const bool ReturnValue = CHECK_VERSION(aMajor1, aMinor1, aPatch1, aMajor2, aMinor2, aPatch2);

		if (aThrowException && !ReturnValue)
		{
			std::stringstream Stream;
			Stream << "Version dependency error.";
			Stream << " ";
			Stream << "Needed: " << ToString(aMajor1, aMinor1, aPatch1, "");
			Stream << " ";
			Stream << "Current: " << ToString(aMajor2, aMinor2, aPatch2, "");
			Stream << ".";

			throw std::runtime_error(Stream.str());
		}

		return ReturnValue;
	}

	std::string CVersion::ToString(const uint32_t aMajor, const uint32_t aMinor, const uint32_t aPatch, const std::string& aCodename)
	{
		std::stringstream Stream;
		Stream << "v" << aMajor << "." << aMinor << "." << aPatch;

		if (!aCodename.empty())
		{
			Stream << " Codename: '" << aCodename << "'";
		}

		return Stream.str();
	}

	IVersion* GetVersion()
	{
		return GetVersionClass();
	}

	CVersion* GetVersionClass()
	{
		static CVersion Version(sVersion(SL_MAJOR_VERSION, SL_MINOR_VERSION, SL_PATCH_VERSION, SL_CODENAME));
		return &Version;
	}
}