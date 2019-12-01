#include <cstdio>
#include <stdexcept>
#include "SL/API.hpp"
#include "SL/IVersion.hpp"
#include "SL/IAnimalFactory.hpp"

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

int main()
{
	try
	{
		const sl::sVersion& Version = sl::VERSION;
		const sl::sVersion& BuiltInVersion = sl::GetVersion()->GetBuiltInVersion();
		printf("Compiled with version: %u.%u.%u '%s'.\n", Version.Major, Version.Minor, Version.Patch, Version.Codename.c_str());
		printf("Shared lib version: %u.%u.%u '%s'.\n", BuiltInVersion.Major, BuiltInVersion.Minor, BuiltInVersion.Patch, BuiltInVersion.Codename.c_str());

		sl::IAnimal* const pDog = sl::GetAnimalFactory()->Create(sl::eAnimalType::Dog);
		pDog->SayHello();
		sl::GetAnimalFactory()->Destroy(pDog);
	}
	catch (const std::exception& e)
	{
		printf("Exception catched: '%s'.\n", e.what());
	}

	printf("Press any key to exit.");
	getchar();

	return 0;
}