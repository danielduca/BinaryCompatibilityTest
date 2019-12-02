#ifndef SHARED_LIB_I_ANIMAL_FACTORY_HPP
#define SHARED_LIB_I_ANIMAL_FACTORY_HPP

#include "SL/API.hpp"
#include "SL/IAnimal.hpp"
#include <string>

namespace sl
{
	enum class eAnimalType
	{
		None = 0,
		Dog,
		Cat,
		Number
	};

	struct sAnimalDefinition
	{
		eAnimalType AnimalType;
		std::string Name;
	};

	class IAnimalFactory
	{
	public:
		
		// 1.0
		virtual IAnimal* Create(const eAnimalType aAnimalType) const = 0;
		virtual void Destroy(IAnimal* const apAnimal) = 0;

		// 1.2
		virtual IAnimal* CreateV2(const sAnimalDefinition& aAnimalDefinition) const = 0;

		// Method overload
		// Windows (MSVC++ 14.23): NOT BINARY BACKWARD COMPATIBLE.
		// Linux (g++ (Debian 4.9.2-10) 4.9.2): BINARY BACKWARD COMPATIBLE.
		// virtual IAnimal* Create(const sAnimalDefinition& aAnimalDefinition) const = 0;
	};

	SL_API IAnimalFactory* GetAnimalFactory();
}

#endif
