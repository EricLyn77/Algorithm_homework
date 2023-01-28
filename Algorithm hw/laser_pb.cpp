#include <iostream>
#include <vector>
#include <fstream>
#include "Algorithm hw.h"
using namespace std;

int drone_arrival[5] = { 0,1,10,10,1 };
int protect_function[5] = { 0,1,2,4,8 };


void main()
{
	laser();
}

int laser()
{
	int M[5] = { 0 };
	int a[5][5];
	fstream laser_output;
	laser_output.open("laser_pb_out.txt", ios::out | ios::trunc);
	laser_output << "1st" << "  " << "2nd" << "  " << "3rd" << "  " << "4th" << endl;
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 0; j < i; j++)
		{
			a[i][j] = ((drone_arrival[i] < protect_function[i - j]) ? drone_arrival[i] : protect_function[i - j]);
		}
	}
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 0; j < i; j++)
		{
			int temp;
			temp = (((a[i][j] + M[j]) > M[i - 1]) ? (a[i][j] + M[j]) : M[i - 1]);
			if (temp > M[i])
				M[i] = temp;
		}
		laser_output << "  " << M[i] << "  ";
	}
	laser_output << endl;
	laser_output << "----------------------------------------------" << endl;
	laser_output << "Max drones harmless are: " << M[4];

	return M[4];
}