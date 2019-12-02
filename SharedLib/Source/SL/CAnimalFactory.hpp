#ifndef SHARED_LIB_C_ANIMAL_FACTORY_HPP
#define SHARED_LIB_C_ANIMAL_FACTORY_HPP

#include "SL/IAnimalFactory.hpp"

namespace sl
{
	class CAnimalFactory : public IAnimalFactory
	{
	public:
		// 1.0
		virtual IAnimal* Create(const eAnimalType aAnimalType) const override;
		virtual void Destroy(IAnimal* const apAnimal) override;

		// 1.2
		// Method overload not BC on Windows!
		// @todo: check on Linux.
		//virtual IAnimal* Create(const sAnimalDefinition& aAnimalDefinition) const override;
		virtual IAnimal* CreateV2(const sAnimalDefinition& aAnimalDefinition) const override;
	};
}

#endif
