#ifndef WARRIOR_H
#define WARRIOR_H

#include <string>
#include "Character.h"

// Melee bruiser: high HP and defense, hits hard with Power Strike.
class Warrior : public Character {
private:
    int abilityCooldown;  // turns remaining until Power Strike is available again.
                           // NOTE: placeholder mechanism. Phase 9 (Skill System) will
                           // introduce a proper Skill class (name/damage/mana/cooldown)
                           // shared by all classes, and this will be refactored to use it.

public:
    explicit Warrior(const std::string& charName);

    int Attack(Character& target) override;
    void UseAbility(Character& target) override;
    std::string GetClassName() const override;
    void DisplayStats() const override;
};

#endif // WARRIOR_H
