#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

// Abstract base class shared by every character in the game.
// Concrete player classes (Warrior, Mage, Archer) are added in Phase 3.
// A parallel Enemy hierarchy arrives in Phase 4.
class Character {
protected:
    std::string name;
    int health;
    int maxHealth;
    int attackPower;
    int defense;
    int level;
    int experience;
    int gold;

    // Experience required to reach the next level. Linear placeholder curve;
    // real tuning happens in Phase 18 (Game Balancing).
    int ExperienceToNextLevel() const;

public:
    Character(const std::string& charName, int startHealth, int startAttack,
              int startDefense, int startLevel = 1);
    virtual ~Character() = default;

    // --- Pure virtual: every concrete character defines its own combat identity ---
    virtual int Attack(Character& target) = 0;       // Returns damage dealt
    virtual void UseAbility(Character& target) = 0;  // Class-specific special move
    virtual std::string GetClassName() const = 0;

    // --- Shared behavior (Phase 2) ---
    void TakeDamage(int amount);
    void Heal(int amount);
    virtual void DisplayStats() const;  // virtual: subclasses append class-specific stats
    virtual void LevelUp();             // virtual: subclasses can extend (e.g., Mage grows mana)
    void GainExperience(int amount);
    bool IsAlive() const;

    // --- Accessors ---
    const std::string& GetName() const { return name; }
    int GetHealth() const { return health; }
    int GetMaxHealth() const { return maxHealth; }
    int GetAttackPower() const { return attackPower; }
    int GetDefense() const { return defense; }
    int GetLevel() const { return level; }
    int GetExperience() const { return experience; }
    int GetGold() const { return gold; }

    void AddGold(int amount);
};

#endif // CHARACTER_H
