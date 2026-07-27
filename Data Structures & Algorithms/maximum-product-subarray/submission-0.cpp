class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();

        int currMin = nums[0];
        int currMax = nums[0];
        int maxsofar = nums[0];

        for(int i = 1; i<n; i++){

            int num = nums[i];

            if(num < 0){
                swap(currMin, currMax);
            }

            currMax = max(num , currMax*num);
            currMin = min(num ,currMin*num);

            maxsofar = max(currMax, maxsofar);
        }

        return maxsofar;


    }
};
