class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
		/*
		Time: O(n) -> worst-case upper-bound
		*/
        int pos = digits.size() - 1;
        while (true) {
            if (digits[pos] < 9) {
                digits[pos]++;
                break;
            } // no carry, only add one 
            else {
                digits[pos] = 0;
                if (pos - 1 >= 0) {
                    pos--;
                } // carry to the existing position
                else {
                    digits.insert(digits.begin(), 1);
                    break;
                } // carry to nonexisting position, add 1 to the front 
            }
        }
        return digits;
    }
};