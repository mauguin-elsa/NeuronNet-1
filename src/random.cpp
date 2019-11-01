#include "random.h"




RandomNumbers::RandomNumbers(unsigned long int s)
{ 
	if (s==0) {
		std::random_device rd;
		s = rd();
	}
	
	rng = std::mt19937(s);
}


void RandomNumbers::uniform_double(std::vector<double>& vect, double lower, double upper)
{
	for (auto nombre : vect)
	{
		nombre=uniform_double(lower, upper);
	}
}

    
double RandomNumbers::uniform_double(double lower, double upper)
{
	std::uniform_real_distribution<> distribution(lower, upper);
	return distribution(rng);
}

    
void RandomNumbers::normal(std::vector<double>& vect, double mean, double sd)
{
	for (auto nombre : vect)
	{
		nombre = normal(mean, sd);
	}
}
	
double RandomNumbers::normal(double mean, double sd)
{
	std::normal_distribution<> distribution(mean, sd);
	return distribution(rng);
}

void RandomNumbers::poisson(std::vector<int>& vect, double mean)
{
	for (auto nombre : vect)
	{
		nombre=poisson(mean);
	}
}
    
int RandomNumbers::poisson(double mean)
{
	std::poisson_distribution<int> distribution(mean);
	return distribution(rng);
}

     



