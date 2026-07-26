class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res = 0 ; 
        int i = 0 , j = heights.size()-1 ; 
        int b  ; 
        while (i<j){
            b = j - i ;
            int a  = min(heights[i] , heights[j]) * b  ; 
            res = max(res , a);
            if (heights[i] < heights[j])i++;

            else j-- ; 

        }

        return res ; 
    }
};
