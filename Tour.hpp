//
// Created by Owntrolf on 2018-11-23.
//

#ifndef ASSIGNMENT_TOUR_HPP
#define ASSIGNMENT_TOUR_HPP

#include "City.hpp"
#include <vector>
#include <set>
#include <random>
#include <ctime>
#include <cstdlib>
#include <chrono>

class Tour {
public:
    vector<City> cityPath = vector<City>();
    Tour(vector<City> vectCity);







    void citySelector(vector<City> vectCity);
};


#endif //ASSIGNMENT_TOUR_HPP
