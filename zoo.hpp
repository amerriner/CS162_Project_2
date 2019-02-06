/***********************************
 * program name: zoo.hpp
 * author: Ashley Merriner
 * date: 1/30/2018
 * description: header file for 
   zoo class.
***********************************/

#ifndef ZOO_HPP
#define ZOO_HPP

#include "animal.hpp"
#include "tiger.hpp"
#include "penguin.hpp"
#include "turtle.hpp"

enum Type {BABY, ADULT};

class Zoo
{
   private:
      int money;
      int tigSize;
      int penSize;
      int turtSize;
      Tiger** tigers;
      Penguin** penguins;
      Turtle** turtles;
      int tigNum;
      int penNum;
      int turtNum;
   public:
      Zoo();
      ~Zoo();
      void newDay();
      int turn();
      void payFeedingCost();
      void randEvent();
      void calcPayoff();
      void buyNewAnimal();
      void sickness();
      void attendanceBoom();
      void newBaby();
      int getMoney();
      int getTigSize();
      int getPenSize();
      int getTurtSize();
      void setMoney(int);
      void setTigSize(int);
      void setPenSize(int);
      void setTurtSize(int);
};
#endif
