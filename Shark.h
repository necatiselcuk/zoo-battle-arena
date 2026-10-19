#ifndef SHARK_H
#define SHARK_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Animal.h"
#include "Abilities.h"

class Shark : public Animal, public Swimmable{
public:
Shark(string n, int h, int a): Animal(n,h,a){}

void swim() override{

    cout<<"The Shark"<<name<<"'s Ability: Swimming"<<endl;

}

void showAbility() override{
    swim();
}

void performAttack(Animal* enemy) override{

    cout<<"Shark "<<name<<" attacks the enemy "<<enemy->getName()<<" with its sharp teeth!"<<endl<<endl;
    enemy->givenDamage(attackPower);

}

};

#endif
