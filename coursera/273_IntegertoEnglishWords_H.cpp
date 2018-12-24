class Solution
{
  public:
	string ifEmpty(string str) {
		return str.empty() ? "" : " ";
	}

	string numberToWords(int num)
	{
		if (num == 0)
		{
			return "Zero";
		}
		string res;
		int cnt = 0;
		vector<string> v1 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
		vector<string> v2 = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
		vector<string> v3 = {"", "Thousand", "Million", "Billion"};
		while (num > 0)
		{
			string tmp;
			int temp = (num >= 1000) ? num % 1000 : num;
			if (temp)
			{
				int hundredth = temp / 100;
				int tenth = (temp / 10) % 10;
				int oneth = temp % 10;
				if (hundredth) tmp += v1[hundredth] + " Hundred" + (tenth || oneth ? " " : "");
				if (tenth < 2) tmp += v1[tenth * 10 + oneth];
				else tmp += v2[tenth] + (oneth ? " " + v1[oneth] : "") ;
				res = (num % 1000) ? tmp + " " + v3[cnt] + " "+ res : tmp; 
			}
			cnt++;
			num /= 1000;
		}
		while (res.back() == ' ') res.pop_back();
		return res;
	}
};