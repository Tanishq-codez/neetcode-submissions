class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort( people.begin() , people.end());
        
        int n = 0 ; 
        for (int i = 0 , j = people.size()-1 ; i <= j  ; ){
        
        if ( i == j ){
            n++ ;
            break ; 
        }
        if ( people[i] + people[j] <= limit) {
            i++ ;
            j-- ;
        }

        else j -- ; 

        n++ ; 
        }

        return n ; 
    }
};