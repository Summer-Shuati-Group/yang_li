class Solution {
public:
    int reverse(int x) {
		/*
		暴力做法:
		Space: O(log10 n), where n is the size of the number 
		Time: O(log10 n), where n is the size of the number
		*/

        string str = to_string(x);
        for (int i = 0; i < str.length() / 2; i++)
        {
            swap(str[i], str[str.length() - 1 - i]);
        }
        if (str[str.length() - 1] == '-') {
            str = "-" + str.substr(0, str.length() - 1);
        }
        while ((str[0] == '0') && str.length() > 1)
        {
            str = str.substr(1);
        }
        int result;
        stringstream ss(str);
        ss >> result;
        if (result >= pow(2, 31) - 1 || result <= -pow(2, 31)) {
            return 0;
        }
        else {
            return result;
        }


		/*
		A much better solution......
		Space: a 64-bit integer (prevent overflow)
		Time: O(log10 n) -> only have to go through the numbers once
		*/
		long long result = 0;
        while (x != 0)
        {
            result = result * 10 + x % 10;
            x /= 10;
        }
        result = (result >= pow(2, 31) - 1|| result <= -pow(2, 31)) ? 0 : result;
        return result;
    }
};