#include <iostream>
#include <conio.h> // for _getch() function (Windows only)

void clearScreen() {
    // Clears the console screen
    #ifdef _WIN32
    system("cls");
    #else
    // Assume POSIX
    system("clear");
    #endif
}

void moveDotUp(int &yPos) {
    if (yPos > 0)
        --yPos; // Move dot up
}

void moveDotDown(int &yPos) {
    if (yPos < 10) // Change 10 to whatever maximum limit you want
        ++yPos; // Move dot down
}

void moveDotLeft(int &xPos) {
    if (xPos > 0)
        --xPos; // Move dot left
}

void moveDotRight(int &xPos) {
    if (xPos < 10) // Change 10 to whatever maximum limit you want
        ++xPos; // Move dot right
}

int main() {
    int xPos = 0; // Initial x position of the dot
    int yPos = 0; // Initial y position of the dot

    char input;
    do {
        clearScreen(); // Clear the screen before printing the dot

        // Print the dot at current position
        for (int i = 0; i < yPos; ++i)
            std::cout << std::endl; // Move cursor down
        for (int j = 0; j < xPos; ++j)
            std::cout << " "; // Move cursor right
        std::cout << "o\n";

        // Get user input
        input = _getch(); // Use _getch() for single character input (Windows only)

        // Move the dot based on arrow keys
        switch (input) {
            case 72: // Up arrow key
                moveDotUp(yPos);
                break;
            case 80: // Down arrow key
                moveDotDown(yPos);
                break;
            case 75: // Left arrow key
                moveDotLeft(xPos);
                break;
            case 77: // Right arrow key
                moveDotRight(xPos);
                break;
        }
    } while (input != 'q'); // 'q' to quit

    return 0;
}
