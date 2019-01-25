// nc_reading2.cpp
#include <iostream>
#include <netcdf>
using namespace netCDF;
int main() {
    // Specify the netCDF file. 
    NcFile dataFile("1st.netCDF.nc", NcFile::read);
    
    // Read the two dimensions.
    ncdim xDim = dataFile.getDim("x");
    ncdim yDim = dataFile.getDim("y");
    int nx = xDim.getSize();
    int ny = yDim.getSize();
    std::cout << "Our matrix is " << nx << " by " << ny << std::endl;
    int **p = new int *[nx];
    p[0] = new int[nx * ny];
    for(int i = 0; i < nx; i++)
      p[i] = &p[0][i * ny];
      
    // Create the data variable.
    NcVar data = dataFile.getVar("data");
    // Put the data in a var.
    data.getVar(p[0]);
  
    for(int i = 0; i < nx; i++) {
      for(int j = 0; j < ny; j++) {
         std::cout << p[i][j] << " "; 
      }
      std::cout << std::endl;
     }
    return 0; 
  }
