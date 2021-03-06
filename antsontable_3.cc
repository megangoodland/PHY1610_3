// antsontable_3.cc

// Simulation of ants walking on a table. The table is subdivided into
// squares. A number of ants is initially put on the table, divided as
// evenly as possible over the squares.  Ants can move to a
// neighbouring square or stay put at every time step.  How many of a
// square's ants move in each of the 9 different directions is random
// (using c++11's random library).  Ants can fall of the edges of the
// table. The program prints the number of ants left on the table
// after every time step, as well as the minimum number of ants on a
// square and the maximum.
//
// Compile with:
//
//     make
//
// On the clusters, it will be necessary to load the gcc, hdf5, and netcdf modules first.
//
// Run with
//
//     ./antsontable3 > output.dat
//
// This saves the output to the file output.dat instead of writing it to
// screen.
//
// Ramses van Zon, SciNet, University of Toronto
// January 2019

#include <iostream>
#include <random>
#include <tuple>
#include <algorithm>
#include <rarray>
#include <rarrayio>
#include "random_partition.h"
#include "report_4_integers.h"
#include "array_2d_tools.h"
#include "ants_move_once.h"
#include "netCDF_writing.h"
using namespace std;

// Main driver function of antsontable.cc
int main(){

    // parameters
    int    length     = 70;     // length of the table 70
    int    time_steps = 10000;  // number of time steps to take 10000
    int    total_ants = 40000;  // initial number of ants
    int    when_to_save = 1000; // going to save the ant positions every _____ timesteps
    
    // work arrays
    rarray<int,2> number_of_ants(length,length);     // distribution of ants on the table over squares.
    rarray<int,2> new_number_of_ants(length,length); // auxiliary array used in time step to hold the new distribution of ants
    int nmin = total_ants;                 // will hold the minimum number of ants on any square
    int nmax = 0;                          // will hold the maximum number of ants on any square
    
    // want to save the number of ants on the table every when_to_save timesteps
    int nsaves = time_steps/when_to_save;
    int ny = nsaves*length;
    rarray<int,2> number_of_ants_1000(length,ny); // will hold the data of number_of_ants array every when_to_save timesteps
    
    // place the ants evenly on the table
    number_of_ants = distribute_on_array(total_ants, number_of_ants);
   
    // count ants and determine minimum and maximum number on a square
    std::tie(total_ants, nmin, nmax) = count_min_max(total_ants, number_of_ants);
    
    // report initial placement
    report_4_ints(0, total_ants, nmin, nmax);
    
    // run time steps

    for (int t = 0; t < time_steps; t++){
        // ants move to a new an auxiliary new 'table'
        // empty auxiliary table first
        new_number_of_ants = clear_array(new_number_of_ants);
        // have the ants move once
        new_number_of_ants = ants_move_once(number_of_ants, new_number_of_ants);
        // update number_of_ants
        number_of_ants = copy_array(new_number_of_ants, number_of_ants);
        // count ants and determine minimum and maximum number on a square
        std::tie(total_ants, nmin, nmax) = count_min_max(total_ants, number_of_ants);
        
        // report
        report_4_ints(t+1, total_ants, nmin, nmax);
        
        // record number_of_ants every 1000 time steps
        if ((t+1) % when_to_save == 0){ // if the time step is divisible by when_to_save value
            int save_number = (t+1)/when_to_save;
            number_of_ants_1000 = append_array(number_of_ants, number_of_ants_1000, save_number);}       
    }
    
    // writing and reading the saved number_of_ants in a netCDF file
    netCDF_write(number_of_ants_1000);   
    netCDF_read();
    
    return 0;
}


