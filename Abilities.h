#ifndef ABILITIES_H
#define ABILITIES_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Running{
public:
virtual void run()=0;
virtual ~Running(){}

};

class Jumping{
public:
virtual void jump()=0;
virtual ~Jumping(){}

};


class Flyable{
public:
virtual void fly()=0;
virtual ~Flyable(){}

};


class Swimmable{
public:
virtual void swim()=0;
virtual ~Swimmable(){}

};

#endif
