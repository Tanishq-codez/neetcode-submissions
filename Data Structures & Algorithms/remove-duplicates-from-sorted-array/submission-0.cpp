class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    int curr = INT_MIN ; 
    int j = 0 ; 
    for ( int i = 0   ; i < nums.size() ; i++){
    if ( nums[i] > curr){{
         nums[j] = nums[i];
         curr = nums[i];
         j++;
          }
        
    }
    }   
    return j ; 
    }
};