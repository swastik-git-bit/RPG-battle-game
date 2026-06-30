#include "TrainingDummy.h"
#include <iostream>

TrainingDummy::TrainingDummy()
    : Character("Training Dummy", /*startHealth=*/70, /*startAttack=*/0, /*startDefense=*/5) {}

int TrainingDummy::Attack(Character&) {
    std::cout << "The Training Dummy just stares back at you.\n";
    return 0;
}

void TrainingDummy::UseAbility(Character&) {
    // Dummies have no abilities.
}

std::string TrainingDummy::GetClassName() const {
    return "Training Dummy";
}
