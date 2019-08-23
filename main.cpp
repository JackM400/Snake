#include <iostream>
bool gameRunning = true;
void Input() {

}

void Draw() {

}

void Setup() {
    gameRunning = true;
}

void GameLogic() {

}

int main() {
    Setup();
    while(gameRunning){
        GameLogic();
        Draw();
        Input();

    }
    std::cout << "Snake Game" << std::endl;
    return 0;
}