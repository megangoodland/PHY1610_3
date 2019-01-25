//  file   array_2d_tools.h
//  author PHYS1610
//  date   2019-01-19.
//  brief  Functions to be used on a square 2d array initialized in a main code

#ifndef array_2d_tools_h
#define array_2d_tools_h

#include <iostream>
#include <tuple>
using namespace std;

// distribute_on_array: distributes total number given evenly on 2D array
// Parameters:
//      inputs: total           number you want divided
//              len             size of one dimension of array
//              in_out_array[]   initialized 2D square array
//      output: updated version of given 2D square array with total number distributed evenly
int* distribute_on_array(int total, int len, int in_out_array[]);

// count_min_max: counts values in 2d array and determines minimum and maximum values
// Parameters:
//      inputs: total      sum of all values in array
//              len        size of one dimension of array
//              array_2d   initialized 2D square array
//      outputs: total     sum of all values in array
//               nmin      minimum number of ants on a square
//               nmax      maximum number of ants on a square
std::tuple<int,int,int> count_min_max(int total, int len, int array_2d[]);

// clear_array: empty initialized 2d array
// Parameters:
//      input: len                  size of one dimension of array
//             array_to_clear[]     array you want cleared
//      output: array_to_clear[], now filled with 0's
int* clear_array(int len, int array_to_clear[]);

// copy array: copy and paste arrays
// Parameters:
//      inputs: length of one side of array, array to copy, array to paste
//      outputs: updated pasted array
int* copy_array(int len, int array_to_copy[], int array_to_paste[]);



#endif /* array_2d_tools */
