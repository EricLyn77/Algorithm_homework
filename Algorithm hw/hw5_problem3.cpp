#pragma once
#include <iostream>
#include <vector>

using namespace std;

void main()
{
	vector<int> A = { 16,  14,  10,  8,  7,  9,  3,  2,  4,  1 };
	vector<int> B = { 10,  3,  9,  7,  2,  11,  5,  1, 6 };
	cout << "The input array is:" << endl;
	for (int i = 0; i < B.size(); i++)
	{
		cout << B[i] << " ";
	}
	cout << endl;
	heap_judgement(B);
	system("pause");
}

void heap_judgement(vector<int>& A)
{
	int l = 1;
	int r = 2;
	int i = 1;
	int largest = 0;
	int n = A.size();
	int a = 1, b = 1;
	if (l <= n - 1 && A[l] > A[i - 1])
		largest = l;
	else if (l <= n - 1 && A[l] < A[i - 1])
		largest = i - 1;
	if (r <= n - 1 && A[r] > A[largest])
		largest = r;
	if (largest == i - 1)
	{
		if (2 * i <= A.size())
			a = heap_judgement(A, 2 * i, n);
		if (2 * i + 1 <= A.size())
			b = heap_judgement(A, 2 * i + 1, n);
	}
	else
	{
		cout << "Not a heap" << endl;
	}
	if (a == 1 && b == 1)
	{
		cout << "Yes,hip" << endl;
	}
	else
	{
		cout << "Not a heap" << endl;
	}

}

int heap_judgement(vector<int>& A, int i, int n)
{
	int l = 2 * i - 1;
	int r = 2 * i;
	int a = 1, b = 1;
	if (l <= n - 1 && A[l] > A[i - 1])
		return -1;
	if (r <= n - 1 && A[r] > A[i - 1])
		return -1;
	if (2 * i <= A.size())
		a = heap_judgement(A, 2 * i, n);
	if (2 * i + 1 <= A.size())
		b = heap_judgement(A, 2 * i + 1, n);
	if (a == 1 && b == 1)
		return 1;
	else
		return -1;
}
