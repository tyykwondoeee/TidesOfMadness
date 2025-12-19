#include <iostream>
#include "playercharacter.h"


int main() {
	PlayerCharacter p1(new AbyssalMage());

	for (int i = 0; i < 2; i++) {
		std::cout
			<< p1.getClassName()
			<< " Level" << p1.getLevel() << '\n'
			<< "EXP: " << p1.getCurrentEXP() << '/' << p1.getEXPToNextLevel() << '\n'
			<< "Madness: " << p1.getMadness() << '/' << p1.getMaxMadness() << '\n'
			<< "HP: " << p1.getCurrentHP() << '/' <<p1.getMaxHP() << '\n'
			<< "Strength: " << p1.getStrength() << '\n'
			<< "Intelligence: " << p1.getIntellect() << '\n'
			<< "Endurance: " << p1.getEndurance() << '\n';
		if (i < 1)
			p1.gainEXP(100u);
		std::cout << '\n';
	}
	std::cin.get();


	return 0;
}

