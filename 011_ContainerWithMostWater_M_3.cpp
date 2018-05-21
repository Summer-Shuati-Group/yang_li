class Solution
{
  public:
    int maxArea(vector<int> &height)
    {
        /*
        暴搜不可取！！！
        Time: O(n(n-1)/2) = O(n^2) 
        */
        int max = (height[0] < height[1]) ? height[0] : height[1];
        for (int i = 0; i < height.size(); i++)
        {
            for (int j = i + 1; j < height.size(); j++)
            {
                int height = (height[i] < height[j]) ? height[i] : height[j];
                if (height * (j - i) > max)
                    max = height * (j - i);
            }
        }
        return max;

        /*
          we would compute the area of the container by multiplying the min(ai, aj), 
          where 0 <= i, j <= height.size() - 1  
          
          Essentially, when we assume if there is a better solution than taking the
          two lines at the front and at the back, we are looking for a that has a
          higher height value in the vector. Therefore, we could approach this 
          higher height value from both ends and compare to see if we have the 
          largest area value 
        */
        int start = 0;
        int end = height.size() - 1;
        int area = 0;
        while (start < end)
        {
            area = max(area, min(height[start], height[end]) * (end - start));
            // we would start at the starting position and ending position
            if (height[start] < height[end])
                start++; // if start position has smaller value of height 
                // then we would shift rightward to see if there is any larger height
            else
                end--; // if end position has smaller value of height 
                // then we would shift leftward to see if there is any larger height
        }
        return area;
        }
};