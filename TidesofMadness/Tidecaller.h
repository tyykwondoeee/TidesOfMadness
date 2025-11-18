#pragma once
#include "hp.h"
#include "statblock.h"
#include "LevelSystem.h"

// TideCaller class definition
// Healer class with high intelligence and moderate health

class TideCaller : public hp, public StatBlock, public LevelSystem {
public:

	static const hptype BASEHP = (hptype)85u;
	static const stattype BASESTR = (stattype)5u;
	static const stattype BASEINT = (stattype)20u;
	static const stattype BASEEND = (stattype)8u;

	static const hptype HPGROWTH = (hptype)40u;
	static const stattype STRGROWTH = (stattype)1u;
	static const stattype INTGROWTH = (stattype)10u;
	static const stattype ENDGROWTH = (stattype)3u;

	TideCaller() : hp(BASEHP, BASEHP), StatBlock(BASESTR, BASEINT, BASEEND) {}

private:
	void LevelUp() override {
		setMaxHp(HPGROWTH + getMaxHP());
		increaseStats(STRGROWTH, INTGROWTH, ENDGROWTH);
	}
};

