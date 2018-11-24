#include <iostream>

#include "City.hpp"
#include "Tour.hpp"
#include <vector>
#include <random>
#include <ctime>

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
    generateCities(5, cityVect);
    printCities(cityVect);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}