#ifndef EAGLE_H
#define EAGLE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Animal.h"
#include "Abilities.h"

class Eagle : public Animal, public Flyable{
public:
Eagle(string n, int h, int a): Animal(n,h,a){}

void fly() override{

    cout<<"The Eagle "<<name<<"'s Ability: Flying"<<endl;

}

void showAbility() override{
    fly();
}

void performAttack(Animal* enemy) override{

    cout<<"Eagle "<<name<<" attacks the enemy "<<enemy->getName()<<" with its claw!"<<endl<<endl;
    enemy->givenDamage(attackPower);

}



};

#endif
