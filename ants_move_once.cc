//  ants_move_once.cc
//  
//
//  Created by Megan Goodland on 2019-01-19.
//
#include "ants_move_once.h"
#include <stdio.h>
#include <random>
#include "random_partition.h"
#include <tuple>
#include <iostream>

// ants_move_once function: have ants move into auxiliary table
int* ants_move_once(int length, int number_of_ants[], int new_number_of_ants[]){
    size_t seed       = 11;     // seed for random number generation
    const int nmoves = 9; // There are (3 in the i direction)x(3 in the j direction)=9 possible moves
    const int* imoves = new int[nmoves] {-1,-1,-1, 0, 0, 0, 1, 1, 1}; // Effect of each move on the i direction
    const int* jmoves = new int[nmoves] {-1, 0, 1,-1, 0, 1,-1, 0, 1}; // Effect of each move on the j direction
    int* partition = new int[nmoves];                 // used to determine how many ants move in which direction in a time step
    for (int i = 0; i < length;i++) {
        for (int j = 0; j < length;j++) {
            int n = i*length + j; // linear index
            if (number_of_ants[n] > 0 ) {
                // pick how many ants go in each of the 9 moves
                rand_partition(number_of_ants[n], nmoves, partition, seed);
                // push ants in their respective moves
                for (int m = 0; m < nmoves; m++) {
                    int i2 = i + imoves[m];
                    int j2 = j + jmoves[m];
                    // put only on new table if not falling off table
                    if (i2>=0 and i2<length and j2>=0 and j2<length) {
                        int n = i2*length + j2; // linear index
                        new_number_of_ants[n] += partition[m];
                    }
                }
            }
        }
    }
    delete[] imoves;
    delete[] jmoves;
    delete[] partition;
    return new_number_of_ants;
}

