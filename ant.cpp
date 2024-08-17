#include <SDL2/SDL.h>
#include <iostream>
#include <vector>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;
const int CELL_SIZE = 10;
const int GRID_WIDTH = WINDOW_WIDTH / CELL_SIZE;
const int GRID_HEIGHT = WINDOW_HEIGHT / CELL_SIZE;

enum Direction { UP, RIGHT, DOWN, LEFT };

void 
MoveAnt(int& x, int& y, Direction& dir, std::vector<std::vector<bool>>& grid)
{
    if (grid[y][x])
    {
        dir = static_cast<Direction>((dir + 3) % 4); // Turning left
    }
    else
    {
        dir = static_cast<Direction>((dir + 1) % 4); // Turning right
    }

    grid[y][x] = !grid[y][x]; // Colour flip

    switch (dir)
    {
    case UP:    y = (y - 1 + GRID_HEIGHT) % GRID_HEIGHT; break;
    case RIGHT: x = (x + 1) % GRID_WIDTH; break;
    case DOWN:  y = (y + 1) % GRID_HEIGHT; break;
    case LEFT:  x = (x - 1 + GRID_WIDTH) % GRID_WIDTH; break;
    }
}

void 
DrawGrid(SDL_Renderer* renderer, const std::vector<std::vector<bool>>& grid)
{
    for (int y = 0; y < GRID_HEIGHT; ++y)
    {
        for (int x = 0; x < GRID_WIDTH; ++x)
        {
            if (grid[y][x])
            {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            }
            else
            {
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            }

            SDL_Rect rect = { x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE };
            SDL_RenderFillRect(renderer, &rect);
        }
    }
}

int main()
{
    int steps;
    std::cout << "Enter the number of steps: ";
    std::cin >> steps;

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("Langton's Ant", SDL_WINDOWPOS_CENTERED,
							SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    std::vector<std::vector<bool>> grid(GRID_HEIGHT, std::vector<bool>(GRID_WIDTH, false));

    int antX = GRID_WIDTH / 2;
    int antY = GRID_HEIGHT / 2;
    Direction antDir = UP;

    for (int i = 0; i < steps; ++i)
    {
        MoveAnt(antX, antY, antDir, grid);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        DrawGrid(renderer, grid);

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Colour of the ant
        SDL_Rect antRect = { antX * CELL_SIZE, antY * CELL_SIZE, CELL_SIZE, CELL_SIZE };
        SDL_RenderFillRect(renderer, &antRect);

        SDL_RenderPresent(renderer);

        SDL_Delay(15); // Simulation speed (refresh rate) in ms
    }

    SDL_Delay(5000); // Window display time in ms

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
