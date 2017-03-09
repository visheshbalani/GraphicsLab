#include <iostream>
#include <algorithm>

using namespace std;

struct point {
	int x, y;
};

struct edge {
	int xmax, xmin, y_xmin;
	float dy, dx, m;
};

struct edge1 {
	edge es;
	int logical;
};

int main()
{
	int Number_of_Vertices;
	cout<<"Enter number of vertices: ";
	cin>>Number_of_Vertices;
	
	point poly[10];
	edge e[10];
	edge1 e2[10];

	cout<<"Enter coordinates: ";
	for (int j = 0; j < Number_of_Vertices; j++)
	{
		cin>>poly[j].x>>poly[j].y;
	}

	
	for(int i = 0; i < Number_of_Vertices-1; i++)
		{
			e[i].dy = poly[i+1].x - poly[i].x;
			e[i].dx = poly[i+1].y - poly[i].y;
			e[i].m = e[i].dy/e[i].dx;
		if(poly[i].x > poly[i+1].x)
			{
				e[i].xmax = poly[i].x;
				e[i].xmin = poly[i+1].x;
				e[i].y_xmin = poly[i+1].y;
			}
		else
			{
				e[i].xmax = poly[i+1].x;
				e[i].xmin = poly[i].x;
				e[i].y_xmin = poly[i].y;	
			}
		}

	int n = Number_of_Vertices;
	
	e[n-1].dy = poly[0].x - poly[n-1].x;
	e[n-1].dx = poly[0].y - poly[n-1].y;
	e[n-1].m = e[n-1].dy/e[n-1].dx; 
	if(poly[n-1].x > poly[0].x)
			{
				e[n-1].xmax = poly[n-1].x;
				e[n-1].xmin = poly[0].x;
				e[n-1].y_xmin = poly[0].y;
			}
	else
			{
				e[n-1].xmax = poly[0].x;
				e[n-1].xmin = poly[n-1].x;
				e[n-1].y_xmin = poly[n-1].y;	
			}
	cout<<"xmax y_xmin dy dx m :"<<endl;
	for(int i = 0; i <Number_of_Vertices; i++)
	{
		cout<<e[i].xmax<<" "<<e[i].y_xmin<<" "<<e[i].dy<<" "<<e[i].dx<<" "<<e[i].m<<endl;
	}
}