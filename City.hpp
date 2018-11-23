//
// Created by Owntrolf on 2018-11-23.
//

#ifndef ASSIGNMENT_CITY_HPP
#define ASSIGNMENT_CITY_HPP

#include <string>

using namespace std;

class City {
private:
    static int cityCount;

    double x;
    double y;
    int seqNum;
public:
    City(int xCoord, int yCoord);

};


#endif //ASSIGNMENT_CITY_HPP
