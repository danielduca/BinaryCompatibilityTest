
#include "CAnimalFactory.hpp"
#include "CDog.hpp"

namespace sl
{
	IAnimal* CAnimalFactory::Create(const eAnimalType aAnimalType) const
	{
		IAnimal* pReturnValue = nullptr;

		switch (aAnimalType)
		{
			case eAnimalType::Dog:
			{
				pReturnValue = new CDog();
				printf("CAnimalFactory: CDog object created.\n");
			}
			break;

			default:
			{
				pReturnValue = nullptr;
				printf("CAnimalFactory: No object created.\n");
			}
		}

		return pReturnValue;
	}
	
	void CAnimalFactory::Destroy(IAnimal* const apAnimal)
	{
		CDog* const pDog = dynamic_cast<CDog*>(apAnimal);

		if (pDog != nullptr)
		{
			delete pDog;
			printf("CAnimalFactory: CDog object destroyed.\n");
		}
	}

	SL_API IAnimalFactory* GetAnimalFactory()
	{
		static CAnimalFactory AnimalFactory;
		return &AnimalFactory;
	}
}