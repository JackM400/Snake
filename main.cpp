#include <iostream>
#include <synchapi.h>

using namespace std;
bool gameRunning = true;
int score;
int width = 20;
int height = 20;
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
    /*
   //target design
   //  ^^^^^^^^^^^^^
   //  ^           ^
   //  ^           ^
   //  ^^^^^^^^^^^^^
    system("cls");\
   //make screen
    //width = height == square screen
     */
    system("cls"); //system("clear");
    for (int i = 0; i < width + 2; i++)
        cout << " ^"; //top
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                cout << " < "; //L.side
            cout << "  ";


            //Game Screen
            if (j == x && i == 7) {
                cout<< "O"; //snake head
            }
            if (j == foodX && i == foodY){
                cout << "*"; //FOOD [* . ,]
            }


            if (j == width - 1)
                cout << " > "; //R.side
        }
        cout << endl;
    }

    for (int i = 0; i < width + 3; i++)
        cout << " ^"; //bottom
    cout << endl;
    cout << "Score:" << score << endl;

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
        Sleep(10);
    }
    cout << "Snake Game" << std::endl;
    return 0;
}