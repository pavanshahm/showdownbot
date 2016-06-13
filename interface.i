// interface.i

%module interface
%{
#define SWIG_FILE_WITH_INIT
#define pascal

#include "Decision.h"
%}

class Decision{
	private:
		void parsePokedex(std::vector<Pokemon> &pokedex);
		std::vector<Pokemon> pokedex; 
		
	public:
		Decision();
		int makeDecision(std::string info);
};
