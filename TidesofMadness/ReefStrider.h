#pragma once
#include "hp.h"
#include "statblock.h"
#include "LevelSystem.h"

// ReefStrider class definition
// Assassin class with high endurance and balanced strength and intelligence


class ReefStrider : public hp, public StatBlock, public LevelSystem {

public:
	static const hptype HPGROWTH = (hptype)90u;
	static const stattype BASESTR = (stattype)12u;
	static const stattype BASEINT = (stattype)8u;
	static const stattype BASEEND = (stattype)20u;

	ReefStrider() : hp(HPGROWTH, HPGROWTH), StatBlock(BASESTR, BASEINT, BASEEND) {}



private:
};

