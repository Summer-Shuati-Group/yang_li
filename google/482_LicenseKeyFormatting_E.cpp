class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int length = 0;
        for (auto i = 0; i < S.length(); i++) {
            if (S[i] != '-') {
                length++;
            }
        }
        auto len1 = length % K;
        for (auto i = 0; i < S.length(); i++) {
            if (S[i] == '-') {
                S.erase(i, 1);
                i--;
            }
        }
        int cnt = 0;
        for (auto i = 0; i < S.length(); i++) {
            if (i + 1 == len1 && len1 != 0) {
                // cout << "i: " << i << " " << S[i] << endl;
                if (S[i] != '-' && i!= S.length() - 1) {
                    S.insert(i + 1, "-");
                    cnt++;
                }
            } // first group
            else if (i + 1 - cnt - len1 >= K && (i + 1 - cnt - len1) % K == 0) {
                // cout << "i: " << i << " " << S[i] << endl;
                if (S[i] != '-' && i != S.length() - 1) {
                    S.insert(i + 1, "-");
                    cnt++;
                }
            }
            if (S[i] >= 'a' && S[i] <= 'z') {
                S[i] += 'A' - 'a';
            } // convert lowercase to uppercase
        }
        return S;
    }
};