// interface.i

%module interface
%{
#define SWIG_FILE_WITH_INIT
#include "Decision.h"
#include "AI/Type.h"
#include "AI/Attack.h"
#include "AI/Pokemon.h"
#include <vector>
#include <string>
%}

class decision{
	private:
		void parsePokedex(std::vector<Pokemon> &pokedex);
		std::vector<Pokemon> pokedex; 
		
	public:
		decision();
		int makeDecision(std::string info);
};
