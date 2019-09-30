
#ifndef I_FUCKING_CLASS_H
#define I_FUCKING_CLASS_H

#include <string>

namespace dlib
{
	class IFuckingClass
	{
	public:
		virtual ~IFuckingClass() {};
		virtual std::string DoAction() = 0;
		virtual int GetData() = 0;
	};
}

#endif
