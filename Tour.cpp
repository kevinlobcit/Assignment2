//
// Created by Owntrolf on 2018-11-23.
//

#include "Tour.hpp"

Tour::Tour(vector<City> vectCity)
{
    citySelector(vectCity);
    fitness = determine_fitness();
    //cout << fitness << endl;
}




double Tour::determine_fitness()
{
    double dist = get_tour_distance();
    double fit = (1/dist) * 100000;

    return fit;
}

double Tour::get_tour_distance()
{
    double dist = 0;
    //calculates distance for 0, size-1
    for(int i = 0; i < cityPath.size()-1; i++)
    {
        dist += get_distance_between_cities(cityPath.at(i), cityPath.at(i+1));
    }

    //calculates distance with end going back to start
    dist += get_distance_between_cities(cityPath.at(0), cityPath.at(cityPath.size()-1));

    return dist;
}

double Tour::get_distance_between_cities(City city1, City city2)
{
    double x1 = city1.x;
    double y1 = city1.y;
    double x2 = city2.x;
    double y2 = city2.y;
    double x = abs(x1 - x2);
    double y = abs(y1 - y2);
    double dist = sqrt(x*x+y*y);
    return dist;
}

//Creates a random path based on the vector of cities given
void Tour::citySelector(vector<City> vectCity)
{
    //create number selector
    vector<int> cityNum = vector<int>();
    for(int i = 0; i < vectCity.size(); i++)
    {
        cityNum.push_back(i);
        //cout << i << endl;
    }

    vector<int> randCityNum = vector<int>();
    //Making the random vector list of city numbers
    int counter = cityNum.size()-1;
    //cout << counter;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    while(counter >= 0)
    {
        std::uniform_int_distribution<int> distribution(0,counter);
        distribution(generator); //Throw away the first because its always the same
        int rand = distribution(generator);
        //cout << rand  << " " << cityNum.at(rand)<< endl;
        //put city number into the randCityNum vector and delete from cityNum
        int cityNumber = cityNum.at(rand);
        //cout << "adding " << cityNumber << endl;
        randCityNum.push_back(cityNumber);//add number to the randCityNum vector

        cityNum.erase(cityNum.begin()+rand); //Remove city already placed in
        //cout <<  rand << " " << cityNum.at(rand) << " " <<cityNum.size()<< endl;

         counter--;
    }

    //Put the cities given the city number into the vectCity vector

    for(int i = 0; i < randCityNum.size(); i++)
    {
        int randCityNo = randCityNum.at(i);
        cityPath.push_back(vectCity.at(randCityNo));
        //cout << cityPath.at(i);
    }



}

