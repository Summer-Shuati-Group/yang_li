class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> ans;
        int sum = 0;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
                ans.push(atoi(tokens[i].c_str()));
            } // only take in numbers 
            else {
                int a = ans.top();
                ans.pop();
                int b = ans.top();
                ans.pop();
                // cout << "a: " << a << ' ' << "b: " << b << endl;
                if (tokens[i] == "+") {
                    sum = a + b;
                }
                else if (tokens[i] == "-") {
                    sum = (b - a);   
                }
                else if (tokens[i] == "*") {
                    sum = (a * b);
                }
                else if (tokens[i] == "/") {
                    sum = (b / a);
                }
                // cout << "sum: " << sum << endl;
                ans.push(sum);
            } // when an operator is encountered, 
			// do the corresponding operation between two top numbers
        }
        return ans.top();
    }
};