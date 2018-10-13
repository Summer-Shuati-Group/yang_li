class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        bool dp[s.length()];
        for (int i = 0; i < s.length(); i++)
        {
            dp[i] = find(wordDict.begin(), wordDict.end(), s.substr(0, i + 1)) != wordDict.end();
            if (dp[i] == false) {
                for (int j = 0; j < i; j++)
                {
                    if (dp[j] == true)
                    {
                        // we find the dividing line
                        dp[i] = find(wordDict.begin(), wordDict.end(), s.substr(j + 1, i - j)) != wordDict.end();
                    }

                    if (dp[i] == true) break;
                }
            }
            // cout << s.substr(0, i + 1) << ' ' << dp[i] << endl;
        }
        return dp[s.length() - 1];
    }
};