class Solution {
private:

    int func(int ind, vector<int>& cost, vector<int>& dp){

        if(dp[ind] != -1) return dp[ind];

        if(ind==0) return 0;
        if(ind==1) return 0;

        int oneStep = func(ind-1, cost, dp) + cost[ind-1];
        int twoStep = func(ind-2, cost, dp) + cost[ind-2];

        return dp[ind] = min(oneStep, twoStep);
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        vector<int> dp(n+1, -1);

        return func(n, cost, dp);
    }
};