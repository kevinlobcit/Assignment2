//
// Created by Owntrolf on 2018-11-23.
//

#include "City.hpp"



City::City(int xCoord, int yCoord)
{
    x = xCoord;
    y = yCoord;
    seqNum = cityCount++;
}






ostream& operator<<(std::ostream &os, const City& city)
{
    os << city.x << " " << city.y << " CityNum: " << city.seqNum << endl;
    return os;
}
