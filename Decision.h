#include "AI/Type.h"
#include "AI/Attack.h"
#include "AI/Pokemon.h"
#include <vector>
#include <string>


class decision{
	private:
		void parsePokedex(std::vector<Pokemon> &pokedex);
		std::vector<Pokemon> pokedex; 
	public:
		decision();
		int makeDecision(std::string info);
}
