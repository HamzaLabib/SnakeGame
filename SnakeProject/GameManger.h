#pragma once
#include "Position.h"
#include "Coordinate.h"
#include "Apple.h"
#include "Player.h"
#include "Snake.h"
#include "Map.h"
#include "ConsoleWriter.h"
#include "ConsoleReader.h"

#include <vector>

using namespace utility;
using namespace std;

class GameManager {
private:
    const int width = 100;
    const int height = 40;
    Apple a;
    Player p;
    Map m;
    Snake s;
    ConsoleWriter cw;
    ConsoleReader cr;
    Coordinate topLeft;
    Coordinate bottomRightMap;
    Coordinate bottomRight;
    Coordinate snakePosition;

public:
    GameManager();
    bool loosingConditions();
    void draw();
    void controlSnake();
    bool isEatApple();
    void displayGameOver();
    void clear();
};