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
		virtual IAnimal* Create(const sAnimalDefinition& aAnimalDefinition) const override;
	};
}

#endif
