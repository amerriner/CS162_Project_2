/*************************************
 * program name: tiger.cpp
 * author: Ashley Merriner
 * date: 1/30/2018
 * description: implementation file
   for child class Tiger, an animal
   in the Zoo.
**************************************/

#include <iostream>
#include <string>
#include "animal.hpp"
#include "tiger.hpp"

using namespace std;

/**********************************************
 Default constructor initializes mem variables
***********************************************/
Tiger::Tiger() : Animal()
{
   this->age = 1;
   this->cost = 10000;
   this->numBabies = 1;
   this->baseFoodCost = 50;
   this->payoff = 2000;
}

/*****************************************
 Constructor with parameters
*****************************************/

Tiger::Tiger(int x) : Animal()
{
   this->age = x;
   this->cost = 10000;
   this->numBabies = 1;
   this->baseFoodCost = 50;
   this->payoff = 2000;
}

/***************************************
 Getters and setters of mem variables
****************************************/

void Tiger::setAge(int x)
{
   this->age = x;
}

void Tiger::setNumBabies(int x)
{
   this->numBabies = x;
}

int Tiger::getAge()
{
   return age;
}
 
int Tiger::getCost()
{
   return this->cost;
}

int Tiger::getNumBabies()
{
   return numBabies;
}

int Tiger::getBaseFoodCost()
{
   return this->baseFoodCost;
}

int Tiger::getPayoff()
{
   return this->payoff;
}
