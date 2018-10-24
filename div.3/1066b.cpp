#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	int n, r, start = 0, end = 0, cnt = 0;
	cin >> n >> r;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 1)
		{
			if (i - r + 1 >= 0 && i + r - 1 <= n)
			{
				// the interval length would be maximized, which is (2r-2)
				start = i - r + 1;
				int j = i, temp = 0;
				while (true)
				{
					if (arr[j] == 1)
					{
						if (j - r + 1 <= end + 1)
						{
							// overlap in interval length
							temp = j;
							j++;
						}
						else
						{
							// find a heater that does not overlap in the range
							end = temp + r - 1;
							cnt++;
							break;
						}
					}
				}
				if (end != i + r - 1)
				{
					end = i + r - 1;
				} // if we do not find an overlapping interval,
				// then we set the end to the end of current interval 
			}
		}
		if (start != 0 && end != n)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << cnt << endl;
		}
		delete[] arr;
		return 0;
	}