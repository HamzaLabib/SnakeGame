#pragma once
#include "Position.h"
#include "Coordinate.h"

using namespace utility;

class Map {

private:
    Coordinate topLeft;
    Coordinate bottomRight;

public:
    Map();
    Map(Coordinate topLeft, Coordinate bottomRight);
    Coordinate getBottomRight();
    Coordinate getTopLeft();
};