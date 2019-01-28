// netCDF_writing.cpp
#include <vector>
#include <netcdf>
#include <iostream>
#include <rarray>
#include "netCDF_writing.h"

// writes file
using namespace netCDF;


// writes file
int netCDF_write(rarray<int,2>& array_to_print) {
   int nx = array_to_print.extent(0);
   int ny = array_to_print.extent(1);
   int dataOut[nx][ny]; 
   for(int i = 0; i < nx; i++)
       for(int j = 0; j < ny; j++)
             dataOut[i][j] = array_to_print[i][j];
   
   // Create the netCDF file.
   NcFile dataFile("1st.netCDF.nc", NcFile::replace);
   // Create the two dimensions.
   NcDim xDim = dataFile.addDim("x",nx);
   NcDim yDim = dataFile.addDim("y",ny);
   std::vector<NcDim> dims(2);
   dims[0] = xDim;
   dims[1] = yDim;
   // Create the data variable.
   NcVar data = dataFile.addVar("data", ncInt, dims);
   // Put the data in the file.
   data.putVar(&dataOut); // writing all the data in one operation
   // Add an attribute.
   dataFile.putAtt("Creation date:", "27 Jan 2019");
   return 0; 
}

// reads file
// have to get the number of square arrays you put in the write file
int netCDF_read() {
    // Specify the netCDF file. 
    NcFile dataFile("1st.netCDF.nc", NcFile::read);
    
    // Read the two dimensions.
    NcDim xDim = dataFile.getDim("x");
    NcDim yDim = dataFile.getDim("y");
    int nx = xDim.getSize();
    int ny = yDim.getSize();
   // int sq_arrays_num = 
    std::cout << "Our matrix is " << nx << " by " << ny << std::endl;
    int **p = new int *[nx];
    p[0] = new int[nx * ny];
    for(int i = 0; i < nx; i++)
      p[i] = &p[0][i * ny];
      
    // Retrieve the variable named "data"
    NcVar data = dataFile.getVar("data");
    // Put the data in a var.
    data.getVar(p[0]);
   // arranging it like a matrix... maybe 
    for(int i = 0; i < nx; i++) {
      for(int j = 0; j < ny; j++) {
         std::cout << p[i][j] << " "; 
      }
      std::cout << std::endl;
     }
    return 0; 
}
