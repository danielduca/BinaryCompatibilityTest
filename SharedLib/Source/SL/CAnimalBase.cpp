#include "CAnimalBase.hpp"
#include <cstdio>

namespace sl
{
	CAnimalBase::CAnimalBase(const std::string& aName) :
		mName(aName)
	{
	}

	CAnimalBase::~CAnimalBase()
	{
	}

	void CAnimalBase::SayHello() const
	{
		if (mName.empty())
		{
			printf("Hello! I do not have a name. May be you have created me from an older version!\n");
		}
		else
		{
			printf("Hello! My name is '%s'.\n", mName.c_str());
		}
	}
}