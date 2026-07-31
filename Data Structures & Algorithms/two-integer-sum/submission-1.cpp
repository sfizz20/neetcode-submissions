class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mpp;

        for(int i=0; i<n; i++){

            int req_sum = target - nums[i];

            if(mpp.find(req_sum) != mpp.end()){
                return {mpp[req_sum], i};
            }

            mpp[nums[i]] = i;
        }
    }
};
