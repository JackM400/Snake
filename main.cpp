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
    //target design
    //  ^^^^^^^^^^^^^
    //  ^           ^
    //  ^           ^
    //  ^^^^^^^^^^^^^
    system("cls");\
    //make screen
    //width
    for (int i = 0; i < width; i++) {
        cout << "^"; //top
    }

    //game screen
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) {
                cout << "|";
            } else {
                cout << " ";
            }

            if (j == width) {
                cout << "|";
            }

        }
    }

    cout << endl;
    for (int i = 0; i < width; i++) {
        cout << "^"; //bottom
    }


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
        gameRunning = false;
        _sleep(10);

    }
    cout << "Snake Game" << std::endl;
    return 0;
}