class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // minimum of maxProfit is 0 
        // first chosen number must be smaller than the second one 
        int sum = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i-1]) {
                sum += (prices[i] - prices[i-1]);
            }
        }
		// if the prices is sorted, a <= b <= c <= d, 
		// then max profit is (d-a) = (b-a) + (c-b) + (d-c)
		// else, 
		//	a <= b <= c >= d, max profit is (c - a) = (c - b) + (b - a)
		// other examples are pretty straightforward
        return sum;
    }
};