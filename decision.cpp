#include <fstream>
#include <iostream>
#include <vector>
#include <string>
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
	Pokemon() : name("NULL"){}
	Pokemon(string name_in) : name(name_in) {}

private: //Add all necessary info here. Will devolve into subclasses depending on ability, etc.
	string name;
};
//End Goal for Pokemon Object: Will have 12 of them in battle that will correspond to the 12 mons on the field
//Interactions will occur between these things, growing more complex as AI grows.
//Need to actively track living Pokemon, and data associated with them.
//Testing Parsing of pokedex.js below
void parsePokedex(vector<Pokemon> &pokedex);

int main() {
	vector<Pokemon> pokedex; 
	parsePokedex(pokedex);
	return 0;
}

void parsePokedex(vector<Pokemon> &pokedex) {
	ifstream pin;
	pin.open("pokedex.js");
	string junk;
	getline(pin, junk); //ignore the first 2 lines
	getline(pin, junk);
	string name;
	string word;
	string characteristic;
	string characterVal;
	while (pin >> name) { //looks for <pokemon:> as indicator to move on
		if (name != "};") {
			getline(pin, junk); //throwaway rest
			while (pin >> characteristic) {
				if(characteristic != "},"){
					getline(pin, characterVal);
					if (characteristic == "species:") { //similar format will work for other things too
						characterVal = characterVal.substr(2, characterVal.length() - 4);
						name = characterVal;
						Pokemon mon(name);
						pokedex.push_back(mon);
					}
				}
				else {
					break;
				}
			}
		}
	}
	return;
}
