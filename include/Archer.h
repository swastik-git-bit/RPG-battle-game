#ifndef ARCHER_H
#define ARCHER_H

#include <string>
#include "Character.h"

// Balanced ranged fighter: moderate stats with a strong critical-hit chance.
class Archer : public Character {
private:
    int critChance;  // percent chance (0-100) for a critical hit

public:
    explicit Archer(const std::string& charName);

    int Attack(Character& target) override;
    void UseAbility(Character& target) override;
    std::string GetClassName() const override;
    void DisplayStats() const override;
};

#endif // ARCHER_H
