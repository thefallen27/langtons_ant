package main

import "core:raylib"

WINDOW_WIDTH  :: 800
WINDOW_HEIGHT :: 800
CELL_SIZE     :: 10
GRID_WIDTH    :: WINDOW_WIDTH / CELL_SIZE
GRID_HEIGHT   :: WINDOW_HEIGHT / CELL_SIZE

Direction :: enum {
    Up,
    Right,
    Down,
    Left,
}

MoveAnt :: proc(x: ^int, y: ^int, dir: ^Direction, grid: ^[GRID_HEIGHT][GRID_WIDTH]bool) {
    if grid[y^][x^] {
        dir^ = Direction((int(dir^) + 3) % 4) // Turning left
    } else {
        dir^ = Direction((int(dir^) + 1) % 4) // Turning right
    }

    grid[y^][x^] = !grid[y^][x^] // Colour flip

    switch dir^ {
    case .Up:
        y^ = (y^ - 1 + GRID_HEIGHT) % GRID_HEIGHT
    case .Right:
        x^ = (x^ + 1) % GRID_WIDTH
    case .Down:
        y^ = (y^ + 1) % GRID_HEIGHT
    case .Left:
        x^ = (x^ - 1 + GRID_WIDTH) % GRID_WIDTH
    }
}

DrawGrid :: proc(grid: [GRID_HEIGHT][GRID_WIDTH]bool) {
    for y in 0..<GRID_HEIGHT {
        for x in 0..<GRID_WIDTH {
            if grid[y][x] {
                raylib.DrawRectangle(i32(x * CELL_SIZE), i32(y * CELL_SIZE), CELL_SIZE, CELL_SIZE, raylib.RAYWHITE)
            } else {
                raylib.DrawRectangle(i32(x * CELL_SIZE), i32(y * CELL_SIZE), CELL_SIZE, CELL_SIZE, raylib.BLACK)
            }
        }
    }
}

main :: proc() 
{
    steps := 8000 // Number of steps the ant will take

    raylib.InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Langton's Ant")
    defer raylib.CloseWindow()

    raylib.SetTargetFPS(60)

    grid: [GRID_HEIGHT][GRID_WIDTH]bool

    antX := GRID_WIDTH / 2
    antY := GRID_HEIGHT / 2
    antDir := Direction.Up

    for i in 0..<steps {
        MoveAnt(&antX, &antY, &antDir, &grid)

        raylib.BeginDrawing()
        defer raylib.EndDrawing()

        raylib.ClearBackground(raylib.BLACK)

        DrawGrid(grid)

        raylib.DrawRectangle(i32(antX * CELL_SIZE), i32(antY * CELL_SIZE), CELL_SIZE, CELL_SIZE, raylib.RED) // Colour of the ant

        raylib.EndDrawing()
    }
}
