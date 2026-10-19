#ifndef MONKEY_H
#define MONKEY_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Animal.h"
#include "Abilities.h"

class Monkey : public Animal, public Jumping{
public:
Monkey(string n, int h, int a): Animal(n,h,a){}

void jump() override{

    cout<<"The Monkey "<<name<<"'s Ability: Jumping"<<endl;

}

void showAbility() override{
    jump();
}

void performAttack(Animal* enemy) override{

    cout<<"Monkey "<<name<<" attacks the enemy "<<enemy->getName()<<" with its punch!"<<endl<<endl;
    enemy->givenDamage(attackPower);
    
}

};

#endif
