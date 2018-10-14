class Solution
{
  public:
	/**
     * @param color: the given color
     * @return: a 7 character color that is most similar to the given color
     */

	int convert(string str)
	{
		int n = 0;
		int cnt = 0;
		for (int i = str.size() - 1; i >= 0; i--)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				n += pow(16, cnt) * (str[i] - '0');
			}
			else if (str[i] >= 'a' && str[i] <= 'f')
			{
				n += pow(16, cnt) * (str[i] - 'a' + 10);
			}
			cnt++;
		}
		return n;
	}

	string similarRGB(string &color)
	{
		// Write your code here
		string result = "#";
		for (int i = 1; i <= 5; i += 2)
		{
			int n = convert(color.substr(i, 2));
			cout << "n: " << n << endl;
			// number converted from hexadecimal to decimal
			int n_transform = floor(n / 17.0 + 0.5);
			cout << "n_transform: " << n_transform << endl;
			// should be less than 16
			if (n_transform >= 10)
			{
				result += 'a' + n_transform % 10;
				result += 'a' + n_transform % 10;
			}
			else
			{
				result += to_string(n_transform % 10);
				result += to_string(n_transform % 10);
			}
		}
		return result;
	}
};