#include <iostream>

using namespace std;
bool gameRunning = true;
int score;
int width = 50;
int height = 50;
int x;
int y;
int foodX;
int foodY;

enum snakeDirection {
    STATIONARY = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
snakeDirection direction;


void Input() {

}

void Draw() {

}

void Setup() {
    gameRunning = true;
    score = 0;
    direction = STATIONARY;
    // snake in middle
    x = width / 5;
    y = height / 5;
    foodX = rand() % width;
    foodY = rand() % height;

}

void GameLogic() {

}

int main() {
    Setup();
    while (gameRunning) {
        GameLogic();
        Draw();
        Input();

    }
    cout << "Snake Game" << std::endl;
    return 0;
}