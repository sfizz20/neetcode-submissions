class Solution {
public:
    int countSubstrings(string s) {
        
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int cnt = 0;

        for(int len = 1; len<=n; len++){
            for(int i = 0; i<=n-len; i++){

                int j = i + len - 1;

                if(s[i] == s[j] && (len<=2 || dp[i+1][j-1])){
                    dp[i][j] = true;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
