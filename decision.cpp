#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cassert>

#include "Type.h"
using std::string;
using std::vector;
using std::ifstream;
//Skeleton Code Here. Just pseudocode describing general behavior
//Algorithm makedecision: Will return a move (in number format presumably)
//Either choice of attack or choice of switch
//Base level of implementation. Takes into account typing and speed.


//Objects:
//Pokemon Object:
class Pokemon { 
public:
	Pokemon() : name("NULL"), firstType("NULL"), secondType("NULL"){}
	Pokemon(string name_in, string type1_in, string type2_in) 
		: name(name_in), firstType(type1_in), secondType(type2_in) {}

private: //Add all necessary info here. Will devolve into subclasses depending on ability, etc.
	string name;
	Type firstType;
	Type secondType; //will be the same if MonoType
};
//End Goal for Pokemon Object: Will have 12 of them in battle that will correspond to the 12 mons on the field
//Interactions will occur between these things, growing more complex as AI grows.
//Need to actively track living Pokemon, and data associated with them.
//Testing Parsing of pokedex.js below
void parsePokedex(vector<Pokemon> &pokedex);

int main() {
	vector<Pokemon> pokedex; 
	parsePokedex(pokedex);
	Type dark("Dark");
	Type fighting("Fighting");
	Type psychic("Psychic");
	assert(dark.isWeakTo(fighting));
	assert(dark.resists(psychic));
	assert(dark.isImmuneTo(psychic));
	assert(fighting.isWeakTo(psychic));
	return 0;
}

void parsePokedex(vector<Pokemon> &pokedex) {
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
