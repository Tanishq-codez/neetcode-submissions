class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
       
        stack<int> s ;
        ; 
        for ( int a : ast){
            if ( a > 0 ) s.push(a);

            else {
                int flag = 1 ;
                while ( !s.empty() && s.top()>0 ){
                if ( s.top() < abs(a)) s.pop();

                else if (s.top() > abs(a)){  flag = 0 ;  break  ;} 

                else if ( s.top() == abs(a)){
                    flag = 0 ; 
                    s.pop();
                    break ; 
                }
                } 
      
                if (flag) s.push(a) ;
            }

        }

        vector<int> res ;
        while( !s.empty()){
        res.push_back(s.top());
        s.pop();
        }

        reverse(res.begin() , res.end() );

        return res ;
    }
};