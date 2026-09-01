class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();

        int left = 0;
        int right = n-1;
        int max_area = 0;

        while(left<right){

            int curr_area = (min(heights[left], heights[right]) * (right-left));

            max_area = max(curr_area, max_area);

            if(heights[left]<heights[right]){
                left++;
            }

            else{right--;}
        }

        return max_area;
    }
};
