#include <stdio.h>
#include <stdlib.h>
#include "river_crossing.h"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input file> <output file1> <output file2>\n", argv[0]);
        return 1;
    }

    readInput(argv[1]);

    FILE *outFile1 = fopen(argv[2], "w");
    if (!outFile1) {
        printf("Error opening output file 1.\n");
        return 1;
    }

    FILE *outFile2 = fopen(argv[3], "w");
    if (!outFile2) {
        printf("Error opening output file 2.\n");
        fclose(outFile1);
        return 1;
    }

    int turns[MAX_ROWS] = {0};

    for (int i = 0; i < getM(); i++) {
        clearSolution();  // Reset solution count
        int turnsForRow = solve(i, 0);
        turns[i] = turnsForRow;
    }

    // Print the second output file
    for (int i = 0; i < getM(); ++i) {
        fprintf(outFile2, "%d\n", turns[i]);
    }

    // Print the first solution in the first output file
    for (int j = 0; j < getSolutionCount(); j++) {
        Board board = getSolution(j);
        fprintf(outFile1, "(%d,%d)(%d,%d)\n", board.r1, board.c1, board.r2, board.c2);        
    }

    fclose(outFile1);
    fclose(outFile2);

    return 0;
}
