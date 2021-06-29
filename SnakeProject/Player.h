#pragma once
#include "Position.h"
#include "Coordinate.h"
#include <vector>
#include "Time.hh"

using namespace utility;
using namespace std;

class Player {
private:
    int score;
    Time time;

public:
    Player();
    void updateScore(int addScore);
    int getScore();
    Time getTime();
    int getHour();
    int getMinute();
    int getSecond();
};