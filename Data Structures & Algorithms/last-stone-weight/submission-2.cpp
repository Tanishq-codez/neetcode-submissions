class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq ; 
        for ( int i = 0 ; i < stones.size() ; i ++ ){
            int e = stones[i]; 
            pq.push(e);
        }

        while (pq.size()>1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
             pq.pop();

            if( a>b )pq.push(a-b);
            if(b>a) pq.push(b-a);


        }
        if (pq.size() == 0 ) return 0 ; 
        return pq.top();
    }
};
