//  file   array_2d_tools.h
//  author PHYS1610
//  date   2019-01-19.
//  brief  Functions to be used on a square 2d array initialized in a main code

#ifndef array_2d_tools_h
#define array_2d_tools_h

#include <iostream>
#include <tuple>
#include <rarray>
using namespace std;

// append_array: adds square array to end of existing array, returns combination
// Parameters:
// inputs: addition_array: the square array to add to the end of old_array
//         old_array: the old array
// output: old array with addition array tacked on the end in the second dimension
rarray<int,2> append_array(rarray<int,2>& addition_array, rarray<int,2>& old_array);

// distribute_on_array: distributes total number given evenly on 2D array
// Parameters:
//      inputs: total           number you want divided
//              in_out_array    initialized 2D square array
//      output: updated version of given 2D square array with total number distributed evenly
rarray<int,2> distribute_on_array(int total, rarray<int,2>& in_out_array);

// count_min_max: counts values in 2d array and determines minimum and maximum values
// Parameters:
//      inputs: total      sum of all values in array
//              array_2d   initialized 2D square array
//      outputs: total     sum of all values in array
//               nmin      minimum number of ants on a square
//               nmax      maximum number of ants on a square
std::tuple<int,int,int> count_min_max(int total, rarray<int,2>& array_2d);

// clear_array: empty initialized 2d array
// Parameters:
//      input: array_to_clear[]     array you want cleared
//      output: array_to_clear[], now filled with 0's
rarray<int,2> clear_array(rarray<int,2>& array_to_clear);

// copy array: copy and paste arrays
// Parameters:
//      inputs: array to copy, array to paste
//      outputs: updated pasted array
rarray<int,2> copy_array(rarray<int,2>& array_to_copy, rarray<int,2>& array_to_paste);



#endif /* array_2d_tools */
