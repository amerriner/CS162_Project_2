/********************************************
 * program name: turtle.hpp
 * author: Ashley Merriner
 * date: 1/30/2018
 * description: header file for child class
   Turtle, which is an Animal in the Zoo.
***********************************************/

#ifndef TURTLE_HPP
#define TURTLE_HPP

#include "animal.hpp"

class Turtle : public Animal
{
   public:
      Turtle();
      Turtle(int);
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
