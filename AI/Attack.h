#ifndef ATTACK_H
#define ATTACK_H

#include <string>
#include "Type.h"

using std::string;

//class that represents an attack.
class Attack {
public:
	Attack() : atkName("NULL"), attackType("NULL") {}
	Attack(string name, Type type_in) : atkName(name), attackType(type_in) {}

	Type getType() const { return attackType; }
private:
	string atkName;
	Type attackType;
	//TODO: Still need power, damage vs status, etc. 
};

#endif
