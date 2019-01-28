
# Makefile for antsontable3

# Define the compiler to use
CXX = g++

#all: antsontable3

antsontable3: antsontable_3.o random_partition.o report_4_integers.o array_2d_tools.o ants_move_once.o netCDF_writing.o
	${CXX} -std=c++11 -O3 -march=native antsontable_3.o random_partition.o report_4_integers.o array_2d_tools.o ants_move_once.o netCDF_writing.o -o antsontable3 -lnetcdf_c++4

antsontable_3.o: antsontable_3.cc
	${CXX} -std=c++11 -O3 -march=native -c antsontable_3.cc

random_partition.o: random_partition.cc random_partition.h 
	${CXX} -std=c++11 -O3 -march=native -c random_partition.cc

report_4_integers.o: report_4_integers.cc report_4_integers.h 
	${CXX} -std=c++11 -O3 -march=native -c report_4_integers.cc

array_2d_tools.o: array_2d_tools.cc array_2d_tools.h 
	${CXX} -std=c++11 -O3 -march=native -c array_2d_tools.cc

ants_move_once.o: ants_move_once.cc ants_move_once.h 
	${CXX} -std=c++11 -O3 -march=native -c ants_move_once.cc
	
netCDF_writing.o: netCDF_writing.cpp netCDF_writing.h
	${CXX} netCDF_writing.cpp -c -o netCDF_writing.o -c

clean:
	rm *.o antsontable3
