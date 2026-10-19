#ifndef TEAM_H
#define TEAM_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Animal.h"

class Team{
private:
string teamName;

public:
vector <Animal*> animals;
Team(string t): teamName(t){}

void addAnimal(Animal* a){

    animals.push_back(a);

}

int calculateTotalHealth(){

    int totalHealth=0;
    for(int i=0;i<animals.size();i++){

        totalHealth+=animals[i]->getHealth();

    }

    return totalHealth;

}

void displayTeamStatus(){

    //cout<<">>>"<<teamName<<" Status<<<"<<endl;
    for(int i=0;i<animals.size();i++){

        cout<<i+1<<".Animal:"<<endl;
        animals[i]->displayStatus();

    }

    cout<<"Team Total Health: "<<calculateTotalHealth()<<endl;

}

string getTeamName(){

    return teamName;

}

};

#endif
