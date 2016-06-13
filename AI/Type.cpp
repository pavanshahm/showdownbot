#include <string>
#include "Type.h"

using std::string;

const double Type::typechart[18][18] = {
	{ 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,0.5,  0,  1,  1,0.5,  1 },
	{ 1,0.5,0.5,  1,  2,  2,  1,  1,  1,  1,  1,  2,0.5,  1,0.5,  1,  2,  1 },
	{ 1,  2,0.5,  1,0.5,  1,  1,  1,  2,  1,  1,  1,  2,  1,0.5,  1,  1,  1 },
	{ 1,  1,  2,0.5,0.5,  1,  1,  1,  0,  2,  1,  1,  1,  1,0.5,  1,  1,  1 },
	{ 1,0.5,  2,  1,0.5,  1,  1,0.5,  2,0.5,  1,0.5,  2,  1,0.5,  1,0.5,  1 },
	{ 1,0.5,0.5,  1,  2,0.5,  1,  1,  2,  2,  1,  1,  1,  1,  2,  1,0.5,  1 },
	{ 2,  1,  1,  1,  1,  2,  1,0.5,  1,0.5,0.5,0.5,  2,  0,  1,  2,  2,0.5 },
	{ 1,  1,  1,  1,  2,  1,  1,0.5,0.5,  1,  1,  1,0.5,0.5,  1,  1,  0,  2 },
	{ 1,  2,  1,  2,0.5,  1,  1,  2,  1,  0,  1,0.5,  2,  1,  1,  1,  2,  1 },
	{ 1,  1,  1,0.5,  2,  1,  2,  1,  1,  1,  1,  2,0.5,  1,  1,  1,0.5,  1 },
	{ 1,  1,  1,  1,  1,  1,  2,  2,  1,  1,0.5,  1,  1,  1,  1,  0,0.5,  1 },
	{ 1,0.5,  1,  1,  2,  1,0.5,0.5,  1,0.5,  2,  1,  1,0.5,  1,  2,0.5,0.5 },
	{ 1,  2,  1,  1,  1,  2,0.5,  1,0.5,  2,  1,  2,  1,  1,  1,  1,0.5,  1 },
	{ 0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  1,  1,  2,  1,0.5,  1,  1 },
	{ 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  1,0.5,  0 },
	{ 1,  1,  1,  1,  1,  1,0.5,  1,  1,  1,  2,  1,  1,  2,  1,0.5,  1,0.5 },
	{ 1,0.5,0.5,0.5,  1,  2,  1,  1,  1,  1,  1,  1,  2,  1,  1,  1,0.5,  2 },
	{ 1,0.5,  1,  1,  1,  1,  2,0.5,  1,  1,  1,  1,  1,  1,  2,  2,0.5,  1 }
};

Type::TypeVal Type::stringToType(string type_in) {
	if (type_in == "Normal") {
		return Type::NORMAL;
	}
	else if (type_in == "Fire") {
		return Type::FIRE;
	}
	else if (type_in == "Water") {
		return Type::WATER;
	}
	else if (type_in == "Electric") {
		return Type::ELECTRIC;
	}
	else if (type_in == "Grass") {
		return Type::GRASS;
	}
	else if (type_in == "Ice") {
		return Type::ICE;
	}
	else if (type_in == "Fighting") {
		return Type::FIGHTING;
	}
	else if (type_in == "Poison") {
		return Type::POISON;
	}
	else if (type_in == "Ground") {
		return Type::GROUND;
	}
	else if (type_in == "Flying") {
		return Type::FLYING;
	}
	else if (type_in == "Psychic") {
		return Type::PSYCHIC;
	}
	else if (type_in == "Bug") {
		return Type::BUG;
	}
	else if (type_in == "Rock") {
		return Type::ROCK;
	}
	else if (type_in == "Ghost") {
		return Type::GHOST;
	}
	else if (type_in == "Dragon") {
		return Type::DRAGON;
	}
	else if (type_in == "Dark") {
		return Type::DARK;
	}
	else if (type_in == "Steel") {
		return Type::STEEL;
	}
	else if (type_in == "Fairy") {
		return Type::FAIRY;
	}
	else if (type_in == "Bird") { //missigno edge Case
		return Type::FLYING;
	}
	else {
		return Type::NORMAL;
	}
}

bool Type::isWeakTo(Type attackType) {
	return typechart[attackType.val][val] > 1;
}

bool Type::resists(Type attackType) {
	return typechart[attackType.val][val] < 1;
}

bool Type::isImmuneTo(Type attackType) {
	return typechart[attackType.val][val] == 0;
}

double Type::attackScale(Type attackType) {
	return typechart[attackType.val][val];
}
bool Type::operator==(const Type &otherType) {
	return val == otherType.val;
}
