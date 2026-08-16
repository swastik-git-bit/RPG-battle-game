#ifndef WARRIOR_H
#define WARRIOR_H

#include <string>
#include "Character.h"
class Warrior : public Character {
private:
    int abilityCooldown;

public:
    explicit Warrior(const std::string& charName);

    int Attack(Character& target) override;
    void UseAbility(Character& target) override;
    std::string GetClassName() const override;
    void DisplayStats() const override;
};

#endif
