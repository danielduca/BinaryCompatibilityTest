#ifndef SHARED_LIB_C_DOG_HPP
#define SHARED_LIB_C_DOG_HPP

#include "SL/IAnimal.hpp"

namespace sl
{
	class CDog : public IAnimal
	{
	public:
		virtual void SayHello() const override;
	};
}

#endif
