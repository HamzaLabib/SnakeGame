#include "Player.h"

Player::Player() : time(Time::getNow()) {
    score = 0;
}

void Player::updateScore(int addScore) {
    score += addScore;
}

int Player::getScore() {
    return score;
}

int Player::getHour() {
    return Time::getHoursBetween(time, Time::getNow());
}

int Player::getMinute() {
    return Time::getMinutesBetween(time, Time::getNow());
}

int Player::getSecond() {
    return Time::getSecondsBetween(time, Time::getNow());
}