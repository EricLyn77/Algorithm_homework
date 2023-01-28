#pragma once
#include <iostream>
#include <vector>

using namespace std;

void main()
{
	vector<int> A = { 9,6,8,2,5,7 };
	cout << "The original heap is: " << endl;
	for (int j = 0; j < log2(A.size()); j++)
	{
		for (int z = 0; z < log2(A.size()) - j; z++)
		{
			cout << " ";
		}
		for (int k = 0; k < pow(2, j) && (pow(2, j) - 1) + k < A.size(); k++)
		{
			for (int z = 0; z < log2(A.size()) - j; z++)
			{
				cout << " ";
			}
			cout << A[(pow(2, j) - 1) + k];
		}
		cout << endl;
	}
	delete_heap(A);
}

int search_heap(vector<int>& A, int i, int v)
{
	int a = -1, b = -1;
	if (A[i - 1] == v)
		return i;
	if (A[i - 1] > v)
	{
		if (2 * i <= A.size())
			a = search_heap(A, 2 * i, v);
		if (2 * i + 1 <= A.size())
			b = search_heap(A, 2 * i + 1, v);
	}
	return ((a > b) ? a : b);
}

void delete_heap(vector<int>& A)
{
	int value;
	cout << "input search value: ";
	cin >> value;
	int i;
	i = search_heap(A, 1, value);


	if (i == A.size())
	{
		cout << "The position at: " << i << endl;
		A.pop_back();
	}
	else if (i > -1)
	{
		cout << "The position at: " << i << endl;
		int temp;
		temp = A[i - 1];
		A[i - 1] = A[A.size() - 1];
		A[A.size() - 1] = A[i - 1];
		A.pop_back();
		cout << "After delete searched value, the heap is: " << endl;
		for (int j = 0; j < log2(A.size()); j++)
		{
			for (int z = 0; z < log2(A.size()) - j; z++)
			{
				cout << " ";
			}
			for (int k = 0; k < pow(2, j) && (pow(2, j) - 1) + k < A.size(); k++)
			{
				for (int z = 0; z < log2(A.size()) - j; z++)
				{
					cout << " ";
				}
				cout << A[(pow(2, j) - 1) + k];
			}
			cout << endl;
		}
		build_max_heap(A);
	}
	else if (i == -1)
	{
		cout << "can't find searched value" << endl;
	}
}

void build_max_heap(vector<int>& A)
{
	int n = A.size();
	for (int i = ceil(n / 2); i >= 1; i--)
	{
		max_heapify(A, i, n);
	}
}

void max_heapify(vector<int>& A, int i, int n)
{
	int l = 2 * i - 1;
	int r = 2 * i;
	int largest = i - 1;
	if (l <= n - 1 && A[l] > A[i - 1])
		largest = l;
	else if (l <= n - 1 && A[l] < A[i - 1])
		largest = i - 1;
	if (r <= n - 1 && A[r] > A[largest])
		largest = r;
	if (largest != i - 1)
	{
		int temp;
		temp = A[i - 1];
		A[i - 1] = A[largest];
		A[largest] = temp;
		cout << "rerange:" << endl;
		for (int j = 0; j < log2(A.size()); j++)
		{
			for (int z = 0; z < log2(A.size()) - j; z++)
			{
				cout << " ";
			}
			for (int k = 0; k < pow(2, j) && (pow(2, j) - 1) + k < A.size(); k++)
			{
				for (int z = 0; z < log2(A.size()) - j; z++)
				{
					cout << " ";
				}
				cout << A[(pow(2, j) - 1) + k];
			}
			cout << endl;
		}
		max_heapify(A, largest + 1, n);
	}
}