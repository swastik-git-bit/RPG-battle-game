#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

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

    int ExperienceToNextLevel() const;

public:
    Character(const std::string& charName, int startHealth, int startAttack,
              int startDefense, int startLevel = 1);
    virtual ~Character() = default;

    virtual int Attack(Character& target) = 0; 
    virtual void UseAbility(Character& target) = 0;  
    virtual std::string GetClassName() const = 0;

    void TakeDamage(int amount);
    void Heal(int amount);
    virtual void DisplayStats() const;
    virtual void LevelUp(); 
    void GainExperience(int amount);
    bool IsAlive() const;

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
