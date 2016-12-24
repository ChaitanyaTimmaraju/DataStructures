#ifndef RANDOM_H
#define RANDOM_H
 //Returns a random value including min and max
 int getRandom(int min,int max)
 {
 	static const double fraction = 1.0/(static_cast<double>(RAND_MAX)+1.0);
 	return static_cast<int>(rand()*fraction*(max-min+1)+min);
 }
#endif