#include "Warrior.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>

Warrior::Warrior(const std::string& charName)
    : Character(charName, /*startHealth=*/120, /*startAttack=*/18, /*startDefense=*/12),
      abilityCooldown(0) {}

int Warrior::Attack(Character& target) {
    int variance = (rand() % 5) - 2;  // -2..+2
    int rawDamage = GetAttackPower() + variance;
    int finalDamage = std::max(1, rawDamage - target.GetDefense() / 2);

    std::cout << GetName() << " swings their blade at " << target.GetName()
              << " for " << finalDamage << " damage!\n";
    target.TakeDamage(finalDamage);

    if (abilityCooldown > 0) abilityCooldown--;
    return finalDamage;
}

void Warrior::UseAbility(Character& target) {
    if (abilityCooldown > 0) {
        std::cout << GetName() << "'s Power Strike is on cooldown for "
                  << abilityCooldown << " more turn(s)!\n";
        return;
    }

    int damage = static_cast<int>(GetAttackPower() * 1.8) - target.GetDefense() / 3;
    damage = std::max(1, damage);

    std::cout << GetName() << " unleashes a POWER STRIKE on " << target.GetName()
              << " for " << damage << " damage!\n";
    target.TakeDamage(damage);
    abilityCooldown = 3;
}

std::string Warrior::GetClassName() const {
    return "Warrior";
}

void Warrior::DisplayStats() const {
    Character::DisplayStats();
    std::cout << "Power Strike: "
              << (abilityCooldown == 0 ? std::string("Ready!")
                                        : std::to_string(abilityCooldown) + " turn(s) left")
              << "\n----------------------------\n";
}
