#include <iostream>
#include "GameSimulator.h"

int main()
{
   GameSimulator gs;

   if(gs.playGame())
   {
       std::cout << "WON\n";
   }
   else
   {
       std::cout << "LOST\n";
   }

}
