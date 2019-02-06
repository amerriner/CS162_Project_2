/*************************************
 * program name: penguin.cpp
 * author: Ashley Merriner
 * date: 1/30/2018
 * description: implementation file
   for child class Penguin, an Animal
   in the Zoo.
*****************************************/

#include <iostream>
#include <string>
#include "animal.hpp"
#include "penguin.hpp"

using namespace std;

/***********************************************
 Default Constructor: initalizes mem variables
***********************************************/
Penguin::Penguin() : Animal()
{
   this->age = 1;
   this->cost = 1000;
   this->numBabies = 5;
   this->baseFoodCost = 10;
   this->payoff = 100;
}
/*********************************************
 Constructor with parameters
*******************************************/
Penguin::Penguin(int x) : Animal()
{
   this->age = x;
   this->cost = 1000;
   this->numBabies = 5;
   this->baseFoodCost = 10;
   this->payoff = 100;
}

/**********************************************
  Getters and Setters for mem variables
*************************************************/

void Penguin::setAge(int x)
{
   this->age = x;
}
void Penguin::setNumBabies(int x)
{
   this->numBabies = x;
}

int Penguin::getAge()
{
   return this->age;
}

int Penguin::getCost()
{
   return this->cost;
}

int Penguin::getNumBabies()
{
   return this->numBabies;
}

int Penguin::getBaseFoodCost()
{
   return this->baseFoodCost;
}

int Penguin::getPayoff()
{
   return this->payoff;
}
