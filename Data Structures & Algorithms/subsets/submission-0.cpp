class Solution {
private:
    void func(int ind,int n,  vector<int>& nums, vector<vector<int>>&ans, vector<int>& arr){

        if(ind == n){
            ans.push_back(arr);
            return;
        }

        //pick
        func(ind + 1, n, nums, ans, arr);
        arr.push_back(nums[ind]);

        //not pick
        func(ind + 1, n, nums, ans, arr);

        //backtrack
        arr.pop_back();


    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> arr;

        func(0, nums.size(), nums, ans, arr);
        return ans;
    }
};
