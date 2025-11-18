#pragma once
#include <cstdint>
// Stat types are between 0 and 255
typedef std::uint16_t stattype;
class StatBlock {
	// 0xFF
	stattype Strength;
	stattype Intelligence;
	stattype Endurance;
public:
	StatBlock() { 
		Strength = (stattype)1u;
		Intelligence = (stattype)1u;
		Endurance = (stattype)1u;
	}
	explicit StatBlock(stattype s, stattype i, stattype e) {
		Strength = s;
		Intelligence = i;
		Endurance = e;
	}
	stattype getStrength() { return Strength; }
	stattype getIntelligence() { return Intelligence; }
	stattype getEndurance() { return Endurance; }

protected:
	void increaseStats(stattype s, stattype i, stattype e) {
		Strength += s;
		Intelligence += i;
		Endurance += e;
	}

};
