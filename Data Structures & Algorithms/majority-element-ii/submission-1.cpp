class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1 = -1 , c2 = -1 , n1 = 0 , n2 = 0 ; 
        int n = nums.size();
        for ( int i = 0 ; i < n  ; i++){
            if (nums[i] == c1) n1++ ;
            else if (nums[i] == c2) n2++ ; 

            else if ( n1 == 0 ){
                c1 = nums[i];
                n1 = 1 ;
            }
            else if ( n2 == 0 ){
                c2 = nums[i];
                n2 = 1 ;
            }
            else {
            n1 -- ;
            n2 -- ;
            }
        }

         n1 = 0 , n2 = 0 ;

        for ( int &num : nums ){
            if ( num == c1) n1++ ;
            if ( num == c2) n2++ ;
        }
       
        vector<int> res ;
        if ( n1> n/3) res.push_back(c1);
        if ( n2 > n/3) res.push_back(c2);

        return res;
    }
};