#include "GameManger.h"
#include <Windows.h>
using namespace std;

int main() {
    bool gameOver = false;
    GameManager g = GameManager();
   while (!gameOver) {
       //g.clear();
       g.draw();
       
       
       g.controlSnake();
       gameOver=g.loosingConditions();
       g.isEatApple();
      // SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
       Sleep(100);
   }
   g.displayGameOver();
   return 0;
}