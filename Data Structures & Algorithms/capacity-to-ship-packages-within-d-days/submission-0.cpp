class Solution {
   public:
    bool isValid(int s, vector<int>& w, int d) {
        int i = 0 ;
        int shipment = 0 ;
        while ( i < w.size()){
        if ( d == 0) return false ; 
        shipment += w[i];

        if ( shipment > s){
            shipment = 0 ; 
            d-- ; 
        }

        else i ++ ;
        }

        return true ; 
    }
    int shipWithinDays(vector<int>& w, int d) {
        int l = *max_element(w.begin(), w.end());
        int r = accumulate(w.begin(), w.end(),0);

        int res = INT_MAX;
        while (l <= r) {
            int m = l + (r - l) / 2;

            if (isValid(m, w, d)) {
                res = m;
                r = m - 1;
            } else
                l = m + 1;
        }

        return res;
    }
};