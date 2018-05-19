class Solution {
public:
    /**
     * @param s: Roman representation
     * @return: an integer
     */
    int romanToInt(string &s) {
        // write your code here
        map<char, int> m;
        m['I'] = 1; m['V'] = 5; m['X'] = 10; m['L'] = 50; m['C'] = 100; m['D'] = 500; m['M'] = 1000;
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i+1 < s.length() && m[s[i+1]] > m[s[i]]) {
                sum -= 2*m[s[i]];
            }
            sum += m[s[i]];
        }
        return sum;
    }
};