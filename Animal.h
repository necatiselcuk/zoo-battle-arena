#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Animal{
protected:
string name;
int health;
int attackPower;

public:
Animal(string n, int h, int a): name(n), health(h), attackPower(a){}
virtual ~Animal() {}
virtual void performAttack(Animal* enemy)=0;

void displayStatus(){

    cout<<"Name: "<<name<<endl;
    cout<<"Health: "<<health<<endl;
    cout<<"Attack Power: "<<attackPower<<endl<<endl;

}

virtual void showAbility(){}

int getHealth(){

    return health;

}

int getAttackPower(){

    return attackPower;

}

string getName(){

    return name;

}

void upgradeAttackPower(int p){

    attackPower+=p;

}

void upgradeHealth(int h){

    health+=h;

}

void setHealth(int h){

    health=h;

}

void givenDamage(int damage){

    health-=damage;
    if(health<0){
    health=0;
    }
}

};

#endif
