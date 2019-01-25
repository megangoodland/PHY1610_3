//  file   ants_move_once.h
//  author PHYS1610
//  date   2019-01-19.
//  brief  Module for moving ants from initialized 2d square array randomly (stay, move +1, move -1) in both directions. Ants that move off array are lost.

#ifndef ants_move_once_h
#define ants_move_once_h

// ants_move_once
// Parameters:
//      input: length
//             number_of_ants      2d square array of current position of ants
//             new_number_of_ants  empty 2d square array of same size to save new ant position
//      output: updated new_number_of_ants
int* ants_move_once(int length, int number_of_ants[], int new_number_of_ants[]);

#endif /* ants_move_once_h */
