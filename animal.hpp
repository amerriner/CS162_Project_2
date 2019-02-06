/************************************************
 * program name: animal.hpp
 * author: Ashley Merriner
 * date: 1/30/2018
 * description: header file for class animal,
   which is a parent class to the zoo animals.
************************************************/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal
{
   protected:
      int age;
      int cost;
      int numBabies;
      int baseFoodCost;
      int payoff;

   public:
      Animal();
      void addDay();
};
#endif
