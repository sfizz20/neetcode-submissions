class Solution {
private:
    int solve(int rem, vector<int>& coins, vector<int>& dp){

            if(rem == 0) return 0;
            if(rem < 0) return -1;
            if(dp[rem] != -2) return dp[rem];

            int mini = INT_MAX;
            for(int coin : coins){
                int ans = solve(rem - coin, coins, dp);
                if(ans >= 0){
                    mini = min(mini, ans + 1);
                }
            }

            return dp[rem] = (mini == INT_MAX) ? -1 : mini;
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, -2);

        return solve(amount, coins, dp);

    }
};
