/***********************************
 * program name: penguin.hpp
 * author: Ashley Merriner
 * date: 1/30/2018
 * description: header file for 
   child class Penguin, an animal
   at the Zoo.
************************************/

#ifndef PENGUIN_HPP
#define PENGUIN_HPP

#include "animal.hpp"

class Penguin : public Animal
{
   public:
      Penguin();
      Penguin(int);
      void addDay();
      void setAge(int);
      void setNumBabies(int);
      int getAge();
      int getCost();
      int getNumBabies();
      int getBaseFoodCost();
      int getPayoff();
};

#endif
