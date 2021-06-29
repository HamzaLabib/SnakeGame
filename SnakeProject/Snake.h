#pragma once
#include "Position.h"
#include "Coordinate.h"
#include <vector>

using namespace utility;
using namespace std;


class Snake {
private:
    const int up = 1;
    const int right = 2;
    const int down = 3;
    const int left = 4;
    vector<Coordinate> coordinates;
    Coordinate head;
    Coordinate tail;
    int length;
    int direction;
    int speed;

public:
    Snake(Coordinate position, int initialSpeed);
    void moveSnake();
    void growSnake();
    void setDirection(int newDirection);

    Coordinate getHead();
    Coordinate getTail();
    vector<Coordinate> getSnake();
    bool inSnake();
    bool inMap(Coordinate topLeft, Coordinate bottomRight);
    bool eatApple(Coordinate applePostion);
};