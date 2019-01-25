//  file   random_partition.h
//  author PHYS1610
//  date   2019-01-19.
//  brief  Module for dividing a number into a set of random numbers that add up to it

#ifndef random_partition_h
#define random_partition_h

// Function to randomly divide a number 'total' into a set of
// 'numdivision' numbers that add up to 'total'.
//
// Parameters:
//   total     number that is to be subdivided (input)
//   nparts    number of partitions into which to divide 'total (input)
//   nperpart  resulting number in each partition (output)
//   seed      the seed for the random number generator (input)

void rand_partition(int total, int nparts, rarray<int,1> & nperpart, size_t seed);

#endif /* random_partition_h */
