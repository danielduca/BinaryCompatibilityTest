#include "CFuckinClass.h"

namespace dlib
{
	CFuckinClass::~CFuckinClass()
	{
	}

	int CFuckinClass::GetData()
	{
		return 7;
	}

	std::string CFuckinClass::DoAction()
	{
		mData += "Fuck! ";
		return mData;
	}
}