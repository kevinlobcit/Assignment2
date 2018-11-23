//
// Created by Owntrolf on 2018-11-23.
//

#include "City.hpp"

City::City(int xCoord, int yCoord)
{
    if(xCoord > 1000 || yCoord > 1000)
    {
       x = 0;
       y = 0;
    }
    else
    {
        x = xCoord;
        y = yCoord;
    }

    seqNum = cityCount++;
}
