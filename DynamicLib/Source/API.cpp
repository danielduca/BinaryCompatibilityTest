#include "API.h"
#include "CVersion.h"

#include "CClass1.h"
#include "CClass2.h"
#include "CFuckinClass.h"

#include <cstdio>

namespace dlib
{
	static IVersion* pVersion = nullptr;
	static IClass1* pClass1 = nullptr;
	static IClass2* pClass2 = nullptr;
	static IFuckingClass* pFuckinClass = nullptr;
	static IGame* pGame = nullptr;

	void Init()
	{
		pVersion = new CVersion();
		pClass1 = new CClass1();
		pClass2 = new CClass2();
		pFuckinClass = new CFuckinClass();
	}

	void Close()
	{
		delete pFuckinClass;
		delete pClass2;
		delete pClass1;
		delete pVersion;
	}

	IVersion* GetVersion()
	{
		return pVersion;
	}

	IClass1* GetClass1()
	{
		return pClass1;
	}

	IClass2* GetClass2()
	{
		return pClass2;
	}

	IFuckingClass* GetFuckinClass()
	{
		return pFuckinClass;
	}

	void SetGame(IGame* const apGame)
	{
		pGame = apGame;

		if (pGame != nullptr)
		{
			printf("Name: %s.\n", pGame->GetName().c_str());

			IGame2* const pGame2 = dynamic_cast<IGame2*>(pGame);

			if (pGame2 != nullptr)
			{
				printf("Description: %s.\n", pGame2->GetDescription().c_str());
			}

			IGame3* const pGame3 = dynamic_cast<IGame3*>(pGame);

			if (pGame3 != nullptr)
			{
				printf("Version: %s.\n", pGame3->GetVersion().c_str());
			}
		}
		else
		{
			printf("<null game>\n");
		}
	}
}
