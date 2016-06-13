#ifndef DECISION
#define DECISION

#include <vector>
#include <string>

#include "AI/Type.h"
#include "AI/Attack.h"
#include "AI/Pokemon.h"



class Decision{
	private:
		void parsePokedex(std::vector<Pokemon> &pokedex);
		std::vector<Pokemon> pokedex; 
	public:
		Decision();
		int makeDecision(std::string info);
};
#endif
