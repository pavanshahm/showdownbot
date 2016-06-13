#ifndef TYPE_H
#define TYPE_H
#pragma once

#include<string>

//interface to represent a Type in Pokemon. Uses Enum
class Type {
public:
	enum TypeVal {
		NORMAL, FIRE, WATER,
		ELECTRIC, GRASS, ICE, FIGHTING,
		POISON, GROUND, FLYING, PSYCHIC, 
		BUG, ROCK, GHOST, DRAGON,
		DARK, STEEL, FAIRY
	};
	Type(std::string type_in) : val(stringToType(type_in)), typestring(type_in) {}

	bool isWeakTo(Type attackType);
	bool resists(Type attackType);
	bool isImmuneTo(Type attackType);
	double attackScale(Type attackType);
	bool operator==(const Type &otherType);

private:
	static const double typechart[18][18];
	Type::TypeVal val;
	std::string typestring;
	Type::TypeVal stringToType(std::string type_in);
};
#endif // !TYPE_H