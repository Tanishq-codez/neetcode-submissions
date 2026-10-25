class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack <int> s ;
        for ( string op : operations){
            

            if ( op == "+"){
            int s1 = s.top();
            s.pop();

            int s2 = s.top();
            s.push(s1);

            s.push(s1+s2);
            }

            else if ( op =="C"){
                s.pop();
            }

            else if ( op == "D"){
                s.push(2*s.top());
            }

            else  s.push(stoi(op));
        }
        int ans  = 0 ;
        while(!s.empty()){
            ans+=s.top() ;
            s.pop();
        }

        return ans ; 
    }
};