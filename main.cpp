#include "Lion.h"
#include "Monkey.h"
#include "Eagle.h"
#include "Shark.h"
#include "Team.h"
#include "Trainer.h"
#include "GameMenu.h"

int main(){

Animal* a1=new Lion("Forest King",180,65);
Animal* a2=new Eagle("Black Eagle",130,50);
Animal* a3=new Monkey("Banana",150,50);
Animal* a4=new Shark("Storm Wave",190,40);
Animal* a5=new Eagle("Fire",140,60);
Animal* a6=new Lion("Leo",130,65);
Animal* a7=new Shark("Big Hunter",145,70);
Animal* a8=new Monkey("Boom",200,40);

vector <Animal*> animalList={a1,a2,a3,a4,a5,a6,a7,a8};


Team team1("The Invincibles");
Team team2("The Immortals");
Team team3("Big Wind");
Team team4("Tornado");

team1.addAnimal(a3);
team1.addAnimal(a6);

team2.addAnimal(a5);
team2.addAnimal(a8);

team3.addAnimal(a2);
team3.addAnimal(a7);

team4.addAnimal(a1);
team4.addAnimal(a4);

vector <Team> teamList={team1,team2,team3,team4};

Trainer trainer1("Necati",20);

    int check=1;

    while(check!=0){
        int op;
        menu();
        cout<<"Please Enter the number (0-6) for the operation you want to perform:";
        cin>>op;

        switch(op){

            case 0: check=0; break;
            case 1: displayAnimals(animalList); break;
            case 2: displayAnimalAbility(animalList); break;
            case 3: displayTeams(teamList); break;
            case 4: createAnimals(animalList,teamList); break;
            case 5: trainAnimal(trainer1,animalList); break;
            case 6: trainAllAnimals(trainer1,animalList); break;
            case 7: battleRules(); break;
            case 8: startBattle(teamList); break;
            default: cout<<endl<<"Invalid Value!"<<endl; break;

        }

    }

  return 0;
}
