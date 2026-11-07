class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;
        
        for (int i = 0; i < nums.size(); ++i) {
            // If window size exceeds k, remove the oldest element
            if (i > k) {
                window.erase(nums[i - k - 1]);
            }
            // If element is already in the set, a duplicate exists within distance k
            if (!window.insert(nums[i]).second) {
                return true;
            }
        }
        
        return false;
    }
};
