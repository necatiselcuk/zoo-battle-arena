#ifndef LION_H
#define LION_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Animal.h"
#include "Abilities.h"

class Lion : public Animal, public Running{
public:
Lion(string n, int h, int a): Animal(n,h,a){}

void run() override{

    cout<<"The Lion "<<name<<"'s Ability: Running"<<endl;

}

void showAbility() override{
    run();

}

void performAttack(Animal* enemy) override{

    cout<<"Lion "<<name<<" attacks the enemy "<<enemy->getName()<<" with its claw!"<<endl<<endl;
    enemy->givenDamage(attackPower);

}

};

#endif
