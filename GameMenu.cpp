#include "GameMenu.h"
#include "Lion.h"
#include "Monkey.h"
#include "Eagle.h"
#include "Shark.h"
#include "BattleArena.h"

void menu(){
    cout<<endl;
    cout<<">>>ZOO Battle Arena<<<"<<endl<<endl;
    cout<<"1.Display Animals"<<endl;
    cout<<"2.Display Animal Ability"<<endl;
    cout<<"3.Display Teams"<<endl;
    cout<<"4.Create Animal and Add Animal to Team"<<endl;
    cout<<"5.Display Trainer and Train Animal"<<endl;
    cout<<"6.Train All Animals"<<endl;
    cout<<"7.Battle Rules"<<endl;
    cout<<"8.Start Battle "<<endl;
    cout<<"Press 0 to exit"<<endl<<endl;

}

void displayAnimals(vector <Animal*>& list){
    int check1=1;

    while(check1!=0 && check1==1){
    cout<<endl;    
    cout<<">>>Animals<<<"<<endl<<endl;

    for(int i=0;i<list.size();i++){

        cout<<i+1<<".Animal:"<<endl;
        cout<<"Name: "<<list[i]->getName()<<endl;
        cout<<"Health: "<<list[i]->getHealth()<<endl;
        cout<<"Attack Power: "<<list[i]->getAttackPower()<<endl;
        cout<<endl;
    }

    cout<<"Press 0 to return menu or Press 1 to display again:";
    cin>>check1;

    if(check1!=0 && check1!=1){
    cout<<endl;    
    cout<<"Inavalid Value! || Please enter 0 or 1:";
    cin>>check1;
    }

}

}

void displayAnimalAbility(vector <Animal*>& list){
    int check2=1;

    while(check2!=0 && check2==1){
    cout<<endl;
    cout<<">>>Animal Abilities<<<"<<endl<<endl;

    for(int i=0;i<list.size();i++){
        list[i]->showAbility();
        cout<<endl;
    }

    cout<<"Press 0 to return menu or Press 1 to display again:";
    cin>>check2;

    if(check2!=0 && check2!=1){
    cout<<endl;
    cout<<"Inavalid Value! || Please enter 0 or 1:";
    cin>>check2;
    }

}

}

void displayTeams(vector <Team>& list){

    int check3=1;

    while(check3!=0 && check3==1){
    cout<<endl;
    cout<<"<<<Teams Information>>>"<<endl<<endl;

    for(int i=0;i<list.size();i++){

        cout<<i+1<<".Team "<<list[i].getTeamName()<<endl<<endl;
        list[i].displayTeamStatus();
        cout<<endl;
    }

    cout<<"Press 0 to return menu or Press 1 to display again:";
    cin>>check3;

    if(check3!=0 && check3!=1){
    cout<<endl;
    cout<<"Inavalid Value! || Please enter 0 or 1:";
    cin>>check3;
    }

}

}

void createAnimals(vector <Animal*>& listofanimal,vector <Team>& teams){

    int check6=1;
    int animalType;
    string animalName;
    int animalHealth;
    int animalAttackPower;
    int checkTeam;
    int checkAnimal;
    int check7=0;

    while(check6!=0 && check6==1){
    cout<<endl;    
    cout<<">>>Warning!<<<"<<endl<<endl;
    cout<<"If you create a new animal, you must replace with another animal from the other team!"<<endl<<endl;
    cout<<"Press 1 to continue or Press 0 to return menu:";
    cin>>check7;
    if(check7==0){
        
        break;
    }

    else if(check7!=1){
        cout<<endl;
        cout<<"Invalid Value!---> You are returning to menu!"<<endl;
        break;
    }

    cout<<endl;
    cout<<"1.Lion"<<endl;
    cout<<"2.Monkey"<<endl;
    cout<<"3. Eagle"<<endl;
    cout<<"4.Shark"<<endl;

    cout<<"Please choose animal type(1-4): ";
    cin>>animalType;
    cout<<endl;
        if(animalType<1 || animalType>4){
            cout<<"Invalid Value!--->You are returning to menu"<<endl;
            break;
        }

    cout<<"Please enter animal's name: ";
    cin>>animalName;
    cout<<endl;

    cout<<"Please enter animal's Health(0-200): ";
    cin>>animalHealth;
    cout<<endl;

        if(animalHealth<0 || animalHealth>200){
            cout<<"Invalid Value!--->You are returning to menu"<<endl;
            break;
        }

    cout<<"Please enter animal's Attack Power(0-70): ";
    cin>>animalAttackPower;
    cout<<endl;
        if(animalAttackPower<0 || animalAttackPower>70){
            cout<<"Invalid Value!---> You are returning to menu"<<endl;
            break;
        }

    Animal* animal;

    switch(animalType){

        case 1: animal= new Lion(animalName,animalHealth,animalAttackPower); break;
        case 2: animal= new Monkey(animalName,animalHealth,animalAttackPower); break;
        case 3: animal= new Eagle(animalName,animalHealth,animalAttackPower); break;
        case 4: animal= new Shark(animalName,animalHealth,animalAttackPower); break;

    }

    listofanimal.push_back(animal);

    cout<<"New animal was created successfully!"<<endl<<endl;

    
    cout<<"---Replace Animals---"<<endl;
    cout<<endl;
    cout<<"<<<Teams Information>>>"<<endl<<endl;

    for(int i=0;i<teams.size();i++){

        cout<<i+1<<".Team: "<<teams[i].getTeamName()<<endl<<endl;
        teams[i].displayTeamStatus();
        cout<<endl;
    }   

    cout<<"Please enter which team you want to add the animal you created to:";
    cin>>checkTeam;

    if(checkTeam<1 || checkTeam>4){
        cout<<endl;
        cout<<"Invalid Value!---> You are returning to menu"<<endl;
        break;
    }
    cout<<endl;

   cout<<"Please choose to animal replace with your animal which is you created(1-2):";
   cin>>checkAnimal;

    if(checkAnimal<1 || checkAnimal>2){
        cout<<endl;
        cout<<"Invalid Value!---> You are returning to menu"<<endl;
        break;
    }
   

   Animal* replacedAnimal= teams[checkTeam-1].animals[checkAnimal-1];
   teams[checkTeam-1].animals[checkAnimal-1]=animal;

    cout<<endl;
  
    cout<<"Animal was added successfully!"<<endl<<endl;
    cout<<animal->getName()<<" replaced "<<replacedAnimal->getName()<<" in "<<teams[checkTeam-1].getTeamName()<<endl<<endl;

    cout<<">>>Current Team<<<"<<endl<<endl;
    cout<<teams[checkTeam-1].getTeamName()<<endl;
    teams[checkTeam-1].displayTeamStatus();
    cout<<endl;

    cout<<"Press 1 to create new animal. Press 0 to return menu:";
    cin>>check6;

    if(check6!=0 && check6!=1){
        cout<<endl;
        cout<<"Inavalid Value! || Please enter 0 or 1:";
        cin>>check6;

    }

    }
}

void trainAnimal(Trainer& trainer,vector <Animal*>& listofanimal){

    int check4=1;
    int checking=0;
    int trainAnimal;

    while(check4!=0 && check4==1){
        cout<<endl;
        cout<<">>>Trainer Information<<<"<<endl<<endl;
        cout<<"Name: "<<trainer.getName()<<endl;
        cout<<"Age: "<<trainer.getAge()<<endl;
        cout<<"He is experienced in animal training."<<endl<<endl;
        cout<<"<<<Animals>>>"<<endl<<endl; 

        for(int i=0;i<listofanimal.size();i++){
            cout<<i+1<<".Animal:"<<endl;
            listofanimal[i]->displayStatus();

        }   

        cout<<"Which animal do you want to train:";
        cin>>trainAnimal;

        if(trainAnimal<1 || trainAnimal>listofanimal.size()){
            cout<<endl;
            cout<<"Invalid value! ---> You are returning to menu"<<endl;
            break;
        }

        trainer.addAnimalTrain(listofanimal[trainAnimal-1]);

        cout<<"1.Increase Attack Power ---> Trainer increases attack power by 10"<<endl;
        cout<<"2.Increase Health ---> Trainer increases health by 10"<<endl<<endl;
        cout<<"Which one do you want to perform:";
        cin>>checking;
        cout<<endl;
        cout<<endl;
        switch(checking){

            case 1: if(listofanimal[trainAnimal-1]->getAttackPower()>60){
                        cout<<"You can't increase the animal's attack power because animal's attack power should be max 70!"<<endl;
                        cout<<"Try again!"<<endl<<endl;  
                        break;
                    }
                    trainer.increaseAttackPower(0);
                    cout<<"Attack power was successfully increased!"<<endl<<endl;
                    cout<<"Current Attack Power: "<<listofanimal[trainAnimal-1]->getAttackPower()<<endl<<endl; 
                    break;
            case 2: if(listofanimal[trainAnimal-1]->getHealth()>190){
                        cout<<"You can't increase animal's health because animal's health should be max 200!"<<endl;
                        cout<<"Try again!"<<endl<<endl; 
                        break;
                    }
                    trainer.increaseHealth(0); 
                    cout<<"Health was successfully increased!"<<endl<<endl;
                    cout<<"Current Health: "<<listofanimal[trainAnimal-1]->getHealth()<<endl<<endl;
                    break; 
            default: cout<<"Invalid Value! --- Try again!"<<endl<<endl; break;
                    
        }   

        trainer.deleteAnimalTrain();

        cout<<"Press 0 to return menu or Press 1 to train again:";
        cin>>check4;

    if(check4!=0 && check4!=1){
        cout<<endl;
        cout<<"Inavalid Value! || Please enter 0 or 1:";
        cin>>check4;
    }
}

}

void trainAllAnimals(Trainer& trainer1,vector <Animal*>& listofanimal){

    int check9=1;
    int checking1=0;

        while(check9!=0 && check9==1){
            cout<<endl;
            cout<<">>>Trainer Information<<<"<<endl<<endl;
            cout<<"Name: "<<trainer1.getName()<<endl;
            cout<<"Age: "<<trainer1.getAge()<<endl;
            cout<<"He is experienced in animal training."<<endl<<endl;
            cout<<"<<<Animals>>>"<<endl<<endl; 

        for(int i=0;i<listofanimal.size();i++){
            cout<<i+1<<".Animal:"<<endl;
            listofanimal[i]->displayStatus();

        }   

        for(int i=0;i<listofanimal.size();i++){

            trainer1.addAnimalTrain(listofanimal[i]);

        }

        cout<<"1.Increase Attack Power ---> Trainer increases attack power by 10"<<endl;
        cout<<"2.Increase Health ---> Trainer increases health by 10"<<endl<<endl;
        cout<<"Which one do you want to perform:";
        cin>>checking1;
        cout<<endl;
        cout<<endl;
        for(int i=0;i<listofanimal.size();i++){

        switch(checking1){

            case 1: if(listofanimal[i]->getAttackPower()>60){
                        break;
                    }
                    trainer1.increaseAttackPower(i); 
                    break;
            case 2: if(listofanimal[i]->getHealth()>190){
                        break;
                    }
                    trainer1.increaseHealth(i); 
                    break; 
        }

        }

        trainer1.cleanAnimals();

        if(checking1==1){

            cout<<"The attack power of all animals with attack power less and equal than 60 was successfully increased."<<endl<<endl;
        }

        if(checking1==2){

        cout<<"The health of all animals with health less and equal than 190 was successfully increased."<<endl<<endl;
        }

        cout<<"Press 0 to return menu or Press 1 to train again:";
        cin>>check9;        

        if(check9!=0 && check9!=1){
            cout<<endl;
            cout<<"Inavalid Value! || Please enter 0 or 1:";
            cin>>check9;
    }
}
}


void startBattle(vector <Team>& teamList1){
int check5=1;  
int team1Check;
int team2Check;

while(check5!=0 && check5==1){
    cout<<endl;
    cout<<"<<<Teams>>>"<<endl<<endl;
    for(int i=0;i<teamList1.size();i++){

        cout<<i+1<<"."<<teamList1[i].getTeamName()<<endl<<endl;
        teamList1[i].displayTeamStatus();
        cout<<endl;

    }
    cout<<endl;
    cout<<"Choose first team to battle:";
    cin>>team1Check;
  
    cout<<"Choose other team to battle:";
    cin>>team2Check;

    BattleArena battle(&teamList1[team1Check-1],&teamList1[team2Check-1]);

    cout<<endl;
    battle.displayBattleInformation();
    battle.startBattle();

    cout<<"Press 0 to return menu or Press 1 to start again:";
    cin>>check5;

    if(check5!=0 && check5!=1){
    cout<<endl;
    cout<<"Inavalid Value! || Please enter 0 or 1:";
    cin>>check5;
    }
}
}

void battleRules(){

    int check8=1;

    while(check8!=0 && check8==1){
    cout<<endl;
    cout<<">>>Battle Rules<<<"<<endl<<endl;

    cout<<"For each animal encounter on each team, 1 round is played."<<endl;
    cout<<"As a result, a battle consists of 2 rounds because each team has 2 animals."<<endl;
    cout<<"Each round consists of 3 turns. In these 3 turns the players on the team fight"<<endl;
    cout<<"against each other respectively. If an animal dies before the 3rd turn, the number of"<<endl;
    cout<<"turns can be less than 3. At the end of the round, whichever of the animals has the"<<endl;
    cout<<"higher health wins the round. If the animals have the same health, the animal that"<<endl;
    cout<<"gives the higher damage wins the round. At the end of the match, the team that wins"<<endl;
    cout<<"more rounds is the winner. If the scores are equal, the match ends in a draw."<<endl<<endl;
        
    cout<<"Press 0 to return menu or Press 1 to display again:";
    cin>>check8;

    if(check8!=0 && check8!=1){
    cout<<endl;
    cout<<"Inavalid Value! || Please enter 0 or 1:";
    cin>>check8;

    }
}
}
