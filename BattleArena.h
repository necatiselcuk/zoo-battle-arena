#ifndef BATTLEARENA_H
#define BATTLEARENA_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Team.h"

class BattleArena{
private:
Team* team1;
Team* team2;
int team1score;
int team2score;
Team* winner;

void setMatchWinner(){

    if(team1score>team2score){
        winner=team1;
    }

    else if(team2score>team1score){
        winner=team2;

    }

}

void setRoundWinner(int i){

    int a;
    int animal1StartHealth=0;
    int animal2StartHealth=0;

    animal1StartHealth=team1->animals[i]->getHealth();
    animal2StartHealth=team2->animals[i]->getHealth();

    cout<<">>>Round has started!<<<"<<endl<<endl;

    for(a=0;a<3;a++){
        
        cout<<a+1<<".Turn:"<<endl;

        team1->animals[i]->performAttack(team2->animals[i]);
        team2->animals[i]->performAttack(team1->animals[i]);

        if(team1->animals[i]->getHealth()<=0|| team2->animals[i]->getHealth()<=0){

            break;

        }
    
    }

    cout<<endl;
    cout<<">>>Round Summary<<<"<<endl<<endl;

    cout<<team1->animals[i]->getName()<<" Health: "<<team1->animals[i]->getHealth()<<" || "
    <<team2->animals[i]->getName()<<" Health: "<<team2->animals[i]->getHealth()<<endl<<endl;

    cout<<"Given Total Damage by "<<team1->animals[i]->getName()<<": "<<animal2StartHealth - team2->animals[i]->getHealth()<<endl;
    cout<<"Given Total Damage by "<<team2->animals[i]->getName()<<": "<<animal1StartHealth - team1->animals[i]->getHealth()<<endl<<endl;

    if(team1->animals[i]->getHealth() > team2->animals[i]->getHealth()){

    team1score++;
    cout<<endl;
    cout<<"This Round Winner: "<<team1->animals[i]->getName();
    cout<<endl<<endl;
    }

    else if(team2->animals[i]->getHealth() > team1->animals[i]->getHealth()){

    team2score++;
    cout<<endl;
    cout<<"This Round Winner: "<<team2->animals[i]->getName();
    cout<<endl<<endl;
        
    }
    //this damage given by animal 1.                            //this damage given by animal 2.
    else if(animal2StartHealth - team2->animals[i]->getHealth() > animal1StartHealth - team1->animals[i]->getHealth()){
    team1score++;
    cout<<endl;
    cout<<"This Round Winner: "<<team1->animals[i]->getName();
    cout<<endl<<endl;
    }

    else if(animal1StartHealth - team1->animals[i]->getHealth() > animal2StartHealth - team2->animals[i]->getHealth()){
    team2score++;
    cout<<endl;
    cout<<"This Round Winner: "<<team2->animals[i]->getName();
    cout<<endl<<endl;        

    }
} 

public:
BattleArena(Team* t1, Team* t2): team1(t1), team2(t2){
team1score=0;
team2score=0;

}

void displayBattleInformation(){

    cout<<">>>Battle Arena Information<<<"<<endl<<endl;
    cout<<"1.Team: "<<team1->getTeamName()<<endl<<endl;
    team1->displayTeamStatus();
    cout<<endl;
    cout<<"     VS"<<endl<<endl;
    cout<<"2.Team: "<<team2->getTeamName()<<endl<<endl;
    team2->displayTeamStatus();
    cout<<endl;

}

void startBattle(){

    cout<<">>>Battle is starting<<<"<<endl<<endl;

    int beginningHealthTeam1=0;
    int beginningHealthTeam2=0;

    for(int i=0;i<team1->animals.size();i++){
        
        beginningHealthTeam1=team1->animals[i]->getHealth();
        beginningHealthTeam2=team2->animals[i]->getHealth();

        cout<<i+1<<".Round"<<endl<<endl;
        cout<<"Team:"<<team1->getTeamName()<<" || Animal's Status:"<<endl;
        team1->animals[i]->displayStatus();
        cout<<"     VS"<<endl<<endl;
        cout<<"Team:"<<team2->getTeamName()<<" || Animal's Status:"<<endl;
        team2->animals[i]->displayStatus();
        cout<<endl;

        setRoundWinner(i);

        team1->animals[i]->setHealth(beginningHealthTeam1);
        team2->animals[i]->setHealth(beginningHealthTeam2);

    }

    setMatchWinner();

    cout<<team1->getTeamName()<<" Team Score: "<<team1score<<endl;
    cout<<team2->getTeamName()<<" Team Score: "<<team2score<<endl;

    cout<<endl;

    if(winner==team1){

        cout<<"Winner Team: "<<team1->getTeamName()<<endl;

    }

    else if(winner==team2){

        cout<<"Winner Team: "<<team2->getTeamName()<<endl;

    }

    else{

    cout<<"The match is draw!"<<endl<<endl;
   
    }

    
}

};

#endif
