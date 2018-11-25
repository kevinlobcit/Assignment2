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
    double fitness;
    Tour(vector<City> vectCity);





    double determine_fitness();
    double get_tour_distance();
    double get_distance_between_cities(City city1, City city2);

    void citySelector(vector<City> vectCity);
};


#endif //ASSIGNMENT_TOUR_HPP
