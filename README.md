# Zoo Battle Arena

A turn-based console game written in **C++** that demonstrates core **object-oriented programming** concepts: abstract classes, inheritance, multiple inheritance, polymorphism and composition. Animals with different abilities form teams, get trained, and battle each other in an arena.

## Features

- **8 ready-made animals in 4 teams** (2 animals per team).
- **Display animals, abilities and teams** with health, attack power and total team health.
- **Create a new animal** (Lion, Monkey, Eagle or Shark) and swap it into any team.
- **Trainer:** Train a single animal or all animals at once (+10 attack power or +10 health, within the limits of 70 attack / 200 health).
- **Battle:** Pick two teams and watch them fight round by round.

## Battle Rules

- Animals at the same position in each team face each other; one round per pair (2 rounds per battle).
- Each round has up to 3 turns. In each turn both animals attack once. The round ends early if an animal's health reaches 0.
- The animal with more health at the end wins the round. If health is equal, the one that dealt more damage wins.
- The team that wins more rounds wins the battle; equal scores mean a draw.
- Health is restored after each round, so a battle does not change the animals permanently.

## OOP Design

| Concept | Where it is used |
|---|---|
| **Abstract class** | `Animal` has the pure virtual method `performAttack()` |
| **Interfaces** | `Running`, `Jumping`, `Flyable`, `Swimmable` (pure virtual classes) |
| **Multiple inheritance** | `Lion : Animal, Running`, `Monkey : Animal, Jumping`, `Eagle : Animal, Flyable`, `Shark : Animal, Swimmable` |
| **Polymorphism** | Each animal overrides `performAttack()` and `showAbility()`; they are called through `Animal*` pointers |
| **Encapsulation** | Protected/private data with getters and modifier methods |
| **Composition** | `Team` and `Trainer` hold `vector<Animal*>`; `BattleArena` works with two `Team` objects |

```
                Animal (abstract)
          ┌──────┬──────┴──────┬──────┐
         Lion  Monkey       Eagle   Shark
          │      │            │       │
       Running Jumping     Flyable Swimmable
```

## Project Structure

```
├── main.cpp          # Creates animals, teams and the trainer; main menu loop
├── Animal.h          # Abstract base class
├── Abilities.h       # Running, Jumping, Flyable, Swimmable interfaces
├── Lion.h
├── Monkey.h
├── Eagle.h
├── Shark.h
├── Team.h            # A team of animals
├── Trainer.h         # Trains animals
├── BattleArena.h     # Battle and round logic
├── GameMenu.h
└── GameMenu.cpp      # Menu screens and user interaction
```

## Build & Run

Requires a C++11 (or newer) compiler.

```bash
g++ -std=c++17 -o zoo *.cpp
./zoo
```

On Windows (MinGW):

```bash
g++ -std=c++17 -o zoo.exe *.cpp
zoo.exe
```

## Menu

```
1. Display Animals
2. Display Animal Ability
3. Display Teams
4. Create Animal and Add Animal to Team
5. Display Trainer and Train Animal
6. Train All Animals
7. Battle Rules
8. Start Battle
0. Exit
```

## Example

```
Battle: The Invincibles vs Big Wind

This Round Winner: Black Eagle
This Round Winner: Big Hunter

The Invincibles Team Score: 0
Big Wind Team Score: 2
Winner Team: Big Wind
```
