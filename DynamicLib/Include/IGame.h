#ifndef I_GAME_H
#define I_GAME_H

#include <string>

namespace dlib
{
	class IGame
	{
	public:
		virtual ~IGame() {}
		virtual const std::string& GetName() const = 0;
	};

	class IGame2 : public IGame
	{
	public:
		virtual const std::string& GetDescription() const = 0;
	};

	class IGame3 : public IGame
	{
	public:
		virtual const std::string& GetVersion() const = 0;
	};
}

#endif
