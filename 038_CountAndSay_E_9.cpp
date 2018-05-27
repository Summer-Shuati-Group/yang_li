class Solution {
public:
    vector<string> v;
    string dp(int n)
    {
        if (n == 1) return "1";
        if (n == 2) return "11";
        v.push_back("1"); 
        v.push_back("11");
        int cnt = 0; string temp = "";
        for (int i = 2; i < n; i++)
        {
            char counter = v[i - 1][0]; cnt = 1; temp = "";
            for (int j = 1; j < v[i - 1].length(); j++)
            {
                if (v[i-1][j] == counter) {
                    cnt++;
                }
                else {
                    temp += to_string(cnt) + to_string(counter - '0');
                    counter = v[i-1][j]; cnt = 1;
                }
            }
            temp += to_string(cnt) + to_string(counter - '0');
            v.push_back(temp);
        }
        return v[n-1];
    }

    string countAndSay(int n)
    {
        return dp(n);
    }
};