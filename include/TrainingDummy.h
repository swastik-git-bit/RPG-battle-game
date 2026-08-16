#ifndef TRAINING_DUMMY_H
#define TRAINING_DUMMY_H

#include "Character.h"

class TrainingDummy : public Character {
public:
    TrainingDummy();

    int Attack(Character& target) override;
    void UseAbility(Character& target) override;
    std::string GetClassName() const override;
};

#endif
