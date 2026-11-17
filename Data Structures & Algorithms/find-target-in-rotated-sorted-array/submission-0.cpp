class Solution {
public:
    int binarySearch(vector<int>& nums, int s, int e, int target) {
        while (s <= e) {
            int m = s + (e - s) / 2;
            if (nums[m] == target) return m;
            if (nums[m] < target) s = m + 1;
            else e = m - 1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;
        int p = 0; 

        
        while (s <= e) {
            if (nums[s] <= nums[e]) { 
                if (nums[s] < nums[p]) p = s;
                break;
            }
            int m = s + (e - s) / 2;
            if (nums[m] < nums[p]) p = m;

            if (nums[m] >= nums[s]) {

                s = m + 1;
            } else {

                e = m - 1;
            }
        }

        
        s = 0;
        e = nums.size() - 1;
        if (target >= nums[p] && target <= nums[e]) {
            return binarySearch(nums, p, e, target);
        } else {
            return binarySearch(nums, s, p - 1, target);
        }
    }
};
