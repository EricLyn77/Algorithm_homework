#include <iostream>
#include <vector>
#include <fstream>
#include "Algorithm hw.h"
using namespace std;

int drone_arrival[5] = { 0,1,10,10,1 };
int protect_function[5] = { 0,1,2,4,8 };

void main()
{
	laser_pd();
}

void laser_pd()
{
	int M[5] = { 0 };
	int a[5][5];
	int opt[5][5] = { 0 };
	fstream laser_output;
	int choose[5] = { 0 };
	laser_output.open("laser_pd_out.txt", ios::out | ios::trunc);
	vector<char> choose_final;
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
			int choose_it = 0;
			if (((a[i][j] + M[j]) > M[i - 1]))
			{
				temp = a[i][j] + M[j];
				choose_it = 1;
			}
			else
			{
				temp = M[i - 1];
			}
			opt[i][j] = temp;
			if (temp > M[i])
			{
				if (choose_it != 0)
				{
					choose[i] = j;
				}
				M[i] = temp;
			}

		}
	}
	for (int i = 0; i < 5; i++)
	{
		cout << choose[i] << endl;
	}
	int b = 4;
	if (choose[b] != 0)
	{
		choose_final.push_back('Y');
	}
	for (int i = 1; i < 4; i++)
	{
		b = choose[b];
		if (4 - i == b)
		{
			choose_final.push_back('Y');
		}
		else
		{
			choose_final.push_back('N');
		}
	}
	laser_output << "----------------------------------------------" << endl;
	laser_output << "    Time    " << "1st" << "  " << "2nd" << "  " << "3rd" << "  " << "4th" << endl;
	laser_output << "use or not" << "   ";
	for (int i = 0; i < choose_final.size(); i++)
	{
		laser_output << choose_final[choose_final.size() - i - 1] << "    ";
	}

}