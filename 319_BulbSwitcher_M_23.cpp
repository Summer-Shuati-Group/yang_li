class Solution {
public:
    int bulbSwitch(int n) {
		/* brainteaser */
        return sqrt(n);


		// simulation (hard-coding):
		// only work on small inputs, large inputs would 
		// cause stack overflow
        bool arr[n + 1];
         for (int i = 0; i < n; i++) {
            arr[i] = false;
        }
        int increment = 1;
        int i = -1;
        int temp = n;
        while (n--)
        {
            i = -1;
            while (i < temp) {
                i += increment;
                if (i < temp) arr[i] = !arr[i];
            }
            //cout << endl;
            //cout << "......." << endl;
            // print(arr, temp);
            increment++;
            // cout << "incre: " << increment << endl;
        }
        int ans = 0;
        for (int i = 0; i < temp; i++)
        {
            if (arr[i])
                ans++;
        }
        return ans;
    }
};