#include <iostream>
#include <cstdlib>
#include <ctime>

const int WIDTH = 10;   // Width of the maze
const int HEIGHT = 10;  // Height of the maze

int main() {
    srand(time(nullptr)); // Seed for random number generation

    // Generate the maze
    char maze[HEIGHT][WIDTH];
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            // Place walls ('#') randomly
            if (rand() % 5 == 0) {
                maze[y][x] = '#';
            } else {
                maze[y][x] = ' ';
            }
        }
    }

    // Place the starting point ('S') at the top-left corner
    maze[0][0] = 'S';

    // Place the ending point ('E') at the bottom-right corner
    maze[HEIGHT - 1][WIDTH - 1] = 'E';

    // Display the maze
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            std::cout << maze[y][x] << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}
