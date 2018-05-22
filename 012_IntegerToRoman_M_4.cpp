class Solution {
public:
    string intToRoman(int num) {
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
            else if (remainder / 5 == 0) {
                // 1-3
                for (int i = 0; i < (remainder%5); i++) {
                    result += m[divisor];
                }
            }
            else if (remainder / 5 == 1) {
                // 5-8
                result += m[5*divisor];
                for (int i = 0; i < (remainder%5); i++) {
                    result += m[divisor];
                }
            }
		}
		divisor /= 10;
	}
	return result;
    }
};