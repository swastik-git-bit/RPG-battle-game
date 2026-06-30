#include "Game.h"
#include "Warrior.h"
#include "Mage.h"
#include "Archer.h"
#include "TrainingDummy.h"
#include <iostream>
#include <limits>
#include <ctime>
#include <cstdlib>

namespace {

int ReadMenuChoice(int minValue, int maxValue) {
    int choice;
    while (true) {
        std::cin >> choice;

        if (std::cin.eof()) {
            std::cout << "\nInput closed -- exiting.\n";
            std::exit(0);
        }

        if (std::cin.fail() || choice < minValue || choice > maxValue) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please enter a number between " << minValue << " and " << maxValue << ": ";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return choice;
        }
    }
}

}  // namespace

Game::Game() : player(nullptr), running(true) {
    srand(static_cast<unsigned int>(time(nullptr)));
}

void Game::ShowWelcomeBanner() const {
    std::cout << "=================================================\n";
    std::cout << "        TERMINAL RPG -- BATTLE GAME (C++)        \n";
    std::cout << "=================================================\n";
    std::cout << "Build status: Phases 1-3 (core structure + characters)\n\n";
}

std::unique_ptr<Character> Game::CreateCharacterFromChoice() {
    std::cout << "Choose your class:\n";
    std::cout << "  1. Warrior  (high HP & defense, strong melee)\n";
    std::cout << "  2. Mage     (fragile, devastating spells, uses mana)\n";
    std::cout << "  3. Archer   (balanced, high crit chance)\n";
    std::cout << "Choice: ";
    int classChoice = ReadMenuChoice(1, 3);

    std::cout << "Enter your character's name: ";
    std::string charName;
    std::getline(std::cin, charName);
    if (charName.empty()) charName = "Hero";

    switch (classChoice) {
        case 1:  return std::make_unique<Warrior>(charName);
        case 2:  return std::make_unique<Mage>(charName);
        default: return std::make_unique<Archer>(charName);
    }
}

void Game::TestArea() {
    auto dummy = std::make_unique<TrainingDummy>();

    bool inTestArea = true;
    while (inTestArea && player->IsAlive()) {
        std::cout << "\n--- Training Grounds (vs " << dummy->GetName() << ", "
                  << dummy->GetHealth() << "/" << dummy->GetMaxHealth() << " HP) ---\n";
        std::cout << "1. Attack\n";
        std::cout << "2. Use Ability\n";
        std::cout << "3. Heal Self (20 HP)\n";
        std::cout << "4. View My Stats\n";
        std::cout << "5. Award 60 EXP (debug -- simulates winning a battle)\n";
        std::cout << "6. Leave Training Grounds\n";
        std::cout << "Choice: ";
        int choice = ReadMenuChoice(1, 6);

        switch (choice) {
            case 1: player->Attack(*dummy); break;
            case 2: player->UseAbility(*dummy); break;
            case 3:
                player->Heal(20);
                std::cout << player->GetName() << " heals for 20 HP.\n";
                break;
            case 4: player->DisplayStats(); break;
            case 5: player->GainExperience(60); break;
            case 6: inTestArea = false; break;
        }

        if (choice != 6 && !dummy->IsAlive()) {
            std::cout << "\nThe Training Dummy is destroyed! A fresh one is set up.\n";
            dummy = std::make_unique<TrainingDummy>();
        }
    }

    if (!player->IsAlive()) {
        std::cout << "\n" << player->GetName() << " has fallen! "
                  << "(No real consequence yet -- defeat handling arrives in Phase 5.)\n";
    }
}

void Game::MainMenu() {
    while (running) {
        std::cout << "\n===== MAIN MENU =====\n";
        std::cout << "1. View Stats\n";
        std::cout << "2. Enter Training Grounds (test Attack/Ability/Heal/EXP)\n";
        std::cout << "3. Quit\n";
        std::cout << "Choice: ";
        int choice = ReadMenuChoice(1, 3);

        switch (choice) {
            case 1: player->DisplayStats(); break;
            case 2: TestArea(); break;
            case 3:
                running = false;
                std::cout << "Thanks for playing! Goodbye, " << player->GetName() << ".\n";
                break;
        }
    }
}

void Game::Run() {
    ShowWelcomeBanner();
    player = CreateCharacterFromChoice();
    std::cout << "\nWelcome, " << player->GetName() << " the " << player->GetClassName() << "!\n";
    player->DisplayStats();
    MainMenu();
}
