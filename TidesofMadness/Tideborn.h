#pragma once
#include "hp.h"
#include "statblock.h"
#include "LevelSystem.h"

// Tideborn class definition
// Tank class with high health and strength


class Tideborn : public hp, public StatBlock {

public:
	static const hptype HPGROWTH = (hptype)120u;
	static const stattype BASESTR = (stattype)20u;
	static const stattype BASEINT = (stattype)5u;
	static const stattype BASEEND = (stattype)15u;

	Tideborn() : hp(HPGROWTH, HPGROWTH), StatBlock(BASESTR, BASEINT, BASEEND) {}



private:
};
