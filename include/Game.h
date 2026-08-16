#ifndef GAME_H
#define GAME_H

#include <memory>
#include "Character.h"

class Game {
private:
    std::unique_ptr<Character> player;
    bool running;

    void ShowWelcomeBanner() const;
    std::unique_ptr<Character> CreateCharacterFromChoice();
    void MainMenu();
    void TestArea();

public:
    Game();
    void Run();
};

#endif
