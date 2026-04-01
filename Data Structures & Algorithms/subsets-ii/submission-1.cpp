class Solution {
public:

    void subsets(vector<vector<int>> &ans, vector<int> &v, int idx, vector<int>& nums) {
        ans.push_back(v);

        for(int i = idx; i < nums.size(); i++) {  
            if(i > idx && nums[i] == nums[i-1]) continue; 
            
            v.push_back(nums[i]);
            subsets(ans, v, i + 1, nums);  
            v.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        
        vector<vector<int>> ans;
        vector<int> v;

        subsets(ans, v, 0, nums);
        return ans;
    }
};