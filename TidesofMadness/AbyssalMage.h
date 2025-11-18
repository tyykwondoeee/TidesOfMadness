#pragma once
#include "hp.h"
#include "statblock.h"
#include "LevelSystem.h"

// AbyssalMage class definition
// Mage class with high intelligence and low health


class AbyssalMage : public hp, public StatBlock, public LevelSystem {

public:
	static const hptype HPGROWTH = (hptype)70u;
	static const stattype BASESTR = (stattype)5u;
	static const stattype BASEINT = (stattype)20u;
	static const stattype BASEEND = (stattype)8u;

	AbyssalMage() : hp(HPGROWTH, HPGROWTH), StatBlock(BASESTR, BASEINT, BASEEND) {}



private:
};
