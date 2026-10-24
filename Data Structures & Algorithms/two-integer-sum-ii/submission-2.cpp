class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        int i = 0 , j = num.size()-1;
        while(true){
        if ( num[i] + num[j] ==  target) return {i+1, j+1 } ;

        while ( num[i] + num[j] > target ) j-- ;

        while ( num[i] + num[j]  < target) i++ ;
        }
    }
};
