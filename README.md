# RPG Battle Game (C++ OOP Project)

A console-based RPG Battle Game developed in C++ that demonstrates core Object-Oriented Programming principles including inheritance, polymorphism, abstraction, encapsulation, and smart pointer-based memory management.

The project allows players to choose from multiple character classes, battle training dummies, gain experience, level up, and use unique class-specific abilities. It was designed as an educational project to showcase clean OOP architecture and extensible game design patterns.

---

## Features

### Playable Character Classes

#### Warrior

* High health and defense
* Strong melee attacks
* Special Ability: **Power Strike**
* Cooldown-based ability system

#### Mage

* High damage output
* Mana-based combat mechanics
* Special Ability: **Fireball**
* Mana regeneration after attacks

#### Archer

* Balanced offensive stats
* Critical hit mechanics
* Special Ability: **Rapid Shot**
* Multi-hit attack capability

---

### Combat System

* Turn-based player actions
* Standard attacks
* Class-specific special abilities
* Healing functionality
* Randomized damage variation
* Critical hit system for Archer

---

### Progression System

* Experience (EXP) gain
* Character leveling
* Stat scaling with levels
* Gold tracking
* Automatic stat upgrades upon level-up

---

### Training Grounds

Players can enter the Training Grounds to:

* Attack enemies
* Use class abilities
* Heal themselves
* View character statistics
* Gain experience
* Test combat mechanics

Destroyed training dummies automatically respawn, allowing continuous gameplay and testing.

---

## Object-Oriented Design

The project demonstrates the following OOP concepts:

### Inheritance

Character
├── Warrior
├── Mage
└── Archer

All character classes inherit from a common base class while implementing their own combat behavior.

### Abstraction

The base `Character` class defines common interfaces and behavior while derived classes provide specialized implementations.

### Polymorphism

Runtime polymorphism is achieved using virtual functions, allowing different character types to be handled through a common interface.

### Encapsulation

Character attributes and game logic are organized within dedicated classes to maintain clean separation of responsibilities.

### Memory Management

The project utilizes modern C++ smart pointers (`std::unique_ptr`) to ensure safe and efficient memory management.

---

## Project Structure

```text
RPG-battle-game/
│
├── include/
│   ├── Character.h
│   ├── Warrior.h
│   ├── Mage.h
│   ├── Archer.h
│   ├── TrainingDummy.h
│   └── Game.h
│
├── src/
│   ├── Character.cpp
│   ├── Warrior.cpp
│   ├── Mage.cpp
│   ├── Archer.cpp
│   ├── TrainingDummy.cpp
│   └── Game.cpp
│
├── main.cpp
├── Makefile
└── README.md
```

---

## Build Instructions

### Linux

```bash
make
./rpg_game
```

### Windows (MinGW)

```bash
mingw32-make
rpg_game.exe
```

---

## Sample Gameplay

```text
=== RPG Battle Game ===

Choose your class:
1. Warrior
2. Mage
3. Archer

Enter character name: Hero

Training Grounds

1. Attack
2. Use Ability
3. Heal Self
4. View Stats
5. Award EXP
6. Leave
```

---

## Future Improvements

Planned enhancements include:

* Enemy hierarchy (Goblin, Orc, Skeleton, Dragon)
* Real turn-based combat encounters
* Inventory system
* Equipment and weapon system
* Loot drops
* Shop system
* Quest system
* Save/Load functionality
* Boss battles
* Status effects (Burn, Poison, Freeze, etc.)
* World exploration and map system

---

## Technologies Used

* C++17
* Object-Oriented Programming
* STL Containers
* Smart Pointers (`std::unique_ptr`)
* Makefile Build System

---

## Learning Outcomes

This project was developed to strengthen understanding of:

* Class design
* Inheritance and polymorphism
* Virtual functions
* Dynamic dispatch
* Encapsulation
* Memory management in modern C++
* Modular software architecture

