#pragma once
#include <cstdint>
#include "statblock.h"
#include "pointwell.h"
#include <memory>
#include <string>

typedef std::uint64_t exptype;
typedef std::uint16_t leveltype;

class PlayerCharacterDelegate : public StatBlock {
public:
	static const exptype LEVEL2AT = 100u;

	PlayerCharacterDelegate() : StatBlock(0u,0u,0u) {
		CurrentLevel = 1u;
		CurrentEXP = 0u;
		EXPToNextLevel = LEVEL2AT;
		HP = std::make_unique<PointWell>();
		Madness = std::make_unique<PointWell>();
		Madness->setMax(100);
		Madness->increaseCurrent(0);
	}

	void gainEXP(exptype gained_exp) {
		CurrentEXP += gained_exp;
		while (check_if_leveled()) {}
	}
	leveltype getlevel() {
		return CurrentLevel;
	}
	exptype getCurrentEXP() {
		return CurrentEXP;
	}
	exptype getEXPToNextLevel() {
		return EXPToNextLevel;
	}
	virtual void LevelUp() = 0;
	virtual std::string getClassName() = 0;

	std::unique_ptr<PointWell>HP;
	std::unique_ptr<PointWell>Madness;
	bool isDefending = false;

protected:
	leveltype CurrentLevel;
	exptype CurrentEXP;
	exptype EXPToNextLevel;

	bool check_if_leveled() {
		static const leveltype LEVELSCALAR = 2u;
		if (CurrentEXP >= EXPToNextLevel) {
			CurrentLevel++;
			LevelUp();
			EXPToNextLevel *= LEVELSCALAR;
			return true;
		}
		return false;
	}
};
// TideCaller class definition
// Healer class with high intelligence and moderate health

class TideCaller : public PlayerCharacterDelegate {
public:
	static const welltype BASEHP = (welltype)85u;
	static const stattype BASESTR = (stattype)5u;
	static const stattype BASEINT = (stattype)12u;
	static const stattype BASEEND = (stattype)8u;

	TideCaller() {
		HP->setMax(BASEHP);
		HP->increaseCurrent(BASEHP);
		increaseStats(BASESTR, BASEINT, BASEEND);
	}
	std::string getClassName() override {
		return std::string("Tide Caller");
	}

protected:
	void LevelUp() override {
		HP->setMax(HP->getMax() + BASEHP / 2);
		HP->increaseCurrent(BASEHP + BASEHP / 2);
		increaseStats(BASESTR / 2, BASEINT, BASEEND / 2);
	}
};

// ReefStrider class definition
// Assassin class with high endurance and balanced strength and intelligence

class ReefStrider : public PlayerCharacterDelegate {
public:
	static const welltype BASEHP = (welltype)90u;
	static const stattype BASESTR = (stattype)12u;
	static const stattype BASEINT = (stattype)8u;
	static const stattype BASEEND = (stattype)15u;

	ReefStrider() {
		HP->setMax(BASEHP);
		HP->increaseCurrent(BASEHP);
		increaseStats(BASESTR, BASEINT, BASEEND);
	}
	std::string getClassName() override {
		return std::string("Reef Strider");
	}

protected:
	void LevelUp() override {
		HP->setMax(HP->getMax() + BASEHP / 2);
		HP->increaseCurrent(BASEHP + BASEHP / 2);
		increaseStats(BASESTR / 2, BASEINT / 2, BASEEND);
	}
};

// Tideborn class definition
// Tank class with high health and strength

class TideBorn : public PlayerCharacterDelegate {
public:
	static const welltype BASEHP = (welltype)120u;
	static const stattype BASESTR = (stattype)20u;
	static const stattype BASEINT = (stattype)5u;
	static const stattype BASEEND = (stattype)12u;

	TideBorn() {
		HP->setMax(BASEHP);
		HP->increaseCurrent(BASEHP);
		increaseStats(BASESTR, BASEINT, BASEEND);
	}
	std::string getClassName() override {
		return std::string("TideBorn");
	}

protected:
	void LevelUp() override {
		HP->setMax(HP->getMax() + BASEHP / 2);
		HP->increaseCurrent(BASEHP + BASEHP / 2);
		increaseStats(BASESTR, BASEINT / 2, BASEEND);
	}
};

// LeviathanHunter class definition
// Ranger class with high strength and endurance

class LeviathanHunter : public PlayerCharacterDelegate {
public:
	static const welltype BASEHP = (welltype)100u;
	static const stattype BASESTR = (stattype)15u;
	static const stattype BASEINT = (stattype)8u;
	static const stattype BASEEND = (stattype)15u;

	LeviathanHunter() {
		HP->setMax(BASEHP);
		HP->increaseCurrent(BASEHP);
		increaseStats(BASESTR, BASEINT, BASEEND);
	}
	std::string getClassName() override {
		return std::string("Leviathan Hunter");
	}

protected:
	void LevelUp() override {
		HP->setMax(HP->getMax() + BASEHP / 2);
		HP->increaseCurrent(BASEHP + BASEHP / 2);
		increaseStats(BASESTR, BASEINT / 2, BASEEND / 2);
	}
};

// AbyssalMage class definition
// Mage class with high intelligence and low health

class AbyssalMage : public PlayerCharacterDelegate {
public:
	static const welltype BASEHP = (welltype)70u;
	static const stattype BASESTR = (stattype)6u;
	static const stattype BASEINT = (stattype)20u;
	static const stattype BASEEND = (stattype)8u;

	AbyssalMage() {
		HP->setMax(BASEHP);
		HP->increaseCurrent(BASEHP);
		increaseStats(BASESTR, BASEINT, BASEEND);
	}
	std::string getClassName() override {
		return std::string("Abyssal Mage");
	}

protected:
	void LevelUp() override {
		HP->setMax(HP->getMax() + BASEHP / 2);
		HP->increaseCurrent(BASEHP + BASEHP / 2);
		increaseStats(BASESTR / 2, BASEINT, BASEEND);
	}
};

class PlayerCharacter {
private:
	PlayerCharacterDelegate* pcclass;

public:
	PlayerCharacter() = delete;
	PlayerCharacter(PlayerCharacterDelegate* pc) : pcclass(pc) {}
	~PlayerCharacter() {
		delete pcclass; pcclass = nullptr;
	}

	std::string getClassName() {
		return pcclass->getClassName();
	}
	leveltype getLevel() {
		return pcclass->getlevel();
	}
	exptype getCurrentEXP() {
		return pcclass->getCurrentEXP();
	}
	exptype getEXPToNextLevel() {
		return pcclass->getEXPToNextLevel();
	}
	welltype getCurrentHP() {
		return pcclass->HP->getCurrent();
	}
	welltype getMaxHP() {
		return pcclass->HP->getMax();
	}
	welltype getMadness() {
		return pcclass->Madness->getCurrent();
	}
	welltype getMaxMadness() {
		return pcclass->Madness->getMax();
	}
	stattype getStrength() {
		return pcclass->getStrength();
	}
	stattype getIntellect() {
		return pcclass->getIntelligence();
	}
	stattype getEndurance() {
		return pcclass->getEndurance();
	}

	void gainEXP(exptype amt) {
		pcclass->gainEXP(amt);
	}
	void takeDamage(welltype amt) {
		pcclass->HP->reduceCurrent(amt);
	}
	void heal(welltype amt) {
		pcclass->HP->increaseCurrent(amt);
	}
	void addMadness(welltype amt) {
		pcclass->Madness->increaseCurrent(amt);
	}
	void defend() {
		pcclass->isDefending = true;
	}
	void cleardefend() {
		pcclass->isDefending = false;
	}
	bool isDefending() {
		return pcclass->isDefending;
	}
};
