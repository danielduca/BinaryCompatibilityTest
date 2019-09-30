#ifndef C_FUCKIN_CLASS_H
#define C_FUCKIN_CLASS_H

#include "IFuckinClass.h"

namespace dlib
{
	class CFuckinClass : public IFuckingClass
	{
	public:
		virtual ~CFuckinClass();
		virtual int GetData() override;
		virtual std::string DoAction() override;

	private:

		std::string mData;
	};
}

#endif
