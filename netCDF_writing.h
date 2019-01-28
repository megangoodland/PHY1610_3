// netCDF_writing.h
// author PHYS1610

#ifndef netCDF_writing_h
#define netCDF_writing_h

// Function to write netCDF file
// Input is a large 2D array (square size x mult of square size) which is a combination of smaller square arrays
int netCDF_write(rarray<int,2>& array_to_print);

// Function to read netCDF file
// Reads netCDF file and formats data in separate small square arrays. The j dimension is output with spaces between,
// the i dimension is output with newlines between. Notes output are custom to antsontable project.
int netCDF_read();

#endif /* netCDF_writing_h */
