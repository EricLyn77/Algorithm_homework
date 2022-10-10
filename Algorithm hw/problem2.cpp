#include <iostream>
#include <vector>

using namespace std;
int max_position(vector<int>, int, int, int &);

int main()
{
	vector<int> a{1,4,9,3,4,9,5,6,9,3,7};
	cout <<"the input array size is:" << a.size()<<endl;
	int max;
	int position;
	position=max_position(a, a.size(), 0, max);
	cout <<"the biggest value's position is: " << position<<endl;
	system("pause");

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