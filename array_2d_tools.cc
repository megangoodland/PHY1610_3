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
using namespace std;


// distribute_on_array: distributes total number given evenly on 2D array
int* distribute_on_array(int total, int len, int in_out_array[]){ //int* is a pointer to the first val in array
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            int n = i*len + j; // linear index
            in_out_array[n] = ((long long)(n+1)*total)/(len*len) - ((long long)(n)*total)/(len*len);
        }
    }
    return in_out_array;
}

// count_min_max: counts values in 2d array and determines minimum and maximum values
std::tuple<int,int,int> count_min_max(int total, int len, int array_2d[]){
    int nmin = total;
    int nmax = 0;
    total = 0;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            int n = i*len + j; // linear index
            total += array_2d[n];
            if (nmin > array_2d[n]) {
                nmin = array_2d[n];
            }
            if (nmax < array_2d[n]) {
                nmax = array_2d[n];
            }
        }
    }
    return std::make_tuple(total, nmin, nmax);
}

// clear_array: empty initialized 2d array
int* clear_array(int len, int array_to_clear[]){
    for (int i = 0; i < len;i++) {
        for (int j = 0; j < len;j++) {
            int n = i*len + j; // linear index
            array_to_clear[n] = 0;
        }
    }
    return array_to_clear;
}

// copy array: copy and paste arrays
int* copy_array(int len, int array_to_copy[], int array_to_paste[]){
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            int n = i*len + j; // linear index
            array_to_paste[n] = array_to_copy[n];
        }
    }
    return array_to_paste;
}
