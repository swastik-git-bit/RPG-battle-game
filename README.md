# Terminal RPG Battle Game (C++)

A text-based RPG built incrementally in C++ using Object-Oriented Programming,
following a 20-phase roadmap: character system → combat → equipment → inventory →
skills → loot → shops → quests → exploration → save/load → bosses → polish.

## Current Status: Phases 1-3 Complete ✅

- **Phase 1 — Core Structure**: project layout (`include/` + `src/`), a `Game` class
  that owns all flow, a clean `main()` that only initializes and starts the game, and
  a basic menu-driven game loop.
- **Phase 2 — Character System**: abstract `Character` base class with the shared
  attributes (Name, Health, Max Health, Attack Power, Defense, Level, Experience, Gold)
  and shared methods (`Attack`, `TakeDamage`, `Heal`, `DisplayStats`, `LevelUp`,
  `GainExperience`, `IsAlive`).
- **Phase 3 — Player Classes**: `Warrior`, `Mage`, and `Archer`, each with different
  base stats, an overridden `Attack()`, and a unique ability (Power Strike / Fireball /
  Rapid Shot) showing distinct playstyles.

Everything below is **not built yet** and arrives in later phases per the project
roadmap: Enemy System, Battle System, Weapons, Armor/Equipment, Inventory, Skills,
deeper Leveling, Loot, multi-enemy fights, Shops, Quests, World/Exploration, Save/Load,
Boss battles, Balancing, Polish, and the Final Refactor.

## Building

```
make
./rpg_game
```

Requires a C++17 compiler (developed and tested with g++ 13). Run `make clean` to
remove build artifacts.

## Trying it out

1. Run the game, pick a class, and name your character.
2. From the **Main Menu**, open the **Training Grounds** to test `Attack`, `UseAbility`,
   `Heal`, and `GainExperience` (including level-ups) against a stand-in target.
3. Use **View Stats** any time to see the full character sheet.

## Architecture notes

- `Character` is abstract — `Attack`, `UseAbility`, and `GetClassName` are pure virtual,
  so every playable class must define its own combat identity. This is what satisfies
  the "override attack behavior per class" requirement from Phase 3.
- Class-specific resources (Mage's `mana`, Archer's `critChance`) live in the derived
  class, not in `Character`, since they aren't shared by every character type. `Mage`
  also overrides the virtual `LevelUp()` to grow `maxMana`, demonstrating how a subclass
  can extend rather than just replace base behavior.
- `TrainingDummy` is **temporary scaffolding** (clearly marked in its header/source) so
  combat methods can be exercised before the real `Enemy` hierarchy exists. It will be
  deleted once Phase 4 is built.
- Warrior's ability cooldown is a simple int counter that only ticks down on a basic
  `Attack()` (not on every action) — a deliberate simplification. Phase 9 (Skill System)
  will replace this with a proper `Skill` class (name, damage, mana cost, cooldown)
  shared by all classes, with a real per-turn tick, so this will be refactored rather
  than duplicated further.
- `std::unique_ptr` is used for character ownership from the start, rather than
  retrofitting smart pointers later, per the project's final-phase requirement to avoid
  raw owning pointers.

## Roadmap (next up)

**Phase 4 — Enemy System** is next: an `Enemy` base class plus Goblin/Skeleton/Orc/
Dragon/Boss types with level-based scaling, followed immediately by **Phase 5 — Battle
System** so the Training Grounds can be replaced with real turn-based encounters.

## Known simplifications (intentionally deferred, not bugs)

- Damage RNG uses `rand()`/`srand()` for simplicity; may move to `<random>` during
  Phase 18 (Game Balancing) for better statistical distribution.
- Leveling curve (`level * 100` EXP, flat +20 HP / +5 ATK / +3 DEF per level) is a
  placeholder and will be tuned in Phase 18.
- There's no real "turn" concept yet (that's Phase 5), so resource ticks like the
  Warrior's cooldown and the Mage's mana regen are approximated via the Training
  Grounds' "Attack" action rather than a true turn counter.
