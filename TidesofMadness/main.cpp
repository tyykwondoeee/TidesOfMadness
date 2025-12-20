#include <iostream>
#include "playercharacter.h"

const char* resourceName(ResourceType type) {
    switch (type) {
    case ResourceType::Mana:   return "MP";
    case ResourceType::Energy: return "Energy";
    case ResourceType::Rage:   return "Rage";
    default:                  return nullptr;
    }
}

int main() {
    PlayerCharacter p1(new LeviathanHunter());

    for (int i = 0; i < 2; i++) {

        std::cout
            << p1.getClassName()
            << " Level " << p1.getLevel() << '\n'
            << "EXP: " << p1.getCurrentEXP() << '/' << p1.getEXPToNextLevel() << '\n'
            << "Madness: " << p1.getMadness() << '/' << p1.getMaxMadness() << '\n'
            << "HP: " << p1.getCurrentHP() << '/' << p1.getMaxHP() << '\n';

        if (p1.hasResource()) {
            const char* name = resourceName(p1.getResourceType());
            if (name) {
                std::cout
                    << name << ": "
                    << p1.getCurrentResource()
                    << '/'
                    << p1.getMaxResource()
                    << '\n';
            }
        }

        std::cout
            << "Strength: " << p1.getStrength() << '\n'
            << "Intelligence: " << p1.getIntellect() << '\n'
            << "Endurance: " << p1.getEndurance() << '\n'
            << "Dexterity: " << p1.getDexterity() << '\n'
            << "Speed: " << p1.getSpeed() << '\n';

        if (i < 1)
            p1.gainEXP(100u);

        std::cout << '\n';
    }

    std::cin.get();
    return 0;
}
