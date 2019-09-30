#include "CVersion.h"
#include "API.h"
#include <stdexcept>
#include <sstream>

namespace dlib
{
	CVersion::CVersion()
	{
	}

	CVersion::~CVersion()
	{
	}

	unsigned int CVersion::GetMajor() const
	{
		return MAJOR_VERSION;
	}

	unsigned int CVersion::GetMinor() const
	{
		return MINOR_VERSION;
	}

	unsigned int CVersion::GetPatch() const
	{
		return PATCH_VERSION;
	}

	const std::string& CVersion::GetCodename() const
	{
		static const std::string ReturnValue = CODENAME;
		return ReturnValue;
	}

	const std::string& CVersion::ToString() const
	{
		static const std::string ReturnValue = ToString(MAJOR_VERSION, MINOR_VERSION, PATCH_VERSION, CODENAME);
		return ReturnValue;
	}

	std::string CVersion::ToString(unsigned int aMajor, unsigned int aMinor, unsigned int aPatch, const std::string& aCodename) const
	{
		std::stringstream Stream;
		Stream << "v" << aMajor << "." << aMinor << "." << aPatch;

		if (!aCodename.empty())
		{
			Stream << " Codename: '" << aCodename << "'";
		}

		return Stream.str();
	}

	bool CVersion::Check(const unsigned int aMajor, const unsigned int aMinor, const unsigned int aPatch, const bool aThrowException) const
	{
		return Check(aMajor, aMinor, aPatch, MAJOR_VERSION, MINOR_VERSION, PATCH_VERSION, aThrowException);
	}

	bool CVersion::Check(const unsigned int aMajor1, const unsigned int aMinor1, const unsigned int aPatch1, const unsigned int aMajor2, const unsigned int aMinor2, const unsigned int aPatch2, const bool aThrowException) const
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
}