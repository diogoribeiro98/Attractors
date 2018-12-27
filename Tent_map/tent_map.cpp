//Tent map program
//Code by Diogo Ribeiro
//Lisbon , 4th of June 2018

/*Libraries*/
#include <iostream>
#include <fstream>
#include <cmath>

//Tent  Function
double tent_function(double nu , double xn)
{
	return (xn < 0.5) ? nu*xn : nu*(1-xn);
}

/*Main Function*/
int main (int argc , char** argv)
{
	//Variables
	double r ;
	double x0;
	double dr;
	int i_max = 500;

	//Initial conditions
	r = 0;
	dr = 0.001;	
	
	//File to be writen
	std::ofstream f1;
	f1.open("tent.txt");
	
	while(r < 2)
	{
		x0 = 0.5;
		//Stabilization Period
		for(int i=0 ; i < i_max ; i++)
		{
			x0 = tent_function(r,x0);
		}
		
		//Orbit Period
		double x1 = x0;
		
		for(int j=0 ; j < 64 ; j++)
		{
			f1 << r << '\t' << j << '\t' << x0 << '\n';
			
			x0 = tent_function(r,x0);
		
			if( fabs(x0 - x1) < 1e-6) break;
		}
		r+=dr;
	}
	f1.close();
	return 0;
}
