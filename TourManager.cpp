//
// Created by Owntrolf on 2018-11-25.
//

#include "TourManager.hpp"

int City::cityCount = 0;

TourManager::TourManager(int numCities, int numTours)
{
    cityVect = std::vector<City>();
    tourVect = std::vector<Tour>();
    generateCities(numCities, cityVect);
    createTours(numTours, tourVect, cityVect);
}


//Makes vector of cities
void TourManager::generateCities(int count, std::vector<City> &cityVect)
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

void TourManager::createTours(int count, std::vector<Tour> &tourVect, std::vector<City> &cityVect)
{
    for(int i = 0; i < count; i++)
    {
        tourVect.push_back(Tour(cityVect));
        cout << "Tour" << i << " created" << endl;
    }
}

void TourManager::printCities(std::vector<City> &cityVect)
{
    for(int i = 0; i < cityVect.size(); i++)
    {
        cout << cityVect.at(i);
    }
}

void TourManager::findElite(std::vector<Tour> &tourVect)
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
