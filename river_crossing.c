#include "river_crossing.h"
#include <stdio.h>
#include <stdlib.h>

int M, N;
int board[MAX_ROWS][MAX_COLS];

Board solution[MAX_ROWS * MAX_COLS];
int solutionCount = 0;

int getM() {
    return M;
}

void setM(int value) {
    M = value;
}

int getN() {
    return N;
}

void setN(int value) {
    N = value;
}

int getBoardValue(int row, int col) {
    return board[row][col];
}

void setBoardValue(int row, int col, int value) {
    board[row][col] = value;
}

Board getSolution(int index) {
    return solution[index];
}

int getSolutionCount() {
    return solutionCount;
}

void clearSolution() {
    solutionCount = 0;
}

void addBoard(int r1, int c1, int r2, int c2) {
    solution[solutionCount].r1 = r1;
    solution[solutionCount].c1 = c1;
    solution[solutionCount].r2 = r2;
    solution[solutionCount].c2 = c2;
    solutionCount++;
}

void move(int r1, int c1, int r2, int c2) {
    addBoard(r1, c1, r2, c2);
}

int solve(int row, int col) {
    int turns = 0;
    int dir = 0;  // 0 for vertical, 1 for horizontal

    // Start with a horizontal board at column -1
    move(row, -1, row, 0);

    while (col < N) {
        // Check if a horizontal move is possible
        if (col + 1 < N && !board[row][col + 1]) {
            move(row, col, row, col + 1);
            col++;
            turns++;
            continue;
        }
        
        // Check if a vertical move is possible
        if (row < M - 1 && !board[row + 1][col]) {
            move(row, col, row + 1, col);
            row++;
            dir = 0;  // Reset direction for vertical movement
            turns++;
            continue;
        }
        
        // Check if turning 90 degrees clockwise is possible
        if (dir == 1 && row > 0 && !board[row - 1][col] && !board[row - 1][col + 1]) {
            move(row - 1, col, row, col);
            row--;
            dir = 0;  // Reset direction for vertical movement
            turns++;
            continue;
        }
        
        // Check if turning 90 degrees counter-clockwise is possible
        if (dir == 0 && row < M - 1 && !board[row + 1][col] && !board[row + 1][col + 1]) {
            move(row, col, row + 1, col);
            row++;
            dir = 1;  // Set direction for horizontal movement
            turns++;
            continue;
        }
        
        // If no move is possible, move to the next column
        col++;
    }

    // End with a horizontal board at column N
    move(row, N - 1, row, N);

    return turns;
}

void readInput(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening input file.\n");
        exit(1);
    }

    fscanf(file, "%d %d\n", &M, &N);
    for (int i = 0; i < M - 1; ++i) {
        for (int j = 0; j < N; ++j) {
            fscanf(file, "%1d", &board[i][j]);
        }
        fscanf(file, "\n");  // Consume newline
    }

    fclose(file);
}
