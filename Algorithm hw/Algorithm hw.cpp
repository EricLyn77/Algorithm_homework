// Algorithm hw.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Algorithm hw.h"
using namespace std;
int main()
{
	/*vector<int> a{1,4,9,3,4,9,5,6,9,3,7};
	cout <<"the input array size is:" << a.size()<<endl;
	int max;
	int position;
	position=max_position(a, a.size(), 0, max);
	cout <<"the biggest value's position is: " << position<<endl;
	system("pause");*/

	/*vector<int> a{ 4, -3,9,8,7,-4,-2,-1,0,6,-5 };
	arrange_positive_negative(a);
	cout << "rerange arrat is : " << endl;
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << " ";
	} 
	cout << endl;
	system("pause");*/

	/*vector<int> a{1,4,9,3,4,9,5,6,9,3,7,2};
	merge_sort(a);
	cout << "rerange array is:" << endl;
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	system("pause");*/

	vector<int> A = { 6, 0, 2, 0, 1, 3, 4, 6, 1, 3, 2 };
	reverse_counting_sort(find_vector_range(A), A);
	system("pause");
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

int max_position(vector<int> v, int size, int index, int &max)
{
	if (size > 1)
	{
		vector<int> a, b;
		int amax, bmax, aindex, bindex;
		int n1 = v.size() / 2;
		int n2 = size - n1;
		for (int i = 0; i < n1; i++)
		{
			a.push_back(v[i]);
		}
		aindex = max_position(a, a.size(), index, amax);
		for (int j = 0; j < n2; j++)
		{
			b.push_back(v[j + n1]);
		}
		bindex = max_position(b, b.size(), index + n1, bmax);
		if (amax > bmax)
		{
			max = amax;
			return aindex;
		}
		else
		{
			max = bmax;
			return bindex;
		}
	}
	else if (size == 1)
	{
		max = v[0];
		return index;
	}
	 
}

void arrange_positive_negative(vector<int> &v)
{
	int n = v.size();
	int k = 1;
	for (int i = 0; i < n; i++)
	{	
		if (v[i] == 0)
		{
			int x = 0;
			while (v[i + x] == 0 && n - k > i + x)
			{
				x++;
			}
			if (n - k < i + x)
			{
				break;
			}
			int a = v[i + x];
			v[i + x] = v[i];
			v[i] = a;
			//i = i - 1;
		}
		if (v[i] > 0)
		{
			if (i <= n - k)
			{
				for (int j = k; j < n; j++)
				{
					if (i <= n - j)
					{
						if (v[n-j] < 0)
						{
							int b = v[n - j];
							v[n - j] = v[i];
							v[i] = b;
							k = j;
							break;
						}
						else if (v[n - j] == 0)
						{
							int z = 1;
							while (v[n - j - z] == 0 && n - j - z > i)
							{
								z++;
							}
							if (n - j - z <= i)
							{
								int b = v[n - j];
								v[n - j] = v[i];
								v[i] = b;
								k = j + z;
								break;
							}
							int c = v[n - j - z];
							v[n - j - z] = v[n - j];
							v[n - j] = c;
						    j = j - 1;
						}
					}
					else
					{
						break;
					}
				}
			}
			else
			{
				break;
			}
		}
	}
}

void merge_sort(vector<int>& v)
{
	for (int i = 0; i <= ceil(log2(v.size())); i++)
	{
		for (int j = 0; j < ceil(v.size() / pow(2, i)); j++)
		{
			vector<int> L;
			vector<int> R;
			for (int z = 0; z < pow(2, i - 1) && (z+j*pow(2,i)<v.size()); z++)
			{
				L.push_back(v[j*pow(2, i) + z]);
				if (v.size() - j * pow(2, i) - pow(2, i - 1) - z > 0)
				{
					R.push_back(v[j*pow(2, i) + pow(2,i-1) + z]);
				}
			}
			int l = 0;
			int r = 0;
			for (int a = 0; a < pow(2, i) && (v.size() - j * pow(2, i) - a > 0); a++)
			{
				if (l < L.size() && r < R.size())
				{
					if (L[l] <= R[r])
					{
						v[j*pow(2, i) + a] = L[l];
						l++;
					}
					else if (R[r] < L[l])
					{
						v[j*pow(2, i) + a] = R[r];
						r++;
					}
				}
				else if (l >= L.size())
				{
					v[j*pow(2, i) + a] = R[r];
					r++;
				}
				else if (r >= R.size())
				{
					v[j*pow(2, i) + a] = L[l];
					l++;
				}
			}
		}
		cout << "After " << i <<"th sort, the array is:" << endl;
		for (int x = 0; x < v.size(); x++)
		{
			cout << v[x] << " ";
		}
		cout << endl;
	}
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
	int * B = new int[100]{0};

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
	for (int a = 0; a<A.size(); a++)
	{
		cout << B[a] << " ";
	}
}
