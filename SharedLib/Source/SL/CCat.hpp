#ifndef SHARED_LIB_C_CAT_HPP
#define SHARED_LIB_C_CAT_HPP

#include "CAnimalBase.hpp"

namespace sl
{
	class CCat : public CAnimalBase
	{
	public:
		CCat(const std::string& aName);
		virtual void SayHello() const override;
	};
}

#endif
