#ifndef TRAINER_H
#define TRAINER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Animal.h"

class Trainer{
private:
string name;
int age;
vector <Animal*> TrainAnimals;

public:
Trainer(string n, int a): name(n), age(a){}

void addAnimalTrain(Animal* a){

    TrainAnimals.push_back(a);

}

void deleteAnimalTrain(){

TrainAnimals.pop_back();

}

void increaseAttackPower(int x){

TrainAnimals[x]->upgradeAttackPower(10);

}

void increaseHealth(int y){

TrainAnimals[y]->upgradeHealth(10);

}

string getName(){
    return name;
}

int getAge(){
    return age;
}

void cleanAnimals(){

TrainAnimals.clear();

}

};

#endif
