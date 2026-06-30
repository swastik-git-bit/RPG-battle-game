#include "Character.h"
#include <iostream>

Character::Character(const std::string& charName, int startHealth, int startAttack,
                      int startDefense, int startLevel)
    : name(charName), health(startHealth), maxHealth(startHealth),
      attackPower(startAttack), defense(startDefense), level(startLevel),
      experience(0), gold(0) {}

int Character::ExperienceToNextLevel() const {
    return level * 100;
}

void Character::TakeDamage(int amount) {
    if (amount < 0) amount = 0;
    health -= amount;
    if (health < 0) health = 0;
}

void Character::Heal(int amount) {
    if (amount < 0) amount = 0;
    health += amount;
    if (health > maxHealth) health = maxHealth;
}

void Character::DisplayStats() const {
    std::cout << "\n----- " << name << " (" << GetClassName() << ") -----\n";
    std::cout << "Level:   " << level << "\n";
    std::cout << "HP:      " << health << "/" << maxHealth << "\n";
    std::cout << "Attack:  " << attackPower << "\n";
    std::cout << "Defense: " << defense << "\n";
    std::cout << "EXP:     " << experience << "/" << ExperienceToNextLevel() << "\n";
    std::cout << "Gold:    " << gold << "\n";
}

void Character::LevelUp() {
    level++;
    int oldMaxHealth = maxHealth;
    int oldAttack = attackPower;
    int oldDefense = defense;

    maxHealth += 20;
    attackPower += 5;
    defense += 3;
    health = maxHealth;  // full heal as a level-up reward

    std::cout << "\n*** " << name << " reached Level " << level << "! ***\n";
    std::cout << "  Max HP:  " << oldMaxHealth << " -> " << maxHealth << "\n";
    std::cout << "  Attack:  " << oldAttack << " -> " << attackPower << "\n";
    std::cout << "  Defense: " << oldDefense << " -> " << defense << "\n";
}

void Character::GainExperience(int amount) {
    if (amount <= 0) return;
    experience += amount;
    std::cout << name << " gains " << amount << " experience points!\n";
    while (experience >= ExperienceToNextLevel()) {
        experience -= ExperienceToNextLevel();
        LevelUp();
    }
}

bool Character::IsAlive() const {
    return health > 0;
}

void Character::AddGold(int amount) {
    if (amount > 0) gold += amount;
}
