/*************************************
 * program name: animal.cpp
 * author:Ashley Merriner
 * date: 1/30/2018
 * description: implementation file
   for class Animal, which is the 
   parent class for the zoo animals.
**************************************/

#include <iostream>
#include <string>
#include "animal.hpp"

using namespace std;
/*************************************
 default constructor for parent class
**************************************/
Animal::Animal()
{
   age = 0;
   cost = 0;
   numBabies =0;
   baseFoodCost = 10;
   payoff = 0;
}

