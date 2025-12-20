#pragma once
#include <cstdint>
// Stat types are between 0 and 255
typedef std::uint16_t stattype;
class StatBlock {
	// 0xFF
	stattype Strength;
	stattype Intelligence;
	stattype Endurance;
	stattype Dexterity;
	stattype Speed;
	stattype Madness;

public:
	StatBlock() { 
		Strength = (stattype)1u;
		Intelligence = (stattype)1u;
		Endurance = (stattype)1u;
		Dexterity = (stattype)1u;
		Speed = (stattype)1u;
		Madness = (stattype)1u;


	}
	explicit StatBlock(stattype s, stattype i, stattype e, stattype d, stattype a, stattype m) {
		Strength = s;
		Intelligence = i;
		Endurance = e;
		Dexterity = d;
		Speed = a;
		Madness = m;

	}
	stattype getStrength() { return Strength; }
	stattype getIntelligence() { return Intelligence; }
	stattype getEndurance() { return Endurance; }
	stattype getDexterity() { return Dexterity; }
	stattype getSpeed() { return Speed; }
	stattype getMadness() { return Madness; }

protected:
	void increaseStats(stattype s, stattype i, stattype e, stattype d, stattype a) {
		Strength += s;
		Intelligence += i;
		Endurance += e;
		Dexterity += d;
		Speed += a;
	}

};
