#ifndef SL_C_MAMOTRETO_HPP
#define SL_C_MAMOTRETO_HPP

#include "SL/IVersion.hpp"
#include "SL/IAnimalFactory.hpp"

namespace sl
{
	/**
	 * Version handler class.
	 */
	class CMamotreto : public IVersion, public IAnimalFactory, public IAnimal
	{
	public:
		CMamotreto();
		virtual ~CMamotreto();
		virtual const sVersion& GetBuiltInVersion() const override;
		virtual bool Check(const sVersion& aVersion, const bool aThrowException = true) const override;
		virtual const std::string& ToString() const override;
		// 1.0
		virtual IAnimal* Create(const eAnimalType aAnimalType) const override;
		virtual void Destroy(IAnimal* const apAnimal) override;

		// 1.2
		// Method overload not BC on Windows!
		// @todo: check on Linux.
		//virtual IAnimal* Create(const sAnimalDefinition& aAnimalDefinition) const override;
		virtual IAnimal* CreateV2(const sAnimalDefinition& aAnimalDefinition) const override;

		virtual void SayHello() const override;

	private:

		static bool Check(const sVersion& aVersion1, const sVersion& aVersion2, const bool aThrowException = true);
		static std::string ToString(const sVersion& aVersion);
		static bool Check(const uint32_t aMajor1, const uint32_t aMinor1, const uint32_t aPatch1, const uint32_t aMajor2, const uint32_t aMinor2, const uint32_t aPatch2, const bool aThrowException = true);
		static std::string ToString(const uint32_t aMajor, const uint32_t aMinor, const uint32_t aPatch, const std::string& aCodename);

		const sVersion		mBuiltInVersion;		//!< Built-in version data.
		const std::string	mString;				//!< Built-in version data converted to string.
	};
}

#endif