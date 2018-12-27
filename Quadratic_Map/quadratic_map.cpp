//Quadratic map program
//Code by Diogo Ribeiro
//Lisbon , 6th of June 2018

/*Libraries*/
#include <iostream>
#include <fstream>
#include <cmath>

//Tent  Function
double tent_function(double nu , double xn)
{
	return (xn < 0.5) ? nu*xn : nu*(1-xn);
}

//Quadratic map
int quadratic_map(double* pn, double* ax , double* ay)
{
	double ps[2];

	ps[0] = pn[0];
	ps[1] = pn[1];

	pn[0] = ax[0] + ax[1]*ps[0] + ax[2]*ps[0]*ps[0] + ax[3]*ps[0]*ps[1] + ax[4]*ps[1] + ax[5]*ps[1]*ps[1];	
	pn[1] = ay[0] + ay[1]*ps[0] + ay[2]*ps[0]*ps[0] + ay[3]*ps[0]*ps[1] + ay[4]*ps[1] + ay[5]*ps[1]*ps[1];	
	
	return 0;
}

/*Main Function*/
int main (int argc , char** argv)
{
	//Variables
	double ax[6];	//Coefficient vector for x equation
	double ay[6];	//Coefficient vector for y equation

	double p[2];	//Phase space vector

	int i_max = 50000;

	//Read coeeficients from file
	std::ifstream f1;
	f1.open("cof.txt");
	for(int i = 0 ; i < 6 ; i++)	f1 >> ax[i];	
	for(int i = 0 ; i < 6 ; i++)	f1 >> ay[i];	
	f1.close();

	//File to write
	std::ofstream f2;
	f2.open("quadratic.txt");

	//Iteration Cycle
	p[0] = 0.1;
	p[1] = 0.5;

	for(int i=0 ; i < i_max ; i++)
	{
		f2 << i << '\t' << p[0] << '\t' << p[1] << '\n';

		quadratic_map(p , ax , ay);	
	}
	
	return 0;
}
