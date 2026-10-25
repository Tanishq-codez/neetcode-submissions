class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack <int> dec ;
        vector<int> res (temp.size() , 0 );
        for ( int i = 0 ; i < temp.size() ; i++ ){
        while ( !dec.empty() && temp[dec.top()]<temp[i]){
            int j = dec.top();
            dec.pop();
            res[j] = i-j;
        }

        dec.push(i);

        }
        return res; 
    }
};
