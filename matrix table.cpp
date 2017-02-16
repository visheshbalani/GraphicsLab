#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>

using namespace std;

const float pi = 3.1412;

void multiply(float A[][3], float B[][3], float C[][3]) 
{
	int N = 3, M = 3;
	for(int i = 0; i<N; i++)
		{
			for(int j = 0; j < M; j++)
			{
					C[i][j] = 0;
					for(int k = 0; k < 3; k++)
						C[i][j] += A[i][k] * B[k][j];
					cout<<setw(7)<<C[i][j]<<" ";
			}
			cout<<"\n";
		}
	cout<<"\n\n";
}

void display(float A[][3], int n) 
{
	for(int i = 0; i < n; i ++)
		{
			for(int j = 0; j< 3; j++)
				{cout<<setw(7)<<A[i][j]<<" ";}
			cout<<"\n";
		}
	cout<<"\n\n";
}

int main() {
	//int angle = 45;
	float x; 
	float a[3][3] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
	float b[3][3] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
	float obj[3][3] = {0, 70, 50, 0, 20, 90, 1, 1, 1};
	float c[3][3], rot[3][3];
	//multiply(a,b,c);
	cout<<"Original coordinates: \n";
	display(obj, 2);
	for(int angle = 15; angle <= 360; angle+=15)
		{x = pi/180 * angle;
		float rot[3][3] = {cos(x), -sin(x), 0, sin(x), cos(x), 0, 0, 0, 1};
	/*
	cout<<"Multiplier matrix: \n";
	display(rot, 3);
	cout<<"Coordinates matrix: \n";
	display(obj, 3);
	cout<<"Matrix after multiplication: \n";
	*/
		cout<<"Rotated coordinates: "<<angle<<": \n";
		multiply(rot, obj, c);
		
	}
	return 0;
}