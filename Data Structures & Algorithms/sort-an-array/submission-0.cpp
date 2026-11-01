class Solution {
   public:
    void shellSort(vector<int>& nums, int n) {
        for (int gap = n / 2; gap >= 1; gap /= 2) {
            for (int i = gap; i < n; i++) {
                for (int j = i; j >= gap && nums[j - gap] > nums[j]; j -= gap) {
                    swap(nums[j], nums[j - gap]);
                }
            }
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        if (nums.size() == 1) return nums;
        shellSort(nums, nums.size());
        return nums;
    }
};