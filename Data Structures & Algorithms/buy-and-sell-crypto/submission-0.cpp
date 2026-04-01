class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxi = 0 ; 
        int curr = prices[0];
        for (int i = 0 ; i < n ; i++ ){
            if (prices[i]<curr) curr = prices[i];
             int profit = prices[i] - curr ; 
            if( profit - maxi > 0) maxi = profit ;
            
        }
        return maxi ; 
    }
};
