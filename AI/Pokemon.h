#ifndef POKEMON_H
#define POKEMON_H
#pragma once

#include <string>

#include "Type.h"
#include "Attack.h"

//Pokemon Object. Represents the Entire Pokemon, with all necessary information used in battle
class Pokemon {
public:
	Pokemon() : name("NULL"), firstType("NULL"), secondType("NULL"), monotype(true) {}
	Pokemon(std::string name_in, std::string type1_in, std::string type2_in)
		: name(name_in), firstType(type1_in), secondType(type2_in), monotype(firstType == secondType) {}

	std::string getName() { return name; }
	double attackEffectiveness(Attack a);
private: //Add all necessary info here. Will devolve into subclasses depending on ability, etc.
	std::string name;
	Type firstType;
	Type secondType; //will be the same if MonoType
	bool monotype;
};
#endif // !POKEMON_H
