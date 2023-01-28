// Algorithm hw.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <fstream>
#include "Algorithm hw.h"
using namespace std;

int drone_arrival[5] = { 0,1,10,10,1 };
int protect_function[5] = { 0,1,2,4,8 };

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

	/*vector<int> A = { 6, 0, 2, 0, 1, 3, 4, 6, 1, 3, 2 };
	reverse_counting_sort(find_vector_range(A), A);
	system("pause");*/

	/*vector<int> A = {9,6,8,2,5,7};
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
	system("pause");*/
	/*vector<int> A = { 16,  14,  10,  8,  7,  9,  3,  2,  4,  1 };
	vector<int> B = { 10,  3,  9,  7,  2,  11,  5,  1, 6 };
	cout<<"The input array is:" <<endl;
	for (int i = 0; i < B.size(); i++)
	{
		cout << B[i] << " ";
	}
	cout << endl;
	heap_judgement(B);
	system("pause");*/
	
	laser_pd();

}


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

void max_heapify(vector<int>& A, int i, int n)
{
	int l = 2 * i  - 1;
	int r = 2 * i;
	int largest = i - 1;
	if (l  <= n - 1 && A[l] > A[i - 1])
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

void build_max_heap(vector<int>& A)
{
	int n = A.size();
	for (int i = ceil(n / 2); i >= 1; i--)
	{
		max_heapify(A, i, n);
	}
}

int heap_extract_max(vector<int>& A)
{
	build_max_heap(A);
	int max = A[0];
	int n = A.size();
	A[0] = A[n - 1];
	A.pop_back();
	max_heapify(A, 1, n - 1);
	return max;
}

int search_heap(vector<int>& A,int i, int v)
{
	int a = -1, b = -1;
	if(A[i-1] == v)
		return i;
	if (A[i - 1] > v)
	{
		if(2*i<=A.size())
			a = search_heap(A, 2 * i, v);
		if(2*i+1<=A.size())
			b = search_heap(A, 2 * i + 1, v);
	}
	return ((a>b)?a:b);
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
	else if(i>-1)
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
	int l = 2*i -1;
	int r = 2*i;
	int a = 1, b = 1;
	if (l <= n - 1&&A[l] > A[i - 1])
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

int laser()
{
	int M[5] = {0};
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
			temp = (((a[i][j] + M[j]) > M[i - 1])? (a[i][j] + M[j]) : M[i - 1]);
			if (temp > M[i])
				M[i] = temp;
		}
		laser_output <<"  "<< M[i] << "  ";
	}
	laser_output << endl;
	laser_output << "----------------------------------------------" << endl;
	laser_output <<"Max drones harmless are: " <<M[4];

	return M[4];
}

void laser_pc()
{
	int M[5] = { 0 };
	int a[5][5];
	int opt[5][5] = { 0 };
	fstream laser_output;
	int choose[5] = { -1 };
	laser_output.open("laser_pc_out.txt", ios::out | ios::trunc);
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
				choose_it = j;
			}
			else
			{
				temp = M[i - 1];
				choose_it = 0;
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
	laser_output << "----------------------------------------------" << endl;
	laser_output << "    Time    " << "1st" << "          " << "2nd" << "          " << "3rd" << "           " << "4th" << endl;
	laser_output << "choice is" << "   ";
	for (int i = 1; i < 5; i++)
	{
		if (choose[i] != -1)
			laser_output << "opt(" << choose[i] << ")" << "+" << a[i][choose[i]] << "    ";
		else
			laser_output << "opt(" << i - 1 << ")" << "    ";
		
	}

}

void laser_pd()
{
	int M[5] = { 0 };
	int a[5][5];
	int opt[5][5] = {0};
	fstream laser_output;
	int choose[5] = {0};
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
		if (4-i == b)
		{
			choose_final.push_back('Y');
		}
		else
		{
			choose_final.push_back('N');
		}
	}
	laser_output << "----------------------------------------------" << endl;
	laser_output << "    Time    "<< "1st" << "  " << "2nd" << "  " << "3rd" << "  " << "4th" << endl;
	laser_output << "use or not" << "   ";
	for (int i = 0; i < choose_final.size(); i++)
	{
		laser_output << choose_final[choose_final.size()-i-1] << "    ";
	}

}


