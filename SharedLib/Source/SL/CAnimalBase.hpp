#ifndef SHARED_LIB_C_ANIMAL_BASE_HPP
#define SHARED_LIB_C_ANIMAL_BASE_HPP

#include "SL/IAnimal.hpp"
#include <string>

namespace sl
{
	class CAnimalBase : public IAnimal
	{
	public:
		CAnimalBase(const std::string& aName);
		virtual ~CAnimalBase();
		virtual void SayHello() const override;

	private:

		std::string mName;
	};
}

#endif
