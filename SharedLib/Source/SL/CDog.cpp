#include "CDog.hpp"
#include <cstdio>

namespace sl
{
	CDog::~CDog()
	{

	}

	void CDog::SayHello() const
	{
		printf("Hello! I'm a dog.\n");
	}
}