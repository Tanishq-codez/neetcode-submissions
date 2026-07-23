class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    int s = nums.size();
    vector<int>p(s) ;
    vector<int>a(s) ; 

    for(int i = 0 ;  i < s ; i++){
    if(i==0) p[i]=1;
    else 
    p[i]=p[i-1]*nums[i-1];
    }

    int suffix = 1;
for (int i = s - 1; i >= 0; i--) {
    a[i] = p[i] * suffix;
    suffix *= nums[i];
}

    return a ; 
    }
};
