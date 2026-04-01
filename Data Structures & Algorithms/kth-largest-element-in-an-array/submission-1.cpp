class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue < int ,  vector<int>  , greater<int> > pq ;

        for (int i = 0 ; i < k ; i++)
        {
            int e = nums[i] ;
            pq.push(e) ;

        }
        
        for (int j = k ; j < nums.size() ; j++ ){
            int e = nums[j];
            int t = pq.top();
            if (e>t){pq.pop();
            pq.push(e);}
        }
        
return pq.top();
        
    }
};
