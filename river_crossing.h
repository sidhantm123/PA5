#ifndef RIVER_CROSSING_H
#define RIVER_CROSSING_H

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    int r1, c1, r2, c2;
} Board;

int getM();
void setM(int value);
int getN();
void setN(int value);
int getBoardValue(int row, int col);
void setBoardValue(int row, int col, int value);

Board getSolution(int index);
int getSolutionCount();
void clearSolution();

void readInput(const char *filename);
int solve(int row, int col);

#endif /* RIVER_CROSSING_H */
