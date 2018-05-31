class Solution {
public:
    void reverseWords(string &s) {
		/* use stringstream to break into separate words,
		   push them into temporary vector,
		   reversely add them into an output string, including spaces,
		   make s = output */
        stringstream ss(s);
        string temp;
        string output;
        vector<string> v;
        while (ss >> temp) {
            v.push_back(temp);
        }
        for (int i = v.size() - 1; i >= 0; i--) {
            output += v[i];
            if (i != 0) output += " ";
        }
        s = output;
    }
};