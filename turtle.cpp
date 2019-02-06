/*********************************************
 * program name: turtle.cpp
 * author: Ashley Merriner
 * date: 1/30/2018
 * description: this is the implementation
   file for child class Turtle, which is 
   an Animal in the Zoo.
**********************************************/

#include <iostream>
#include <string>
#include "turtle.hpp"
#include "animal.hpp"

using namespace std;
/************************************************
 Default Constructor: initializes mem variables
*************************************************/

Turtle::Turtle() : Animal()
{
   this->age = 1;
   this->cost = 100;
   this->numBabies = 10;
   this->baseFoodCost = 5;
   this->payoff = 5;
}
/**********************************
 Constructor with parameter
**********************************/
Turtle::Turtle(int x) : Animal()
{
   this->age = x;
   this->cost = 100;
   this->numBabies = 10;
   this->baseFoodCost = 5;
   this->payoff = 5;
}

/**************************************
 Getters and Setters of mem variables
*****************************************/

void Turtle::setAge(int x)
{
   this->age = x;
}

void Turtle::setNumBabies(int x)
{
   this->numBabies = x;
}

int Turtle::getAge()
{
   return this->age;
}

int Turtle::getCost()
{
   return this->cost;
}

int Turtle::getNumBabies()
{
   return this->numBabies;
}

int Turtle::getBaseFoodCost()
{
   return this->baseFoodCost;
}

int Turtle::getPayoff()
{
   return this->payoff;
}
