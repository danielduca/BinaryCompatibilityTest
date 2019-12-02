#include "CCat.hpp"
#include <cstdio>

namespace sl
{
	CCat::CCat(const std::string& aName)	:
		CAnimalBase(aName)
	{
	}

	void CCat::SayHello() const
	{
		CAnimalBase::SayHello();
		printf("Hello! I'm a cat.\n");
	}
}