#include "Archer.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>

Archer::Archer(const std::string& charName)
    : Character(charName, /*startHealth=*/95, /*startAttack=*/20, /*startDefense=*/8),
      critChance(20) {}

int Archer::Attack(Character& target) {
    bool isCrit = (rand() % 100) < critChance;
    int variance = (rand() % 5) - 2;
    int rawDamage = GetAttackPower() + variance;
    if (isCrit) rawDamage = static_cast<int>(rawDamage * 1.5);

    int finalDamage = std::max(1, rawDamage - target.GetDefense() / 2);

    std::cout << GetName() << " fires an arrow at " << target.GetName();
    if (isCrit) std::cout << " -- CRITICAL HIT!";
    std::cout << " for " << finalDamage << " damage!\n";

    target.TakeDamage(finalDamage);
    return finalDamage;
}

void Archer::UseAbility(Character& target) {
    std::cout << GetName() << " fires a RAPID SHOT -- two arrows in quick succession!\n";
    int total = 0;
    for (int i = 1; i <= 2; i++) {
        if (!target.IsAlive()) break;
        int variance = (rand() % 4) - 1;
        int rawDamage = static_cast<int>(GetAttackPower() * 0.65) + variance;
        int finalDamage = std::max(1, rawDamage - target.GetDefense() / 2);
        std::cout << "  Arrow " << i << " hits for " << finalDamage << " damage!\n";
        target.TakeDamage(finalDamage);
        total += finalDamage;
    }
    std::cout << GetName() << "'s Rapid Shot dealt " << total << " total damage!\n";
}

std::string Archer::GetClassName() const {
    return "Archer";
}

void Archer::DisplayStats() const {
    Character::DisplayStats();
    std::cout << "Crit Chance: " << critChance << "%"
              << "\n----------------------------\n";
}
