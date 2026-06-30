#ifndef TRAINING_DUMMY_H
#define TRAINING_DUMMY_H

#include "Character.h"

// TEMPORARY TEST SCAFFOLD -- Phases 1-3 only.
// ---------------------------------------------
// Not part of the final game design. It exists purely so Attack()/UseAbility()/
// TakeDamage() can be exercised end-to-end before the real Enemy hierarchy exists.
// Deleted once Phase 4 (Enemy System) introduces real enemies to fight instead.
class TrainingDummy : public Character {
public:
    TrainingDummy();

    int Attack(Character& target) override;       // Dummies don't fight back
    void UseAbility(Character& target) override;  // Dummies have no abilities
    std::string GetClassName() const override;
};

#endif // TRAINING_DUMMY_H
