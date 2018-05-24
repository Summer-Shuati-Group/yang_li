class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
		/*
		1. sort the array, 
		2. minimum of the pairs would have index 0, 2, 4, 6, 8, .... 
		3. just add up all the elements by every 2 elements
		*/
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < nums.size(); i+=2) {
            sum += nums[i];
        }
        return sum;

		int arr[200001] = {0};
        bool flag = 1;
        unsigned int sum = 0;
        for(unsigned int i = 0;i < nums.size();i++) arr[nums[i]+10000]++;
        for(unsigned int i = 0;i < 200001;i++){
            if(arr[i]){
                if(flag) sum += i-10000;
                flag = !flag;
                if(--arr[i]) i--;
            }
        }
        return sum;
    }
};