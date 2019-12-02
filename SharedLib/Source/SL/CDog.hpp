#ifndef SHARED_LIB_C_DOG_HPP
#define SHARED_LIB_C_DOG_HPP

#include "CAnimalBase.hpp"

namespace sl
{
	class CDog : public CAnimalBase
	{
	public:
		CDog(const std::string& aName);
		virtual void SayHello() const override;
	};
}

#endif
