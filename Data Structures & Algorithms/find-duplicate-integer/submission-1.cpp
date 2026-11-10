class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        int i = 0;
        int j = 0;
        while (true) {
            i = nums[i];
            j = nums[nums[j]];

            if ( i == j ) break ; 
        }

        i = 0;

        while (true) {
            i = nums[i];
            j = nums[j];

            if (i == j) break ; 
        }

        return i ; 
    }
};
