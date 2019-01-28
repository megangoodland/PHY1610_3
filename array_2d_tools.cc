//  array_2d_tools.cc
//  
//
//  Created by Megan Goodland on 2019-01-19.
//
// Implementation of module for tools to use on a 2d array initialized by a user

#include <stdio.h>

#include "array_2d_tools.h"
#include <iostream>
#include <tuple>
#include <rarray>
using namespace std;

// append_array: adds square array to end of existing array, returns combination
rarray<int,2> append_array(rarray<int,2>& addition_array, rarray<int,2>& old_array){
    int nx = addition_array.extent(0);
    int ny =  addition_array.extent(1) + old_array.extent(1);
    rarray<int,2> new_array(nx,ny); // initialize new array
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < old_array.extent(1); j++) {
            new_array[i][j] = old_array[i][j];
        }
    }
    for (int i = 0; i < nx; i++) {
        for (int j = old_array.extent(1); j < ny; j++) {
            new_array[i][j] = addition_array[i][j];
        }
    }
    return new_array
    
}


// distribute_on_array: distributes total number given evenly on 2D array
rarray<int,2> distribute_on_array(int total, rarray<int,2>& in_out_array){
    int len = in_out_array.extent(0);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            int n = i*len + j; // linear index
            in_out_array[i][j] = ((long long)(n+1)*total)/(len*len) - ((long long)(n)*total)/(len*len);
        }
    }
    return in_out_array;
}

// count_min_max: counts values in 2d array and determines minimum and maximum values
std::tuple<int,int,int> count_min_max(int total, rarray<int,2>& array_2d){
    int len = array_2d.extent(0);
    int nmin = total;
    int nmax = 0;
    total = 0;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            total += array_2d[i][j];
            if (nmin > array_2d[i][j]) {
                nmin = array_2d[i][j];
            }
            if (nmax < array_2d[i][j]) {
                nmax = array_2d[i][j];
            }
        }
    }
    return std::make_tuple(total, nmin, nmax);
}

// clear_array: empty initialized 2d array
rarray<int,2> clear_array(rarray<int,2>& array_to_clear){
    int len = array_to_clear.extent(0);
    for (int i = 0; i < len;i++) {
        for (int j = 0; j < len;j++) {
            array_to_clear[i][j] = 0;
        }
    }
    return array_to_clear;
}

// copy array: copy and paste arrays
rarray<int,2> copy_array(rarray<int,2>& array_to_copy, rarray<int,2>& array_to_paste){
    int len = array_to_copy.extent(0);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            array_to_paste[i][j] = array_to_copy[i][j];
        }
    }
    return array_to_paste;
}
