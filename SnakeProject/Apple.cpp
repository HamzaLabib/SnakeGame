#include "Apple.h"

//default constructor
Apple::Apple() : position(0, 0) {
}

//creates a new apple within bounds
void Apple::createApple(Coordinate topLeft, Coordinate bottomRight) {
    position.X = Random::getRandomInteger(topLeft.X+1, bottomRight.X-1);
    position.Y = Random::getRandomInteger(topLeft.Y+1, bottomRight.Y-1);
}

//returns the current position of the apple
Coordinate Apple::getPosition() {
    return position;
}


