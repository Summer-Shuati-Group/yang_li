class Solution {
public:
    int myAtoi(string str) {
		// stringstream could single-handedly handle the 'atoi' request
		// However, it would produce strange output '11' when input is empty string
        stringstream ss(str);
        int n;
        ss >> n;
        return n;

		int output = 0;
        int i = 0; bool sign = false;
        while (str[i] == ' ') i++; // clear out all the leading whitespaces
        if (str[i] == '+' || str[i] == '-') 
        {
            sign = (str[i] == '-');
            i++;
        } // there is only at most 1 '+' or '-' sign 
		// so we need if statement, if there is another sign 
		// base would directly be 0, bypassing the next while loop
        while (str[i] >= '0' && str[i] <= '9') {
            if ((output == INT_MAX / 10 && str[i] - '0' > 7) || output > INT_MAX / 10) {
                if (sign) return INT_MIN;
                else return INT_MAX;
            } // determine the overflow 
            output = output * 10 + (str[i] - '0');
            i++;
        } 
        if (sign) return -1 * output;
	    else return output;
    }
};