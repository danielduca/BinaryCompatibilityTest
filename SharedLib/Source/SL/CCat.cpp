#include "CCat.hpp"
#include <cstdio>

namespace sl
{
	CCat::~CCat()
	{

	}

	void CCat::SayHello() const
	{
		printf("Hello! I'm a cat.\n");
	}
}