#ifndef MAGE_H
#define MAGE_H

#include <string>
#include "Character.h"

class Mage : public Character {
private:
    int mana;
    int maxMana;

public:
    explicit Mage(const std::string& charName);

    int Attack(Character& target) override;
    void UseAbility(Character& target) override;
    std::string GetClassName() const override;
    void DisplayStats() const override;
    void LevelUp() override;

    int GetMana() const { return mana; }
    int GetMaxMana() const { return maxMana; }
};

#endif
