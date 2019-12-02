
#include "CAnimalFactory.hpp"
#include "CDog.hpp"
#include "CCat.hpp"

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

			case eAnimalType::Cat:
			{
				pReturnValue = new CCat();
				printf("CAnimalFactory: CCat object created.\n");
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
		if (auto* const pValue = dynamic_cast<CDog*>(apAnimal))
		{
			delete pValue;
			printf("CAnimalFactory: CDog object destroyed.\n");
		}
		else if (auto* const pValue = dynamic_cast<CCat*>(apAnimal))
		{
			delete pValue;
			printf("CAnimalFactory: CCat object destroyed.\n");
		}
	}

	SL_API IAnimalFactory* GetAnimalFactory()
	{
		static CAnimalFactory AnimalFactory;
		return &AnimalFactory;
	}
}