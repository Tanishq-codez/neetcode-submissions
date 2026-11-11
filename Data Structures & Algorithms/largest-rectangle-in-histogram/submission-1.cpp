class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> prevS(n,0);
        vector<int> nextS(n,0);

        stack<int> s;

        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[s.top()] > heights[i]) {
                nextS[s.top()] = i;
                s.pop();
            }

            s.push(i);
        }

        while (!s.empty()) {
            nextS[s.top()] = n;
            s.pop();
        }

        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && heights[s.top()] > heights[i]) {
                prevS[s.top()] = i;
                s.pop();
            }

            s.push(i);
        }

        while (!s.empty()) {
            prevS[s.top()] = -1;
            s.pop();
        }
        
        

        int res = 0 ; 
        for ( int i = 0 ; i < n ; i++){
        int area = heights[i] * ( nextS[i] - prevS[i] -1 ) ; 
        res = max ( area , res );
        }

        return res ; 
    }
};
