#include "CMamotreto.hpp"
#include <stdexcept>
#include <sstream>

namespace sl
{
	static CMamotreto Mamotreto;

	CMamotreto::CMamotreto() :
		mBuiltInVersion(SL_MAJOR_VERSION, SL_MINOR_VERSION, SL_PATCH_VERSION, SL_CODENAME),
		mString(ToString(mBuiltInVersion))
	{
	}

	CMamotreto::~CMamotreto()
	{
	}

	const sVersion& CMamotreto::GetBuiltInVersion() const
	{
		return mBuiltInVersion;
	}

	bool CMamotreto::Check(const sVersion& aVersion, const bool aThrowException) const
	{
		return Check(aVersion, mBuiltInVersion, aThrowException);
	}

	const std::string& CMamotreto::ToString() const
	{
		return mString;
	}

	bool CMamotreto::Check(const sVersion& aVersion1, const sVersion& aVersion2, const bool aThrowException)
	{
		return Check(
			aVersion1.Major, aVersion1.Minor, aVersion1.Patch,
			aVersion2.Major, aVersion2.Minor, aVersion2.Patch
		);
	}

	std::string CMamotreto::ToString(const sVersion& aVersion)
	{
		return ToString(aVersion.Major, aVersion.Minor, aVersion.Patch, aVersion.Codename);
	}

	IAnimal* CMamotreto::Create(const eAnimalType aAnimalType) const
	{
		// return Create({ aAnimalType, "" });
		return CreateV2({ aAnimalType, "" });
	}

	void CMamotreto::Destroy(IAnimal* const apAnimal)
	{
		printf("CAnimalFactory: mamotreto object destroyed... NO!\n");
	}

	IAnimal* CMamotreto::CreateV2(const sAnimalDefinition& aAnimalDefinition) const
	{
		printf("CAnimalFactory: mamotreto object returned WITH A CreateV2 METHOD!.\n");
		return &Mamotreto;
	}

	// Method overload
	// Windows (MSVC++ 14.23): NOT BINARY BACKWARD COMPATIBLE.
	// Linux (g++ (Debian 4.9.2-10) 4.9.2): BINARY BACKWARD COMPATIBLE.
	/*
	IAnimal* CMamotreto::Create(const sAnimalDefinition& aAnimalDefinition) const
	{
		printf("CAnimalFactory: mamotreto object returned WITH THE NEW & IMPROVED OVERLOAD METHOD!.\n");
		return &Mamotreto;
	}
	*/

	bool CMamotreto::Check(const uint32_t aMajor1, const uint32_t aMinor1, const uint32_t aPatch1, const uint32_t aMajor2, const uint32_t aMinor2, const uint32_t aPatch2, const bool aThrowException)
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

	std::string CMamotreto::ToString(const uint32_t aMajor, const uint32_t aMinor, const uint32_t aPatch, const std::string& aCodename)
	{
		std::stringstream Stream;
		Stream << "v" << aMajor << "." << aMinor << "." << aPatch;

		if (!aCodename.empty())
		{
			Stream << " Codename: '" << aCodename << "'";
		}

		return Stream.str();
	}

	void CMamotreto::SayHello() const
	{
		printf("Hello! I'm a fucking mamotreto object.\n");
	}

	IVersion* GetVersion()
	{
		return &Mamotreto;
	}

	SL_API IAnimalFactory* GetAnimalFactory()
	{
		return &Mamotreto;
	}
}