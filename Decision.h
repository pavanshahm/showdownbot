#include "Type.h"
#include "Attack.h"
#include "Pokemon.h
#include <vector>
#include <string>


class decision{
	private:
		void parsePokedex(vector<Pokemon> &pokedex);
		vector<Pokemon> pokedex; 
	public:
		decision();
		makeDecision(std::string info);
}