#ifndef GAME_H
#define GAME_H

#include <memory>
#include "Character.h"

// Owns the overall game flow. Phase 1: menu + a Training Grounds test area.
// Will grow into full exploration/battle flow in later phases.
class Game {
private:
    std::unique_ptr<Character> player;
    bool running;

    void ShowWelcomeBanner() const;
    std::unique_ptr<Character> CreateCharacterFromChoice();
    void MainMenu();
    void TestArea();  // exercises Attack/UseAbility/Heal/GainExperience against a
                       // TrainingDummy; replaced by the real Battle System (Phase 5).

public:
    Game();
    void Run();
};

#endif // GAME_H
