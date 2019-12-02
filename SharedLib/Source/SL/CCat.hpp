#ifndef SHARED_LIB_C_CAT_HPP
#define SHARED_LIB_C_CAT_HPP

#include "SL/IAnimal.hpp"

namespace sl
{
	class CCat : public IAnimal
	{
	public:
		virtual ~CCat();
		virtual void SayHello() const override;
	};
}

#endif
