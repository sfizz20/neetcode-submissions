class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int order_map[26];
        for(int i=0; i<order.size(); i++){
            order_map[order[i] - 'a'] = i;
        }

        for(int i=0; i<words.size()-1; i++){

            string w1 = words[i];
            string w2 = words[i+1];

            int min_length = min(w1.length(), w2.length());
            bool found_diff = false;

            for(int j = 0; j<min_length; j++){

                if(w1[j] != w2[j]){
                    if(order_map[w1[j] - 'a'] > order_map[w2[j] - 'a']){
                        return false;
                    }

                    found_diff = true;
                    break;
                }

                
            }

            if(!found_diff && w1.size() > w2.size()){
                    return false;
                }
        }
        return true;
    }
};