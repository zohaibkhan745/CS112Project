#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

const int Width = 50;
const int Height = 30;

class MazeGame {
private:
    struct Position {
        int x;
        int y;
    };

    Position playerPos;
    Position destPos;

public:
    MazeGame() : playerPos({2, 2}), destPos({2, Height - 2}) {}

    void start() {
        system("mode con: lines=40 cols=70");
        hideCursor();

        showInstructions();
        system("pause");
        system("cls");

        drawScreen();
        drawMaze();
        drawPositions();

        playGame();
    }

private:
    void hideCursor() {
        HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO cursorInfo;
        GetConsoleCursorInfo(consoleHandle, &cursorInfo);
        cursorInfo.bVisible = false;
        SetConsoleCursorInfo(consoleHandle, &cursorInfo);
    }

    void showInstructions() {
        gotoxy(0, Height / 2 - 3);
        cout << "<<<<< Instruction >>>>>:" << endl;
        cout << "************************" << endl;
        cout << "Use Arrow keys (Left,Right,Up,Down) for move:" << endl;
        cout << endl;
    }

    void drawScreen() {
        for (int i = 0; i < Width; i++) {
            gotoxy(i, 0);
            cout << "#";
            gotoxy(i, Height - 1);
            cout << "#";
        }

        for (int i = 1; i < Height - 1; i++) {
            gotoxy(0, i);
            cout << "#";
            gotoxy(Width - 1, i);
            cout << "#";
        }
    }

    void drawMaze() {
        // Draw the maze pattern
        for (int i = 0; i < Width - 4; i++) {
            gotoxy(i + 1, 3);
            cout << "*";
        }

        // Add more maze patterns as needed
    }

    void drawPositions() {
        gotoxy(playerPos.x, playerPos.y);
        cout << "@";

        gotoxy(destPos.x, destPos.y);
        cout << "()";
    }

    void movePlayer(char key) {
        Position newPos = playerPos;

        if (key == 80) {
            newPos.y++;
        } else if (key == 72) {
            newPos.y--;
        } else if (key == 77) {
            newPos.x++;
        } else if (key == 75) {
            newPos.x--;
        }

        if (!checkCollision(newPos)) {
            gotoxy(playerPos.x, playerPos.y);
            cout << " ";

            playerPos = newPos;

            drawPositions();
        }
    }

    bool checkCollision(const Position& newPos) {
        if (newPos.x <= 0 || newPos.x >= Width - 1 ||
            newPos.y <= 0 || newPos.y >= Height - 1)
            return true;

        return false;
    }

    bool checkWin() {
        if (playerPos.x == destPos.x && playerPos.y == destPos.y)
            return true;
        return false;
    }

    void playGame() {
        while (true) {
            if (_kbhit()) {
                char key = _getch();
                movePlayer(key);
            }

            if (checkWin())
                break;
        }

        gotoxy(2, Height + 1);
        cout << "Congratulations! You reached the destination!" << endl;
    }

    void gotoxy(int x, int y) {
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }
};

int main() {
    MazeGame game;
    game.start();
    return 0;
}
