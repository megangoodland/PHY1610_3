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

// append_array: adds square array to holding array with size that is multiple of square array dimension size. 
// Parameters:
//      inputs:   holding array, addition array, and which position within holding array to place additiona array (mult)
//      output:   holding array with addition added
rarray<int,2> append_array(rarray<int,2>& addition_array, rarray<int,2>& holding_array, int mult){

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
