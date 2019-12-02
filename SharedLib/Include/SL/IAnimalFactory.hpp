#ifndef SHARED_LIB_I_ANIMAL_FACTORY_HPP
#define SHARED_LIB_I_ANIMAL_FACTORY_HPP

#include "SL/API.hpp"
#include "SL/IAnimal.hpp"

namespace sl
{
	enum class eAnimalType
	{
		None = 0,
		Dog,
		Cat,
		Number
	};

	class IAnimalFactory
	{
	public:
		virtual IAnimal* Create(const eAnimalType aAnimalType) const = 0;
		virtual void Destroy(IAnimal* const apAnimal) = 0;
	};

	SL_API IAnimalFactory* GetAnimalFactory();
}

#endif
