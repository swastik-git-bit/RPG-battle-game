#include "TrainingDummy.h"
#include <iostream>

TrainingDummy::TrainingDummy()
    : Character("Training Dummy", 70, 0, 5) {}

int TrainingDummy::Attack(Character&) {
    std::cout << "The Training Dummy just stares back at you.\n";
    return 0;
}

void TrainingDummy::UseAbility(Character&) {
    // No abilities.
}

std::string TrainingDummy::GetClassName() const {
    return "Training Dummy";
}
