#include "TourManager.hpp"

#define CITIES_IN_TOUR 50
#define POPULATION_SIZE 6
#define SHUFFLES 64
#define ITERATIONS 1000
#define MAP_BOUNDARY 1000
#define PARENT_POOL_SIZE 5
#define MUTATION_RATE 15
#define NUMBER_OF_PARENTS
#define NUMBER_OF_ELITES 1


int main() {
    TourManager tManager = TourManager(CITIES_IN_TOUR
            , POPULATION_SIZE
            , ITERATIONS
            , MUTATION_RATE
            );

    std::cout << "Hello, World!" << std::endl;
    return 0;
}