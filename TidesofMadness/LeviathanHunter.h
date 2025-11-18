#pragma once
#include "hp.h"
#include "statblock.h"
#include "LevelSystem.h"

// LeviathanHunter class definition
// Ranger class with high strength and endurance


class LeviathanHunter : public hp, public StatBlock, public LevelSystem {

public:
	static const hptype HPGROWTH = (hptype)100u;
	static const stattype BASESTR = (stattype)15u;
	static const stattype BASEINT = (stattype)8u;
	static const stattype BASEEND = (stattype)15u;

	LeviathanHunter() : hp(HPGROWTH, HPGROWTH), StatBlock(BASESTR, BASEINT, BASEEND) {}



private:
};

