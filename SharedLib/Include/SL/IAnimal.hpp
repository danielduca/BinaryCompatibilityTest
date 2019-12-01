#ifndef SHARED_LIB_I_ANIMAL_HPP
#define SHARED_LIB_I_ANIMAL_HPP

#include "SL/API.hpp"

namespace sl
{
	class IAnimal
	{
	public:
		virtual void SayHello() const = 0;
	};
}

#endif
