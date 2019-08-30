#include <iostream>
#include <synchapi.h>
#include <conio.h>


//TODO
// correct input problem,
// write score to file ,
// option for retry

const int MAXLENGTH = 100;
using namespace std;
bool gameRunning = true;
int score;

int width = 20;
int height = 20;

int snakeX;
int snakeY;
int foodX;
int foodY;

int tailSize = 0;
int tailX[MAXLENGTH];
int tailY[MAXLENGTH];

enum snakeDirection {
    STATIONARY = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
snakeDirection direction;


void Input() {
    if (_kbhit()) {
        switch (_getch()) {
            //quit / pause
            case 'p':
                gameRunning = false;
                break;
                //up
            case 'w':
                direction = UP;
                break;
                //down
            case 's':
                direction = DOWN;
                break;
                //left
            case 'a':
                direction = LEFT;
                break;
                //right
            case 'd':
                direction = RIGHT;
                break;
        }
    }
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
            if (j == 0) {
                cout << " < "; //L.side
            }
            //Game Screen
            if (j == snakeX && i == 7) {
                cout << "O "; //snake head
            } else if (j == foodX && i == foodY) {
                cout << "* "; //FOOD [* . ,]
            } else {
                bool isDrawTail = false; //check if tail is drawn at position [i,j] ,if true add tail icon ,
                // if not draw blank space
                for (int n = 0; n < tailSize; n++) {   //loop through screen ,
                    // if their is a tail element at co-ordinate , draw
                    if (tailX[n] == j && tailY[n] == i) {
                        cout << "o";
                        isDrawTail = true;
                    }
                }
                if (!isDrawTail) {
                    cout << "  ";
                }
            }
            if (j == width - 1)
                cout << " > "; //R.side
        }
        cout << endl;
    }

    for (int i = 0; i < width + 3; i++)
        cout << " ^"; //bottom
    cout << endl;
    cout << "Score: " << score << endl;

}

void Setup() {
    direction = STATIONARY;
    // snake in middle
    snakeX = width / 5;
    snakeY = height / 5;
    foodX = rand() % width;
    foodY = rand() % height;
    gameRunning = true;
    score = 0;
}

void GameLogic() {
    //previous co-ordinates of tail (end)
    int prevTailX = tailX[0];
    int prevTailY = tailY[0];
    int prevTailX_2;
    int prevTailY_2;
    //set initial tail position
    tailX[0] = snakeX;
    tailY[0] = snakeY;
    //update tail positions
    for (int i = 0; i < tailSize; i++) {
        prevTailX_2 = tailX[i];
        prevTailY_2 = tailY[i];
        tailX[i] = prevTailX;
        tailY[i] = prevTailY;
        prevTailX = prevTailX_2;
        prevTailY = prevTailY_2;
    }

    //if hit tail section,
    // if snake head is in same position as any tail
    for (int i = 0; i < tailSize; i++) {
        if (snakeX == tailX[i] && snakeY == tailY[i]) { // if in same coordinates
            gameRunning = false;
        }
    }

    switch (direction) {
        case UP:
            snakeY++;
            break;
        case DOWN:
            snakeY--;
            break;
        case LEFT:
            snakeX--;
            break;
        case RIGHT:
            snakeX++;
            break;
        case STATIONARY:
            break;
    }
    //hit boarder
    if (snakeX < 0 || snakeX > width || snakeY < 0 || snakeY > height) {
        cout << "GAME OVER";
        gameRunning = false;
    }
    //eat food
    if (snakeX == foodX && snakeY == foodY) {
        tailSize++;
        score += 5;
        foodX = rand() % width;
        foodY = rand() % height;
    }
}

int main() {
    Setup();
    while (gameRunning) {
        GameLogic();
        Input();
        Draw();
        gameRunning = false;
        Sleep(10);
    }
    cout << "Snake Game" << std::endl;
    return 0;
}