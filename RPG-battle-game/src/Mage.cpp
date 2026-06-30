#include "Mage.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>

Mage::Mage(const std::string& charName)
    : Character(charName, /*startHealth=*/80, /*startAttack=*/24, /*startDefense=*/6),
      mana(60), maxMana(60) {}

int Mage::Attack(Character& target) {
    const int manaCost = 5;

    if (mana < manaCost) {
        std::cout << GetName() << " is out of mana and fumbles a weak strike!\n";
        int fallback = std::max(1, GetAttackPower() / 3 - target.GetDefense() / 2);
        target.TakeDamage(fallback);
        return fallback;
    }

    mana -= manaCost;
    int variance = (rand() % 7) - 3;
    int rawDamage = GetAttackPower() + variance;
    int finalDamage = std::max(1, rawDamage - target.GetDefense() / 4);  // armor barely helps vs magic

    std::cout << GetName() << " hurls a Magic Bolt at " << target.GetName()
              << " for " << finalDamage << " damage! (-" << manaCost << " mana)\n";
    target.TakeDamage(finalDamage);

    mana = std::min(maxMana, mana + 3);  // small regen to keep the resource usable
    return finalDamage;
}

void Mage::UseAbility(Character& target) {
    const int manaCost = 25;

    if (mana < manaCost) {
        std::cout << GetName() << " doesn't have enough mana for Fireball! ("
                  << mana << "/" << manaCost << ")\n";
        return;
    }

    mana -= manaCost;
    int damage = static_cast<int>(GetAttackPower() * 2.0) - target.GetDefense() / 5;
    damage = std::max(1, damage);

    std::cout << GetName() << " casts FIREBALL at " << target.GetName()
              << " for " << damage << " damage! (-" << manaCost << " mana)\n";
    target.TakeDamage(damage);
}

std::string Mage::GetClassName() const {
    return "Mage";
}

void Mage::DisplayStats() const {
    Character::DisplayStats();
    std::cout << "Mana:    " << mana << "/" << maxMana
              << "\n----------------------------\n";
}

void Mage::LevelUp() {
    Character::LevelUp();
    int oldMaxMana = maxMana;
    maxMana += 10;
    mana = maxMana;
    std::cout << "  Max Mana: " << oldMaxMana << " -> " << maxMana << "\n";
}
