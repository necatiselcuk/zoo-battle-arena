#ifndef GAMEMENU_H
#define GAMEMENU_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Animal.h"
#include "Team.h"
#include "Trainer.h"

void menu();
void displayAnimals(vector <Animal*>& list);
void displayAnimalAbility(vector <Animal*>& list);
void displayTeams(vector <Team>& list);
void createAnimals(vector <Animal*>& listofanimal,vector <Team>& teams);
void trainAnimal(Trainer& trainer,vector <Animal*>& listofanimal);
void trainAllAnimals(Trainer& trainer1,vector <Animal*>& listofanimal);
void startBattle(vector <Team>& teamList1);
void battleRules();

#endif
