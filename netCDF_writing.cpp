// netCDF_writing.cpp
#include <vector>
#include <netcdf>
using namespace netCDF;
int main() {
int nx = 6, ny = 12;
int dataOut[nx][ny]; for(int i = 0; i < nx; i++)
       for(int j = 0; j < ny; j++)
          dataOut[i][j] = i * ny + j;
   // Create the netCDF file.
   NcFile dataFile("1st.netCDF.nc",
       NcFile::replace);
   // Create the two dimensions.
   NcDim xDim = dataFile.addDim("x",nx);
   NcDim yDim = dataFile.addDim("y",ny);
   std::vector<ncdim> dims(2);
   dims[0] = xDim;
   dims[1] = yDim;
   // Create the data variable.
   NcVar data =
       dataFile.addVar("data", ncInt, dims);
   // Put the data in the file.
   data.putVar(&dataOut);
   // Add an attribute.
   dataFile.putAtt("Creation date:",
       "12 Dec 2014");
return 0; }