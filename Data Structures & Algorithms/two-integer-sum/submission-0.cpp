class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> s;

        for(int i=0; i<n; i++){
            int req_sum = target - nums[i];

            if(s.find(req_sum) != s.end()){
                return {s[req_sum], i};
            }

            s[nums[i]] = i;
        }
    }
};
