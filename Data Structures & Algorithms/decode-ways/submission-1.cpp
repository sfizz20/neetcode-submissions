class Solution {
private:
    int solve(int i, string s, vector<int>& dp){

        int n = s.length();

        if(i == n) return 1;

        if(s[i] == '0') return 0;

        if(dp[i] != -1) return dp[i];

        int ans = solve(i+1, s, dp);

        if(i + 1 < n){
            int twodigit = (s[i] - '0')*10 + (s[i+1] - '0');
            if(twodigit >= 10 && twodigit <= 26) ans += solve(i+2, s, dp);
        }

        return dp[i] = ans;
    }
public:
    int numDecodings(string s) {
        if(s.empty()) return 0;
        int n = s.length();
        vector<int> dp(n, -1);

        return solve(0, s, dp);
    }
};
