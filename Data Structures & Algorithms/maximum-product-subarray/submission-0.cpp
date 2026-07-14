class Solution {
public:

    int maxProduct(vector<int>& nums) {
        int maxi = nums[0];
        int mini = nums[0] ;
        int r = maxi ;  
        for(int i = 1 ; i <nums.size();i++){

        int tempmaxi = max(nums[i] , max(nums[i]*maxi , nums[i]*mini) ) ;
        mini = min(nums[i] , min(nums[i]*maxi , nums[i]*mini) );
        maxi = tempmaxi ; 

        r = max(r,maxi );
        }

        return r; 

    }
};
