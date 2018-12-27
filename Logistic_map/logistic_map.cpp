//Logistic map program
//Code by Diogo Ribeiro
//Lisbon , 4th of June 2018

/*Libraries*/
#include <iostream>
#include <fstream>
#include <cmath>

//Logistic  Function
double logistic_function(double r , double xn)
{
	return r*xn*(1-xn);
}

/*Main Function*/int main (int argc , char** argv)
{
	//Variables
	double r ;
	double x0;
	double dr;
	int i_max = 500;

	//Initial conditions
	r = -2;
	dr = 0.001;	
	
	//File to be writen
	std::ofstream f1;
	f1.open("logistic.txt");
	
	while(r < 4)
	{
		x0 = 0.5;
		//Stabilization Period
		for(int i=0 ; i < i_max ; i++)
		{
			x0 = logistic_function(r,x0);
		}
		
		//Orbit Period
		double x1 = x0;
		
		for(int j=0 ; j < 512 ; j++)
		{
			f1 << r << '\t' << j << '\t' << x0 << '\n';
			
			x0 = logistic_function(r,x0);
		
			if( fabs(x0 - x1) < 1e-6) break;
		}
		r+=dr;
	}
	f1.close();
	return 0;
}
