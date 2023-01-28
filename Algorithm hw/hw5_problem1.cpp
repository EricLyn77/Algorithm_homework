#pragma once
#include <iostream>
#include <vector>

using namespace std;

void main()
{
	vector<int> A = { 6, 0, 2, 0, 1, 3, 4, 6, 1, 3, 2 };
	reverse_counting_sort(find_vector_range(A), A);
	system("pause");
}

int find_vector_range(vector<int> A)
{
	int max = 0, min = 0;
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i] > max)
		{
			max = A[i];
		}
		if (A[i] < min)
		{
			min = A[i];
		}
	}
	return max - min;
}


void reverse_counting_sort(int range, vector<int>A)
{
	int * C = new int[100];
	int * B = new int[100]{ 0 };

	for (int i = 0; i < range; i++)
	{
		C[i] = 0;
	}
	for (int j = 0; j < A.size(); j++)
	{
		C[A[j]] = C[A[j]] + 1;
	}
	for (int i = range; i >= 0; i--)//count how many elements smaller than this value
	{
		C[i] = 0;
		for (int j = 0; j < i; j++)
		{
			C[i] = C[i] + C[j];
		}
		cout << "there's " << C[i] << " elements smaller than " << i << endl;
		for (int i = 0; i <= range; i++)
		{
			cout << C[i] << " ";
		}
		cout << endl;
	}
	cout << "The final C is:" << endl;
	for (int i = 0; i <= range; i++)
	{
		cout << C[i] << " ";
	}
	cout << endl;
	for (int j = 0; j < A.size(); j++)
	{
		B[C[A[j]]] = A[j];
		C[A[j]] = C[A[j]] + 1;
		cout << "the " << j << "th sort: ";
		for (int a = 0; a < A.size(); a++)
		{
			cout << B[a] << " ";
		}
		cout << endl;
	}
	for (int a = 0; a < A.size(); a++)
	{
		cout << B[a] << " ";
	}
}