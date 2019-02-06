/******************************************
 * program name: zoo.cpp
 * Author: Ashley Merriner
 * Date: 1/31/2018
 * description: this program implements
   the zoo class for the zoo tycoon game.
********************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include "zoo.hpp"
#include "animal.hpp"
#include "tiger.hpp"
#include "penguin.hpp"
#include "turtle.hpp"

using namespace std;
/**************************************
  Constructor: initializes variables
***************************************/

Zoo::Zoo()
{
   money = 100000;
   tigSize = 10;
   penSize = 10;
   turtSize = 10;

   tigers = new Tiger*[tigSize];
   for (int i = 0; i < tigSize; i++)
   {
       tigers[i] = 0;
   }

   penguins = new Penguin*[penSize];
   for (int j = 0; j < penSize; j++)
   {
      penguins[j] = 0;
   } 

   turtles = new Turtle*[turtSize];
   for (int k = 0; k < turtSize; k++)
   {
      turtles[k] = 0;
   }

   cout << "Congrats on opening your zoo! You started with $100000."
        << "You have to buy a tiger ($10,000), a penguin ($1000), and a turtle ($100)." << endl;
   
   money = money - 11100;

   cout << "You now have $" << money << " to begin your zoo! Good luck!" << endl;
   cout << "\n";
   cout << "\n";
   cout << "\n";

   tigers[0] = new Tiger();
   penguins[0] = new Penguin();
   turtles[0] = new Turtle();
   
   tigNum = 1;
   penNum = 1;
   turtNum = 1;
   
}
/****************************************
 Destructor: destroys dynamic memory
****************************************/
Zoo::~Zoo()
{
   for (int x = 0; x < tigSize; x++)
   {
      delete tigers[x];
   }
   delete [] tigers;
   
   for (int y = 0; y < penSize; y++)
   {
      delete penguins[y];
   }
   delete [] penguins;

   for (int z = 0; z < turtSize; z++)
   {
      delete turtles[z];
   }
   delete [] turtles;
}

/****************************************
 newDay(): adds a day to animals' age
*****************************************/

void Zoo::newDay()
{
   for (int x = 0; x < tigNum; x++)
   {
      int r;
      r = tigers[x]->getAge();
      tigers[x]->setAge(r++);
   }
   
   for (int y = 0; y < penNum; y++)
   {
      int q;
      q = penguins[y]->getAge();
      penguins[y]->setAge(q++);
   }

   for (int z = 0; z < turtNum; z++)
   {
      int s;
      s = turtles[z]->getAge();
      turtles[z]->setAge(s++);
   }
}

/*****************************************
  turn(): goes through the day and asks
  user if they would like to play again.
*****************************************/

int Zoo::turn()
{
   cout << "Good morning!" << endl;
   cout << "\n \n";
   if (money != 0)
   {
      char answer;
      newDay();
      payFeedingCost();
      randEvent();
      calcPayoff();
      buyNewAnimal();
      cout << "Do you want to continue? Enter 'y' for yes "
           << "or 'n' for no." << endl;
      cin >> answer;
      if (answer == 'y' || answer == 'Y')
      {
         cout << "Get ready for a new day! \n \n" << endl;
         return 1;
      }
      else if (answer == 'n' || answer == 'N')
      {
         cout << "Thanks for playing!" << endl;
         return 0;
      }
      else
      {
         while (answer != 'Y' && answer != 'N' &&
                answer != 'y' && answer != 'n')
         {
            cout << "Please enter a 'y' or 'n'." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> answer;
            if (answer == 'y' || answer == 'Y')
            {
               return 1;
            }
            else if (answer == 'n' || answer == 'N')
            {
               return 0;
            }
         }
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
       }
   }
   else 
   {
      cout << "You ran out of money!"
           << " Thank you for playing!" << endl;
      return 0;
   }
}

/***********************************
 randEvent(): Picks random event
***********************************/

void Zoo::randEvent()
{
   srand(time(NULL));
   int r = (rand() % 4) + 1;
   if (r == 1)
   {
      cout << "Oh no! One of your animals is sick!" << endl;
      sickness();
   }
   else if (r == 2)
   {
      cout << "Attendance boom! " 
           << "Special bonus ($250-$500) for each tiger you have!" << endl;
      attendanceBoom();
   }
   else if (r == 3)
   {
      cout << "Hooray! A new baby is born!" << endl;
      newBaby();
   }
   else if (r == 4)
   {
      cout << "Just an ordinary day!" << endl;
   }
}

/***********************************
 sickness(): inflicts sickness on 
 an animal.
*************************************/

void Zoo::sickness()
{
   srand(time(NULL));
   int r = (rand() % 3) + 1;
   if (r == 1 && tigNum != 0) //tigers
   {
      cout << "A tiger has died." << endl;
      tigers[tigNum-1] == 0;
      tigNum--;
      cout << "You have " << tigNum << " tigers left." << endl;
   }
   else if (r == 2 && penNum != 0) //penguins
   {
       cout << "A penguin has died." << endl;
       penguins[penNum - 1] == 0;
       penNum--;
       cout << "You have " << penNum << " penguins left." << endl;
   }
   else if (r == 3 && turtNum != 0) //turtles
   {
      cout << "A turtle has died." << endl;
      turtles[turtNum - 1] == 0;
      turtNum--;
      cout << "You have " << turtNum << " turtles left." << endl;
   }
}

/****************************************
 attendanceBoom(): grants bonus for 
 having tigers.
****************************************/

void Zoo::attendanceBoom()
{
   int range = 251;
   int num = 0;
   for (int x = 0; x < tigNum; x++)
   {
      num += (rand() % range) + 250;
   }
   cout << "You made $" << num << " in bonus from your tigers!!!" << endl;
   money += num;
   cout << "You now have $" << money << "." << endl;
}

/********************************
 newBaby(): adds an animal to 
  the array.
*********************************/

void Zoo::newBaby()
{
   srand(time(NULL));
   int r = (rand() % 3) + 1;
   if (r == 1) //if tigers
   {
      cout << "You have a new baby tiger!!!" << endl;
      for (int x = 0; x < tigNum; x++)
      {
         if ((tigers[x]->getAge() >= 3) && (tigers[x]->getNumBabies() == 1))
         {
            if (tigNum < tigSize)
            {
               tigers[tigNum] = new Tiger(0);
            }
            else
            {
               Tiger* temp = new Tiger[tigSize * 2];
               for (int i = 0; i < tigSize; i++)
               {
                   temp[i] = *tigers[i];
               }
               /*
               for (int u = 0; u < tigSize; u++)
               {
                  delete tigers[u];
               }*/
               delete [] tigers;
               *tigers = temp;
               int oldTigSize = tigSize;
               tigSize = tigSize*2;
               tigers[oldTigSize] = new Tiger(0);
               
            }
            tigNum++;
            cout << "You now have " << tigNum << " tigers." << endl;
            tigers[x]->setNumBabies(0);
            break;
         }
      }
   }
   else if (r == 2) //if penguins
   {
      cout << "You have a new baby penguin!!!" << endl;
      for (int y = 0; y < penNum; y++)
      {
         int numB = penguins[y]->getNumBabies();
         if ((penguins[y]->getAge() >=3) && (numB > 0))
         {
            if (penNum < penSize)
            {
               penguins[penNum] = new Penguin(0);
            }
            else
            {
               Penguin* temp = new Penguin[penSize * 2];
               for (int j = 0; j < penSize; j++)
               {
                  temp[j] = *penguins[j];
               }
               /*
               for (int v = 0; v < penSize; v++)
               {
                  delete penguins[v];
               }*/
               delete [] penguins;
               *penguins = temp;
               int oldPenSize = penSize;
               penSize = penSize * 2;
               penguins[oldPenSize] = new Penguin(0);
               
            }
            penNum++;
            cout << "You now have " << penNum << " penguins." << endl;
            numB--;
            penguins[y]->setNumBabies(numB);
            break;
         }
      }
   }
   else if (r == 3) //if turtles
   {
      cout << "You have a new baby Turtle!!!" << endl;
      for (int z = 0; z < turtNum; z++)
      {
         int babies = turtles[z]->getNumBabies();
         if ((turtles[z]->getAge() >= 3) && (babies > 0))
         {
            if (turtNum < turtSize)
            {
               turtles[turtNum] = new Turtle(0);
            }
            else
            {
               Turtle* temp = new Turtle[turtSize * 2];
               for (int h = 0; h < turtSize; h++)
               {
                  temp[h] = *turtles[h];
               }
               /*
               for (int w = 0; w < turtSize; w++)
               {
                  delete turtles[w];
               }*/
               delete [] turtles;
               *turtles = temp;
               int oldTurtSize = turtSize;
               turtSize = turtSize * 2;
               turtles[oldTurtSize] = new Turtle(0);
             
            }
            turtNum++;
            cout << "You now have " << turtNum << " turtles." << endl;
            babies--;
            turtles[z]->setNumBabies(babies);
            break;
         }
      }
   }
}

/****************************************
 payFeedingCost(): pays food cost for 
  all the animals.
****************************************/

void Zoo::payFeedingCost()
{
   int tigFeed = 0;
   int penFeed = 0;
   int turtFeed = 0;
   int total = 0;

   for (int x = 0; x < tigNum; x++)
   {
      tigFeed = tigFeed + 50;
   }

   for (int y = 0; y < penNum; y++)
   {
         penFeed = penFeed + 10;
   }

   for (int z = 0; z < turtNum; z++)
   {
         turtFeed = turtFeed + 5;
   }

   total = tigFeed + penFeed + turtFeed;
   money = (money - total);
   cout << "You spent: $" << total << " on feed. You have: $" << money << "." << endl;
}

/**********************************************
 calcPayoff(): calculates the payoff from the
  animals.
***********************************************/

void Zoo::calcPayoff()
{
   int tigP = 0;
   int penP = 0;
   int turtP = 0;
   int total;

   for (int x = 0; x < tigNum; x++)
   {
      tigP = tigP + 2000;
   }

   for (int y = 0; y < penNum; y++)
   {
      penP = penP + 100;
   }
   
   for (int z = 0; z < turtNum; z++)
   {
      turtP = turtP + 5;
   }
  
   total = tigP + penP + turtP;
   money = money + total;
   cout << "You made $" << total << " today. You have: $" << money << "." << endl;
}

/**************************************
 buyNewAnimal(): asks user if they'd 
 like to buy a new animal and adds
 it to the array
***************************************/

void Zoo::buyNewAnimal()
{
   int answer;
   while (1)
   {
      cout << "Would you like to buy another animal?"
           << " Enter 1 for tiger, 2 for penguin, 3 for turtle,"
           << " or 4 for no animal." << endl;
      cin >> answer;

      if (answer == 1)  //tigers
      {
         if (tigNum < tigSize)
         {
            tigers[tigNum] = new Tiger(3);
            tigNum++;
         }

         else //allocate more memory
         {
            Tiger* temp;
            temp = new Tiger[(tigSize * 2)];
         
            for (int i = 0; i < tigSize; i++)
            {
                 temp[i] = *tigers[i];
            }
            /*
            for (int b = 0; b < tigSize; b++)
            {
               delete tigers[b];
            }*/
            delete [] tigers;

            *tigers = temp;
            int oldTigSize = tigSize;
            tigSize = tigSize * 2;
            tigers[oldTigSize] = new Tiger(3);
            tigNum++;
         }
         money = money - 10000;
         cout << "You have bought a tiger. You now have $" << money << "." << endl;
      }


      else if (answer == 2)
      {
         if (penNum < penSize)
         {
            penguins[penNum] = new Penguin(3);
            penNum++;
         }

         else //allocate more memory
         {

            Penguin* temp;
            temp = new Penguin[(penSize * 2)];
            for (int h = 0; h < penSize; h++)
            {
               temp[h] = *penguins[h];
            }
            /*
            for (int p = 0; p < penSize; p++)
            {
               delete penguins[p];
            }
            */
            delete [] penguins;
            *penguins = temp;
            int oldPenSize = penSize;
            penSize = penSize * 2;
            penguins[oldPenSize] = new Penguin(3);
            penNum++;
         }
         money = money - 1000;
         cout << "You have bought a penguin. You now have $" << money << "." << endl;
      }

      else if (answer == 3)
      {
         if (turtNum < turtSize)
         {
            turtles[turtNum] = new Turtle(3);
            turtNum++;
         }
         else //allocate more memory
         {
            Turtle* temp;
            temp = new Turtle[(turtSize * 2)];
            for (int z = 0; z < turtSize; z++)
            {
               temp[z] = *turtles[z];
            }
            /*
            for (int o = 0; 0 < turtSize; o++)
            {
               delete turtles[o];
            }
            */
            delete [] turtles;
            *turtles = temp;
            int oldTurtSize = turtSize;
            turtSize = turtSize * 2;
            turtles[oldTurtSize] = new Turtle(3);
            turtNum++;
         }
         money = money - 100;
         cout << "You have bought a turtle. You now have $" << money << ".\n";
      }
  
      else if (answer == 4)
      {
         cout << "You did not buy an animal today." << endl;
      }
   
      else 
      {
         cout << "Please enter 1, 2, 3, or 4." << endl;
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
         continue;
      }
      cin.ignore (numeric_limits<streamsize>::max(), '\n');
      break;
     
   }   
}

/*****************************************
  Getters and Setters for mem variables
*****************************************/  
       
int Zoo::getMoney()
{
   return money;
}

int Zoo::getTigSize()
{
   return tigSize;
}

int Zoo::getPenSize()
{
   return penSize;
}

int Zoo::getTurtSize()
{
   return turtSize;
}

void Zoo::setMoney(int x)
{
   money = x;
}

void Zoo::setTigSize(int x)
{
   tigSize = x;
}

void Zoo::setPenSize(int x)
{
   penSize = x;
}
  
void Zoo::setTurtSize(int x)
{
   turtSize = x;
}  
