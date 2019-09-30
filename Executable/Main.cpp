#include <cstdio>
#include <stdexcept>
#include "API.h"

#define TO_STRING(a) #a
#define CHECK(a)												\
	printf("%s: ", TO_STRING(a));								\
	if (a)														\
	{															\
		printf("ok!\n");										\
	}															\
	else														\
	{															\
		printf("bad!\n");										\
		throw std::runtime_error("Check error");				\
	}															\

class CGame : public dlib::IGame2
{
public:
	CGame(const std::string& aName, const std::string& aDescription) :
		mName(aName),
		mDescription(aDescription)
	{
	}

	virtual const std::string& GetName() const override
	{
		return mName;
	}

	virtual const std::string& GetDescription() const override
	{
		return mDescription;
	}

private:
	std::string mName;
	std::string mDescription;
};

int main()
{
	try
	{
		dlib::Init();

		DLIB_CHECK_VERSION(0, 0, 0);
		printf("exec: %s.\n", dlib::GetVersion()->ToString(MAJOR_VERSION, MINOR_VERSION, PATCH_VERSION, CODENAME).c_str());
		printf("dlib: %s.\n", dlib::GetVersion()->ToString().c_str());
		printf("\n");

		CGame Game("POKER", "Trocotro!");

		dlib::IClass1* const pClass1 = dlib::GetClass1();
		dlib::IClass2* const pClass2 = dlib::GetClass2();
		dlib::IFuckingClass* const pFuckinClass = dlib::GetFuckinClass();
		dlib::SetGame(&Game);

		CHECK(pClass1->Get0() == 0);
		CHECK(pClass1->Get1() == 1);
		CHECK(pClass1->Get2() == 2);
		CHECK(pClass1->Get3() == 3);
		CHECK(pClass1->Get4() == 4);
		CHECK(pClass2->Get10() == 10);
		CHECK(pClass2->Get11() == 11);
		CHECK(pClass2->Get12() == 12);
		CHECK(pClass2->Get13() == 13);
		CHECK(pClass2->Get14() == 14);

		CHECK(pFuckinClass->DoAction() == "Fuck! ");
		CHECK(pFuckinClass->DoAction() == "Fuck! Fuck! ");
		CHECK(pFuckinClass->DoAction() == "Fuck! Fuck! Fuck! ");

		pClass1->ProcessStruct1({ 7, 0.5, "pepe" }, { 'a', "manolo", 9 });

		dlib::Close();

		printf("\n");

		printf("All ok!\n");
	}
	catch (const std::exception& e)
	{
		printf("Exception catched: '%s'.\n", e.what());
	}

	printf("Test finished.\n");

	getchar();

	return 0;
}