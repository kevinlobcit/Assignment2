//
// Created by Owntrolf on 2018-11-23.
//

#ifndef ASSIGNMENT_CITY_HPP
#define ASSIGNMENT_CITY_HPP

#include <string>
#include <iostream>

using namespace std;

class City {
    static int cityCount;
public:
    double x;
    double y;
    int seqNum;
    City(int xCoord, int yCoord);

    friend ostream& operator<<(std::ostream& os, const City& city);

};

#endif //ASSIGNMENT_CITY_HPP

