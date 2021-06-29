#include "Snake.h"
#include "Coordinate.h"
#include <vector>

using namespace utility;
using namespace std;

//constructor
Snake::Snake(Coordinate position, int initialSpeed) : head(position),tail(position) {//written by ashif
    speed = initialSpeed;
    direction = 0;
    coordinates.push_back(head);
    coordinates.push_back(Coordinate(head.X-1,head.Y));
    coordinates.push_back(Coordinate(head.X-2, head.Y));
    length = coordinates.size();
    tail =Coordinate(head.X - 3, head.Y);
}

void Snake::setDirection(int newDirection) {
    direction = newDirection;
}

void Snake::moveSnake() {
    if (direction == up)
        head.Y -= speed;
    else if (direction == down)
        head.Y += speed;
    else if (direction == left)
        head.X -= speed;
    else
        head.X += speed;

    //modify head and add it to the snake and delete the tail 
    coordinates.push_back(head);
    if (coordinates.size() > length)
    {
        tail = coordinates[0];
        coordinates.erase(coordinates.begin());
    }
   
}

void Snake::growSnake() {
    length++;
}

Coordinate Snake::getHead() {
    return head;
}
Coordinate Snake::getTail()
{
    return tail;
}
vector<Coordinate> Snake::getSnake() {
    return coordinates;
}


bool Snake::inSnake() {
    for (int i = 0; i < coordinates.size()-1; i++) {
        //if the head coordinates and any other body coordinates are the same
        if (head.X == coordinates[i].X && head.Y == coordinates[i].Y) {
            return true;
        }
    }
    return false;
}

bool Snake::inMap(Coordinate topLeft, Coordinate bottomRight) {
    //if the head is out of the map
    if (head.X > bottomRight.X-1 || head.X < topLeft.X+1 || head.Y>bottomRight.Y-1 || head.Y<topLeft.Y +1) {
        return false;
    }
    return true;
}

bool Snake::eatApple(Coordinate applePosition) {
    //if the head and apple pos are the same
    if (head.X == applePosition.X && head.Y == applePosition.Y) {
        return true;
    }
    return false;
}
