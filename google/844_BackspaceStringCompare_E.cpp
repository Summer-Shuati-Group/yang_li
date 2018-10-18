class Solution {
public:
    string solve(string S) {
        stack<int> s;
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == '#' && !s.empty()) {
                s.pop();
            }
            else if (S[i] == '#' && s.empty()){
                continue;
            }
            else {
                cout << S[i] << endl;
                s.push(S[i]);
            }
        }
        string ans;
        while (!s.empty()) {
            ans += s.top();
            s.pop();
        }
        return ans;
    }

    bool backspaceCompare(string S, string T)
    {
        return (solve(S) == solve(T));
    }
};