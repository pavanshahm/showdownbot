#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <cmath>

#include "Type.h"
#include "Attack.h"
#include "Pokemon.h"
#include "Decision.h"
using std::string;
using std::vector;
using std::ifstream;
//Skeleton Code Here. Just pseudocode describing general behavior
//Algorithm makedecision: Will return a move (in number format presumably)
//Either choice of attack or choice of switch
//Base level of implementation. Takes into account typing and speed.


//Objects:

//End Goal for Pokemon Object: Will have 12 of them in battle that will correspond to the 12 mons on the field
//Interactions will occur between these things, growing more complex as AI grows.
//Need to actively track living Pokemon, and data associated with them.
//Testing Parsing of pokedex.js below


Decision::Decision() {
	parsePokedex(pokedex);
	Type dark("Dark");
	Type fighting("Fighting");
	Type psy("Psychic");
	assert(dark.isWeakTo(fighting));
	assert(dark.resists(psy));
	assert(dark.isImmuneTo(psy));
	assert(fighting.isWeakTo(psy));
	assert(!(fighting == dark));


	Attack psychic("Psychic", psy);
	assert(pokedex[0].getName() == "Bulbasaur");
	assert(abs(pokedex[0].attackEffectiveness(psychic) - 2.0) < 0.001);
	assert(pokedex[514].getName() == "Croagunk");
	assert(abs(pokedex[514].attackEffectiveness(psychic) - 4.0) < 0.001);
	assert(pokedex[291].getName() == "Poochyena");
	assert(abs(pokedex[291].attackEffectiveness(psychic)) < 0.001);
	assert(pokedex[287].getName() == "Mudkip");
	assert(abs(pokedex[287].attackEffectiveness(psychic) - 1.0) < 0.001);
	assert(pokedex[728].getName() == "Cobalion");
	assert(abs(pokedex[728].attackEffectiveness(psychic) - 1.0) < 0.001);
	assert(pokedex[422].getName() == "Metagross");
	assert(abs(pokedex[422].attackEffectiveness(psychic) - 0.25) < 0.001);
	return 0;
}

void Decision::parsePokedex(vector<Pokemon> &pokedex) {
	ifstream pin;
	pin.open("pokedex.js");
	string junk;
	getline(pin, junk); //ignore the first 3 lines
	getline(pin, junk);
	getline(pin, junk);
	string name;
	string type1, type2;
	string word;
	string characteristic;
	string characterVal;
	while (pin >> name) { //looks for <pokemon:> as indicator to move on
		if (name != "};") {
			getline(pin, junk); //throwaway rest
			while (pin >> characteristic) {
				if(characteristic != "},") {
					getline(pin, characterVal);
					if (characteristic == "species:") { //similar format will work for other things too
						characterVal = characterVal.substr(2, characterVal.length() - 4);
						name = characterVal;
						
					}
					if (characteristic == "types:") { //need to parse " ["Type1", "Type2"],"
						if (characterVal.find(',') == characterVal.length() - 1) {
							type1 = characterVal.substr(3, characterVal.length() - 6);
							type2 = type1;
						}
						else {
							type1 = characterVal.substr(3, characterVal.find(',') - 4);
							type2 = characterVal.substr(characterVal.find(',') + 3, characterVal.length() - (type1.length() + 10));
						}
					}
				}
				else {
					Pokemon mon(name, type1, type2);
					pokedex.push_back(mon);
					break;
				}
			}
		}
	}
	return;
}

std::string Decision::makeDecision(std::string info){
	return 'a'
}