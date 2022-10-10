#include <iostream>
#include <vector>
#include "Algorithm hw.h"
using namespace std;

void arrange_positive_negative(vector<int> &v);
void arrange_positive_negative_2(vector<int> &v);

int main()
{
    vector<int> a{ 4, -3,9,8,7,-4,-2,-1,0,6,-5 };
	arrange_positive_negative(a);
	cout << "rerange arrat is : " << endl;
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	system("pause");

	/*arrange_positive_negative_2(a);
	cout << "rerange arrat is : " << endl;
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	system("pause");*/

}

void arrange_positive_negative(vector<int> &v)
{
	int n = v.size();
	int k = 1;
	for (int i = 0; i < n; i++)
	{

		if (v[i] > 0)
		{
			if (i <= n - k)
			{
				for (int j = k; j < n; j++)
				{
					if (i <= n - j)
					{
						if (v[n - j] < 0)
						{
							int b = v[n - j];
							v[n - j] = v[i];
							v[i] = b;
							k = j;
							break;
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


void arrange_positive_negative_2(vector<int> &v)//make the 0 between positive and negative
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
						if (v[n - j] < 0)
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