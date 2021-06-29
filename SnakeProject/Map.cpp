#include "Map.h"

//default constructor
Map::Map() : topLeft(0, 0), bottomRight(0, 0)
{

}
//parameterized constructor
Map::Map(Coordinate topLeft, Coordinate bottomRight) : topLeft(topLeft), bottomRight(bottomRight)//written by parsa
{

}

//methods to get the corners

Coordinate Map::getBottomRight() {
    return bottomRight;
}

Coordinate Map::getTopLeft() {
    return topLeft;
}