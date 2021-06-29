#pragma once
#include "Position.h"
#include "Coordinate.h"
#include <vector>
#include<Random.h>

using namespace utility;
using namespace std;

class Apple {
private:
    Coordinate position;


public:
    Apple();
    void createApple(Coordinate topLeft, Coordinate bottomRight);
    Coordinate getPosition();
};