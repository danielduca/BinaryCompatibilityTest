#include "CClass1.h"
#include <cstdio>

namespace dlib
{
	CClass1::~CClass1()
	{
	}

	unsigned int CClass1::Get0() const
	{
		return 0;
	}

	unsigned int CClass1::Get1() const
	{
		return 1;
	}

	unsigned int CClass1::Get2() const
	{
		return 2;
	}

	unsigned int CClass1::Get3() const
	{
		return 3;
	}

	unsigned int CClass1::Get4() const
	{
		return 4;
	}

	void CClass1::ProcessStruct1(const sStruct1& aStruct1, const sStruct2& aStruct2) const
	{
		printf("ProcessStruct1:\n");
		printf("Struct1:\n");
		printf("Integer: %d.\n", aStruct1.Integer);
		printf("Float: %f.\n", aStruct1.Float);
		printf("String: %s.\n", aStruct1.String.c_str());
		printf("Struct2:\n");
		printf("Char: %c.\n", aStruct2.Char);
		printf("String: %s.\n", aStruct2.String.c_str());
		printf("Integer: %d.\n", aStruct2.Integer);
	}
}
