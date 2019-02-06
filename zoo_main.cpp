#include <iostream>
#include <string>
#include "animal.hpp"
#include "tiger.hpp"
#include "penguin.hpp"
#include "turtle.hpp"
#include "zoo.hpp"

using namespace std;

int main()
{
   Zoo zoo;
   
   while (zoo.turn() == 1)
   {
      continue;
   }

   return 0;
}
