//
// Created by Owntrolf on 2018-11-25.
//

#ifndef ASSIGNMENT_TOURMANAGER_HPP
#define ASSIGNMENT_TOURMANAGER_HPP

#include "Tour.hpp"
#include "City.hpp"
#include "Tour.hpp"
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>

class TourManager {

public :
    std::vector<City> cityVect;
    std::vector<Tour> tourVect;

    TourManager(int numCities, int numTours);

    //Makes vector of cities
    void generateCities(int count, std::vector<City> &cityVect);

    //Creates tours given a vector of cities
    void createTours(int count, std::vector<Tour> &tourVect, std::vector<City> &cityVect);

    //Prints out the cities in the order of the path of a certain City vector
    void printCities(std::vector<City> &cityVect);

    //Finds the elite within a tour
    void findElite(std::vector<Tour> &tourVect);

};


#endif //ASSIGNMENT_TOURMANAGER_HPP
