class Solution {
public:
    string intToRoman(int num) {
		/*
		Time: O(sum of the digits) 
		Space: O(1), where it stores all the specifications 
		and find would take O(1) as it uses hash table
		*/
		unordered_map<int, string> m;
		int divisor = 1000;
		string result;
		m[1] = "I";
		m[5] = "V";
		m[10] = "X";
		m[50] = "L";
		m[100] = "C";
		m[500] = "D";
		m[1000] = "M";
		while (num != 0 && divisor != 0)
		{
			int remainder = (num / divisor) % 10;
			if (remainder != 0)
			{
				if (remainder % 5 == 4) {
					// 4 or 9
					result += m[divisor] + m[(remainder / 5 + 1) * divisor * 5];
				}
				else {
					// 1-3
					if (remainder / 5) result += m[5*divisor];
					for (int i = 0; i < (remainder%5); i++) {
						result += m[divisor];
					}
				}
			}
			divisor /= 10;
		}
		return result;
		
		// A more elegant solution......
		//  打表: 舍空间，争时间
		// Time: O(1) 
		vector<string> M = {"", "M", "MM", "MMM"};
		vector<string> C = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
		vector<string> X = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
		vector<string> I = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
		return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
    }
};