#include <iostream>

#include "City.hpp"
#include "Tour.hpp"
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>

#define CITIES_IN_TOUR 5
#define POPULATION_SIZE 6
#define SHUFFLES 64
#define ITERATIONS 1000
#define MAP_BOUNDARY 1000
#define PARENT_POOL_SIZE 5
#define MUTATION_RATE 15
#define NUMBER_OF_PARENTS
#define NUMBER_OF_ELITES 1





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
        tourVect.push_back(Tour(cityVect));
        cout << "Tour" << i << " created" << endl;
    }
}

void printCities(std::vector<City> &cityVect)
{
    for(int i = 0; i < cityVect.size(); i++)
    {
        cout << cityVect.at(i);
    }
}

void findElite(std::vector<Tour> &tourVect)
{

    int eliteIndex = 0;
    cout << "hello";
    //Find position of highest fitness tour
    for(int i = 1; i < tourVect.size(); i++)
    {
        //cout << "hello";

        if(tourVect.at(eliteIndex).fitness > tourVect.at(i).fitness )
        {
            eliteIndex = i;
        }

    }
    iter_swap(tourVect.begin(), tourVect.begin() + eliteIndex);
    cout << "highest fitness tour is " << eliteIndex << endl;
    //printCities(tourVect.at(0).cityPath);
}

int City::cityCount = 0;

int main() {
    std::vector<City> cityVect = std::vector<City>();
    std::vector<Tour> tourVect = std::vector<Tour>();

    generateCities(5, cityVect);
    printCities(cityVect);

    //Tour test = Tour(cityVect);
    //test.citySelector(cityVect);

    createTours(5, tourVect, cityVect);

    findElite(tourVect);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}