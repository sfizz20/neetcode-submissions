class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
        unordered_set<string> vis(deadends.begin(), deadends.end());

        if(target == "0000") return 0;
        if(vis.count("0000")) return -1;

        int turns = 0;
        queue<string> q;
        q.push("0000");
        vis.insert("0000");

        while(!q.empty()){

            int size = q.size();
            for(int i=0; i<size; i++){
                
                string curr = q.front();
                q.pop();

                if(curr == target) return turns;

            for(int j=0; j<4; j++){

                string up = curr;
                up[j] = (curr[j] == '9') ? '0' : curr[j] + 1;
                if(!vis.count(up)){
                    vis.insert(up);
                    q.push(up);
                }

                string down = curr;
                down[j] = (curr[j] == '0') ? '9' : curr[j] - 1;
                if(!vis.count(down)){
                vis.insert(down);
                q.push(down);
                }
            }
        }
         turns++;
        }
return -1;  
    }

};