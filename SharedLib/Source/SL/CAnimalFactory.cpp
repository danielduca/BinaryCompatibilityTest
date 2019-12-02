
#include "CAnimalFactory.hpp"
#include "CDog.hpp"
#include "CCat.hpp"

namespace sl
{
	IAnimal* CAnimalFactory::Create(const eAnimalType aAnimalType) const
	{
		return Create({aAnimalType, ""});
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

	IAnimal* CAnimalFactory::Create(const sAnimalDefinition& aAnimalDefinition) const
	{
		IAnimal* pReturnValue = nullptr;

		switch (aAnimalDefinition.AnimalType)
		{
			case eAnimalType::Dog:
			{
				pReturnValue = new CDog(aAnimalDefinition.Name);
				printf("CAnimalFactory: CDog object created.\n");
			}
			break;

			case eAnimalType::Cat:
			{
				pReturnValue = new CCat(aAnimalDefinition.Name);
				printf("CAnimalFactory: CCat object created.\n");
			}
			break;
		}

		return pReturnValue;
	}

	SL_API IAnimalFactory* GetAnimalFactory()
	{
		static CAnimalFactory AnimalFactory;
		return &AnimalFactory;
	}
}