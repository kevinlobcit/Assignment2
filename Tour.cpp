//
// Created by Owntrolf on 2018-11-23.
//

#include "Tour.hpp"

Tour::Tour(vector<City> vectCity)
{
    citySelector(vectCity);
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
        cout << rand  << " " << cityNum.at(rand)<< endl;
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

