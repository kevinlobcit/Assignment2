//
// Created by Owntrolf on 2018-11-25.
//

#include "TourManager.hpp"

int City::cityCount = 0;

TourManager::TourManager(int numCities, int numTours)
{
    cityVect = std::vector<City>();
    tourVect = std::vector<Tour>();
    generateCities(numCities);
    createTours(numTours);
    findElite();
}


//Makes vector of cities
void TourManager::generateCities(int count)
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

void TourManager::createTours(int count)
{
    for(int i = 0; i < count; i++)
    {
        tourVect.push_back(Tour(cityVect));
        cout << "Tour" << i << " created" << endl;
    }
}

void TourManager::printCities()
{
    for(int i = 0; i < cityVect.size(); i++)
    {
        cout << cityVect.at(i);
    }
}

void TourManager::findElite()
{

    int eliteIndex = 0;
    //cout << "hello";
    //Find position of highest fitness tour
    for(int i = 1; i < tourVect.size(); i++)
    {
        //cout << "hello";

        if(tourVect.at(eliteIndex).fitness < tourVect.at(i).fitness )
        {
            eliteIndex = i;
        }

    }
    iter_swap(tourVect.begin(), tourVect.begin() + eliteIndex);
    cout << "highest fitness tour is " << eliteIndex << endl;
    //printCities(tourVect.at(0).cityPath);
}

//Crosses all tours except the elite
void TourManager::crosses()
{
    std::vector<Tour> tempTourVect = std::vector<Tour>();
    tempTourVect.push_back(tourVect.at(0)); //placing back elite into tour
    for(int i = 1; i < tourVect.size() - 1; i++)
    {
        Tour newTour = crossTours(tourVect.at(i), tourVect.at(i+1));
        tempTourVect.push_back(newTour);
    }
    Tour newTour = crossTours(tourVect.at(tourVect.size()-1), tourVect.at(1));
    tempTourVect.push_back(newTour);

    tourVect.swap(tempTourVect);
}

//Crosses two tours together and returns a tour
Tour TourManager::crossTours(Tour tour1, Tour tour2)
{
    std::vector<City> tCity1 = tour1.cityPath;
    std::vector<City> tCity2 = tour2.cityPath;

    //for checking which indexes have been added
    std::vector<int> indexAdded = std::vector<int>();
    std::vector<int> cityNumbers = std::vector<int>();
    for(int i = 0; i < tCity1.size(); i++)
    {
        indexAdded.push_back(i);
        cityNumbers.push_back(i);
    }


    int counter = indexAdded.size()-1;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(0,counter);
    distribution(generator); //Throw away the first because its always the same
    int rand = distribution(generator);

    //City cityNumber = tCity1.at(rand);
    //The citylist to create the new tour
    int cityNum = tCity2.at(rand).seqNum;
    int index = 0;
    std::vector<City> newPath = std::vector<City>();
    //fill newpath with the city1path
    for(int i = 0; i < tCity1.size(); i++)
    {
        if(tCity1.at(i).seqNum == cityNum)
        {
            index = i; //saves index to swap with
        }
        newPath.push_back(tCity1.at(i));
    }
    iter_swap(newPath.begin() + index, newPath.begin() + rand);

    Tour newTour = Tour(newPath);

    return newTour;
}


