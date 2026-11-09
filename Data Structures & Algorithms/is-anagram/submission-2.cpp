class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map < char , int > m1;
        unordered_map < char , int > m2;

        for (int i = 0 ; i < s.size() ; i ++){
            char key = s[i];
            m1[key]++;
        }
        for (int j = 0 ; j < t.size() ;j++){
            char key = t[j];
            m2[key]++;
        }

        if (m1 == m2) return true ; 
        else return false ; 
    }
};
