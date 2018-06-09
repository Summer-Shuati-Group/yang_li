class Solution
{
  public:
	int BinarySearch(vector<int> &nums, int l, int r, int target)
	{
		if (r < l)
			return -1;
		int mid = (l + r) / 2;
		if (nums[mid] == target)
			return mid;
		else if (nums[mid] > target)
		{
			return BinarySearch(nums, l, mid - 1, target);
		}
		else
		{
			return BinarySearch(nums, mid + 1, r, target);
		}
	}

	int search(vector<int> &nums, int target)
	{
		/* Time: 
			1. search the minimum: O(log n) 
			2. search the left portion for target: O(log n)
			3. search the right portion for target: O(log n)
		the total time is O(log n + log n + log n) = O(log n) */
		int start = 0;
		int end = nums.size() - 1;
		int minimum = 0;
		while (start <= end)
		{
			if (nums[start] <= nums[end])
			{
				minimum = start;
				break;
			}
			int mid = (start + end) / 2;

			if (nums[mid] >= nums[start])
			{
				start = mid + 1;
			}
			else
			{
				end = mid;
			}
		}
		// first locate the minimum element in tne array 
		// and search the left and right portion respectively
		if (minimum - 1 >= 0)
		{ // there is elements before -> it's rotated
			return max(BinarySearch(nums, 0, minimum - 1, target), BinarySearch(nums, minimum, nums.size() - 1, target));
		}
		else
			return BinarySearch(nums, 0, nums.size() - 1, target);
		// it is not rotated
	}
};