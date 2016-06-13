#include "Pokemon.h"
#include "Attack.h"
#include "Type.h"

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