#pragma once
#include <cstdint>
#include "statblock.h"
#include "pointwell.h"
#include "resourcetype.h"
#include <memory>
#include <string>

typedef std::uint64_t exptype;
typedef std::uint16_t leveltype;

class PlayerCharacterDelegate : public StatBlock {
public:
	static const exptype LEVEL2AT = 100u;

	PlayerCharacterDelegate() : StatBlock(0u,0u,0u,0u,0u,0u) {
		CurrentLevel = 1u;
		CurrentEXP = 0u;
		EXPToNextLevel = LEVEL2AT;
		HP = std::make_unique<PointWell>();
		MP = std::make_unique<PointWell>();
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
	std::unique_ptr<PointWell>MP;
	std::unique_ptr<PointWell>Madness;
	std::unique_ptr<PointWell>Resource;

	ResourceType resourceType = ResourceType::None;
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
	static const welltype BASEMP = (welltype)30u;
	static const stattype BASESTR = (stattype)5u;
	static const stattype BASEINT = (stattype)12u;
	static const stattype BASEEND = (stattype)8u;
	static const stattype BASEDEX = (stattype)8u;
	static const stattype BASESPD = (stattype)5u;
	static const stattype BASEMAD = (stattype)0u;
	

	TideCaller() {
		HP->setMax(BASEHP);
		HP->increaseCurrent(BASEHP);

		Resource = std::make_unique<PointWell>();
		Resource->setMax(BASEMP);
		Resource->increaseCurrent(BASEMP);
		resourceType = ResourceType::Mana;

		increaseStats(BASESTR, BASEINT, BASEEND, BASEDEX, BASESPD);
	}
	std::string getClassName() override {
		return std::string("Tide Caller");
	}

protected:
	void LevelUp() override {
		HP->setMax(HP->getMax() + BASEHP / 2);
		HP->increaseCurrent(BASEHP + BASEHP / 2);
		Resource->setMax(Resource->getMax() + BASEMP / 2);
		Resource->increaseCurrent(Resource->getCurrent() / 2);
		increaseStats(BASESTR / 2, BASEINT, BASEEND / 2, BASEDEX / 2, BASESPD);
		
	}
};

// ReefStrider class definition
// Assassin class with high endurance and balanced strength and intelligence

class ReefStrider : public PlayerCharacterDelegate {
public:
	static const welltype BASEHP = (welltype)90u;
	static const welltype BASEENERGY = (welltype)40u;
	static const stattype BASESTR = (stattype)9u;
	static const stattype BASEINT = (stattype)8u;
	static const stattype BASEEND = (stattype)6u;
	static const stattype BASEDEX = (stattype)12u;
	static const stattype BASESPD = (stattype)12u;
	static const stattype BASEMAD = (stattype)0u;

	ReefStrider() {
		HP->setMax(BASEHP);
		HP->increaseCurrent(BASEHP);

		Resource = std::make_unique<PointWell>();
		Resource->setMax(BASEENERGY);
		Resource->increaseCurrent(BASEENERGY);
		resourceType = ResourceType::Energy;
		increaseStats(BASESTR, BASEINT, BASEEND, BASEDEX, BASESPD);
	}
	std::string getClassName() override {
		return std::string("Reef Strider");
	}

protected:
	void LevelUp() override {
		HP->setMax(HP->getMax() + BASEHP / 2);
		HP->increaseCurrent(BASEHP + BASEHP / 2);
		Resource->setMax(Resource->getMax() + BASEENERGY / 2);
		Resource->increaseCurrent(Resource->getCurrent() / 2);
		increaseStats(BASESTR / 2, BASEINT / 2, BASEEND, BASEDEX, BASESPD);
	}
};

// Tideborn class definition
// Tank class with high health and strength

class TideBorn : public PlayerCharacterDelegate {
public:
	static const welltype BASEHP = (welltype)120u;
	static const welltype BASEENERGY =(welltype)30u;
	static const stattype BASESTR = (stattype)20u;
	static const stattype BASEINT = (stattype)5u;
	static const stattype BASEEND = (stattype)12u;
	static const stattype BASEDEX = (stattype)8u;
	static const stattype BASESPD = (stattype)10u;
	static const stattype BASEMAD = (stattype)0u;

	TideBorn() {
		HP->setMax(BASEHP);
		HP->increaseCurrent(BASEHP);

		Resource = std::make_unique<PointWell>();
		Resource->setMax(BASEENERGY);
		Resource->increaseCurrent(BASEENERGY);
		resourceType = ResourceType::Energy;
		increaseStats(BASESTR, BASEINT, BASEEND, BASEDEX, BASESPD);
	}
	std::string getClassName() override {
		return std::string("TideBorn");
	}

protected:
	void LevelUp() override {
		HP->setMax(HP->getMax() + BASEHP / 2);
		HP->increaseCurrent(BASEHP + BASEHP / 2);
		Resource->setMax(Resource->getMax() + BASEENERGY / 2);
		Resource->increaseCurrent(Resource->getCurrent() / 2);
		increaseStats(BASESTR, BASEINT / 2, BASEEND, BASEDEX / 2,BASESPD / 2);
	}
};

// LeviathanHunter class definition
// Ranger class with high strength and endurance

class LeviathanHunter : public PlayerCharacterDelegate {
public:
	static const welltype BASEHP = (welltype)100u;
	static const welltype BASEENERGY = (welltype)30u;
	static const stattype BASESTR = (stattype)15u;
	static const stattype BASEINT = (stattype)8u;
	static const stattype BASEEND = (stattype)15u;
	static const stattype BASEDEX = (stattype)10u;
	static const stattype BASESPD = (stattype)9u;
	static const stattype BASEMAD = (stattype)0u;

	LeviathanHunter() {
		HP->setMax(BASEHP);
		HP->increaseCurrent(BASEHP);

		Resource = std::make_unique<PointWell>();
		Resource->setMax(BASEENERGY);
		Resource->increaseCurrent(BASEENERGY);
		resourceType = ResourceType::Energy;
		increaseStats(BASESTR, BASEINT, BASEEND, BASEDEX, BASESPD);
	}
	std::string getClassName() override {
		return std::string("Leviathan Hunter");
	}

protected:
	void LevelUp() override {
		HP->setMax(HP->getMax() + BASEHP / 2);
		HP->increaseCurrent(BASEHP + BASEHP / 2);
		Resource->setMax(Resource->getMax() + BASEENERGY / 2);
		Resource->increaseCurrent(Resource->getCurrent() / 2);
		increaseStats(BASESTR, BASEINT / 2, BASEEND / 2, BASEDEX,BASESPD);
	}
};

// AbyssalMage class definition
// Mage class with high intelligence and low health

class AbyssalMage : public PlayerCharacterDelegate {
public:
	static const welltype BASEHP = (welltype)70u;
	static const welltype BASEMP = (welltype)20u;
	static const stattype BASESTR = (stattype)6u;
	static const stattype BASEINT = (stattype)20u;
	static const stattype BASEEND = (stattype)6u;
	static const stattype BASEDEX = (stattype)8u;
	static const stattype BASESPD = (stattype)5u;
	static const stattype BASEMAD = (stattype)0u;
	

	AbyssalMage() {
		HP->setMax(BASEHP);
		HP->increaseCurrent(BASEHP);

		Resource = std::make_unique<PointWell>();
		Resource->setMax(BASEMP);
		Resource->increaseCurrent(BASEMP);
		resourceType = ResourceType::Mana;
		increaseStats(BASESTR, BASEINT, BASEEND, BASEDEX, BASESPD);

	}
	std::string getClassName() override {
		return std::string("Abyssal Mage");
	}

protected:
	void LevelUp() override {
		HP->setMax(HP->getMax() + BASEHP / 2);
		HP->increaseCurrent(BASEHP + BASEHP / 2);
		Resource->setMax(Resource->getMax() + BASEMP / 2);
		Resource->increaseCurrent(Resource->getCurrent() / 2);
		increaseStats(BASESTR / 2, BASEINT, BASEEND, BASEDEX, BASESPD);
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
	welltype getCurrentResource() const {
		return pcclass->Resource ? pcclass->Resource->getCurrent() : 0;
	}
	welltype getMaxResource() const {
		return pcclass->Resource ? pcclass->Resource->getMax() : 0;
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
	stattype getDexterity() {
		return pcclass->getDexterity();
	}
	stattype getSpeed() {
		return pcclass->getSpeed();
	}
	ResourceType getResourceType() const {
		return pcclass->resourceType;
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
	bool hasResource() const {
		return pcclass->Resource != nullptr;
	}
	bool isDefending() {
		return pcclass->isDefending;
	}
};
