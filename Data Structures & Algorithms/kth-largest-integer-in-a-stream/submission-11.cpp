class KthLargest {
    priority_queue<int , vector<int> , greater<int> > pq ; 
    int k ; 
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k ; 
        int i = 0;
        while (i<nums.size()){
    
    if(  i < k ){
        pq.push(nums[i]);
        i++;
    }
    else{if(pq.top()<nums[i])
        {
            pq.pop();
            pq.push(nums[i]);
        }
        i++;}
        
    }
    }
    
    int add(int val) {
    
        // Always push first
        pq.push(val);
        // If size exceeds K, pop smallest
        if(pq.size() > k) pq.pop();
        
        return pq.top(); // no need for null or edge variable
    
    }
};
