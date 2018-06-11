class Solution {
public:
    int evalRPN(vector<string>& tokens) {
		// 1. iterative implementation: 
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

		// 2. recursive implementation: 
		// 		(1). pop string from the end of the vector
		// 		(2). if it's number, just return it
		// 		(3). if it's operation, call function recursively for 2nd operand and 1st
		string s = tokens.back(); tokens.pop_back();
        if(s != "+" && s != "-" && s != "*" && s != "/") return stoi(s);
        
        int r2 = evalRPN(tokens), r1 = evalRPN(tokens);
        
        if(s == "+") return r1 + r2;
        if(s == "-") return r1 - r2;
        if(s == "*") return r1 * r2;
        if(s == "/") return r1 / r2;
    }
};