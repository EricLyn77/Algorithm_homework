
#include <iostream>
#include <vector>
using namespace std;
void merge_sort(vector<int>&);

int main()
{
	vector<int> a{ 1,4,9,3,4,9,5,6,9,3,7,2 };
	merge_sort(a);
	cout << "rerange array is:" << endl;
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	system("pause");
}
void merge_sort(vector<int>& v)
{
	for (int i = 0; i <= ceil(log2(v.size())); i++)
	{
		for (int j = 0; j < ceil(v.size() / pow(2, i)); j++)
		{
			vector<int> L;
			vector<int> R;
			for (int z = 0; z < pow(2, i - 1) && (z + j * pow(2, i) < v.size()); z++)
			{
				L.push_back(v[j*pow(2, i) + z]);
				if (v.size() - j * pow(2, i) - pow(2, i - 1) - z > 0)
				{
					R.push_back(v[j*pow(2, i) + pow(2, i - 1) + z]);
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
		cout << "After " << i << "th sort, the array is:" << endl;
		for (int x = 0; x < v.size(); x++)
		{
			cout << v[x] << " ";
		}
		cout << endl;
	}
}
