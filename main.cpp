#include <iostream>

#include "City.hpp"
#include "Tour.hpp"
#include <vector>
#include <random>
#include <ctime>

//Makes vector of cities
void generateCities(int count, std::vector<City> &cityVect)
{
    std::default_random_engine generator(time(0));
    std::uniform_int_distribution<int> distribution(0,1000);
    distribution(generator); //Throw away the first because its always the same

    for(int i = 0; i < count; i++)
    {
        int x = distribution(generator);
        int y = distribution(generator);
        City newCity = City(x,y);
        cityVect.push_back(newCity);
    }
}

//Creates vectors of tours given a vector of cities
void createTours(int count, std::vector<Tour> &tourVect, std::vector<City> &cityVect)
{
    for(int i = 0; i < count; i++)
    {
        //cout << "hi";
        //tourVect.push_back(Tour(cityVect));
    }
}


void printCities(std::vector<City> &cityVect)
{
    for(int i = 0; i < cityVect.size(); i++)
    {
        cout << cityVect.at(i);
    }
}


int City::cityCount = 0;

int main() {
    std::vector<City> cityVect = std::vector<City>();
    std::vector<Tour> tourVect = std::vector<Tour>();

    generateCities(5, cityVect);
    printCities(cityVect);

    Tour test = Tour(cityVect);
    test.citySelector(cityVect);

    //createTours(5, tourVect, cityVect);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}