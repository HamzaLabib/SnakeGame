#include "GameManger.h"

//constructor initializes all variables.
GameManager::GameManager() : topLeft(1,1),
bottomRightMap(width-2, height-1),
bottomRight(width, height),
snakePosition(width / 2, height / 2),
m(topLeft, bottomRightMap),
s(Coordinate(width / 2, height /2 ), 1)
{
    this->a.createApple(topLeft, bottomRightMap);
}

//checks whether snake ate itself or hit the walls
bool GameManager::loosingConditions()
{
    if (!s.inMap(topLeft, bottomRightMap)) {
        return true;
    }
    if (s.inSnake()) {
        return true;
    }
    return false;
}

//draws on the console
void GameManager::draw() {
    //get snake head and previous tail pos
    snakePosition = s.getHead();
    Coordinate snakeTail = s.getTail();
    //get apple pos
    Coordinate applePosition = a.getPosition();
    //get all snake coordinates and store in a vector
    vector<utility::Coordinate> snakeBody = s.getSnake();
    //window size
    cw.setWindowSize(width, height);
    //print score, length and time
    int score = p.getScore();
    cw.setCursorPosition(5, 0);
    cw.write("SCORE  " + Strings::integerToString(score) +
        "            LENGTH  " + Strings::integerToString(snakeBody.size()) +
        "        TIME  " + Strings::integerToString(p.getHour()) + ":" +
        Strings::integerToString(p.getMinute()) + ":" +
        Strings::integerToString(p.getSecond()));

    //draw map boundaries
    cw.drawRectangle(topLeft, bottomRightMap);
    //in the snake's previous position insert a space
    cw.setCharacterAtPosition(snakeTail.X, snakeTail.Y, ' ');
    //draw a = at snakes head position
    cw.setCharacterAtPosition(snakePosition.X, snakePosition.Y, '=');
    //draw X at apple positioin
    cw.setCharacterAtPosition(applePosition.X, applePosition.Y, 'X');
    //draw the snake's body other than the head
    for (int k = 0; k < snakeBody.size()-1; k++) {
        cw.setCharacterAtPosition(snakeBody[k].X, snakeBody[k].Y,'O');
    }
}

//method checks for keys pressed and sets the direction accordingly
void GameManager::controlSnake()
{
    if (cr.isUpArrowPressed())
    {
        s.setDirection(1);
    }
    else if (cr.isRightArrowPressed())
    {
        s.setDirection(2);
    }
    else if (cr.isDownArrowPressed())
    {
        s.setDirection(3);
    }
    else if (cr.isLeftArrowPressed())
    {
        s.setDirection(4);
    }
    else if (cr.isEscapePressed()||cr.isReturnPressed())
    {
        exit(0);
    }
    //keep moving the snake
    s.moveSnake();
}

//method which returns if the snake ate an apple
bool GameManager::isEatApple()
{
    if (s.eatApple(a.getPosition()))
    {
        p.updateScore(1); //update score if the apple is eaten and
        a.createApple(topLeft,bottomRightMap); //create a new apple and 
        s.growSnake();// grow the snake
        return true;
    }
    return false;
}

//message to display when game is over
void GameManager::displayGameOver() {
    cw.setCursorPosition(width / 2 - 15, height / 2 +1);
    cw.write("GAME OVER!! Press Enter to exit...");
    cw.pause();
}

//method to clear console
void GameManager::clear()
{
    cw.clear();
}
