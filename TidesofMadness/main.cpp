#include <iostream>
#include "Tideborn.h"
#include "TideCaller.h"
#include "AbyssalMage.h"
#include "ReefStrider.h"
#include "LeviathanHunter.h"


int main() {

	Tideborn Tideb1;
	TideCaller TideC1;
	AbyssalMage Abyssal1;
	ReefStrider ReefS1;
	LeviathanHunter LevH1;

	std::cout << "Tideborn\n"
		<< "-MaxHp: " << Tideb1.getMaxHP() << '\n'
		<< "-Str: " << (int)Tideb1.getStrength() << '\n'
		<< "-Int: " << (int)Tideb1.getIntelligence() << '\n'
		<< "-End: " << (int)Tideb1.getEndurance() << "\n\n";

	std::cout << "TideCaller\n"
		<< "-MaxHp: " << TideC1.getMaxHP() << '\n'
		<< "-Str: " << (int)TideC1.getStrength() << '\n'
		<< "-Int: " << (int)TideC1.getIntelligence() << '\n'
		<< "-End: " << (int)TideC1.getEndurance() << "\n\n";

	std::cout << "AbyssalMage\n"
		<< "-MaxHp: " << Abyssal1.getMaxHP() << '\n'
		<< "-Str: " << (int)Abyssal1.getStrength() << '\n'
		<< "-Int: " << (int)Abyssal1.getIntelligence() << '\n'
		<< "-End: " << (int)Abyssal1.getEndurance() << "\n\n";

	std::cout << "ReefStrider\n"
		<< "-MaxHp: " << ReefS1.getMaxHP() << '\n'
		<< "-Str: " << (int)ReefS1.getStrength() << '\n'
		<< "-Int: " << (int)ReefS1.getIntelligence() << '\n'
		<< "-End: " << (int)ReefS1.getEndurance() << "\n\n";

	std::cout << "LeviathanHunter\n"
		<< "-MaxHp: " << LevH1.getMaxHP() << '\n'
		<< "-Str: " << (int)LevH1.getStrength() << '\n'
		<< "-Int: " << (int)LevH1.getIntelligence() << '\n'
		<< "-End: " << (int)LevH1.getEndurance() << "\n\n";


	return 0;

}