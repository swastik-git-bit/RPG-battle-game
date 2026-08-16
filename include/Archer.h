#ifndef ARCHER_H
#define ARCHER_H

#include <string>
#include "Character.h"

class Archer : public Character {
private:
    int critChance;

public:
    explicit Archer(const std::string& charName);

    int Attack(Character& target) override;
    void UseAbility(Character& target) override;
    std::string GetClassName() const override;
    void DisplayStats() const override;
};

#endif
