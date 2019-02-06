/****************************************
 * program name: tiger.hpp
 * author: Ashley Merriner
 * date: 1/23/2018
 * description: header file for child
   class Tiger.
*****************************************/

#ifndef TIGER_HPP
#define TIGER_HPP
#include "animal.hpp"


class Tiger : public Animal
{
   public:
      Tiger();
      Tiger(int);
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
