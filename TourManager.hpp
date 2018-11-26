//
// Created by Owntrolf on 2018-11-25.
//

#ifndef ASSIGNMENT_TOURMANAGER_HPP
#define ASSIGNMENT_TOURMANAGER_HPP

#include "Tour.hpp"
#include "City.hpp"
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
    void generateCities(int count);

    //Creates tours given a vector of cities
    void createTours(int count);

    //Prints out the cities in the order of the path of a certain City vector
    void printCities();

    //Finds the elite within a tour
    void findElite();

    //Crosses the tours for the next iteration
    void crosses();

    //Crosses two tours
    Tour crossTours(Tour tour1, Tour tour2);

};


#endif //ASSIGNMENT_TOURMANAGER_HPP
