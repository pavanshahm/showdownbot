#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include "Type.h"
#include "Attack.h"
using std::string;

//Pokemon Object. Represents the Entire Pokemon, with all necessary information used in battle
class Pokemon {
public:
	Pokemon() : name("NULL"), firstType("NULL"), secondType("NULL"), monotype(true) {}
	Pokemon(string name_in, string type1_in, string type2_in)
		: name(name_in), firstType(type1_in), secondType(type2_in), monotype(firstType == secondType) {}

	string getName() { return name; }
	double attackEffectiveness(Attack a);
private: //Add all necessary info here. Will devolve into subclasses depending on ability, etc.
	string name;
	Type firstType;
	Type secondType; //will be the same if MonoType
	bool monotype;
};

double Pokemon::attackEffectiveness(Attack a) {
	if (monotype) {
		return firstType.attackScale(a.getType());
	}
	else {
		double mult1 = firstType.attackScale(a.getType());
		double mult2 = secondType.attackScale(a.getType());
		return mult1 * mult2;
	}
}
#endif // !POKEMON_H
