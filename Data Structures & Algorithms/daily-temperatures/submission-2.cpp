class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        stack<pair<int,int>> st;
        int n = temperatures.size();
        vector<int> ans(n);
        ans[n-1] = 0;

        for(int i=1; i<=n-1; i++){

            while(!st.empty()){
                if(temperatures[i] > st.top().first){
                    ans[st.top().second] = (i-st.top().second);
                    st.pop();
                }
                else{break;}
            }

            if(temperatures[i] > temperatures[i-1]){
                ans[i-1] = 1;
            }

            else if(i!=(n-1) && temperatures[i]<=temperatures[i-1]){
                st.push({temperatures[i-1], i-1});
            }
        }

        return ans;
    }
};
