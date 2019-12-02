#include "CDog.hpp"
#include <cstdio>

namespace sl
{
	CDog::CDog(const std::string& aName) :
		CAnimalBase(aName)
	{
	}

	void CDog::SayHello() const
	{
		CAnimalBase::SayHello();
		printf("I'm a dog.\n");
	}
}