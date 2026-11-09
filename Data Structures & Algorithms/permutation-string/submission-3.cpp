class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> m1;
        int l1 = s1.length();
        for (char c : s1) {
            m1[c]++;
        }

        int i = 0, j = 0;

        unordered_map<char, int> m2;

        while (j < l1) {
            m2[s2[j]]++;
            j++;
        }

        

        while (j <=s2.size()) {
            if (m1 == m2) return true;
            m2[s2[i]]--;

            if (m2[s2[i]] == 0) {
                m2.erase(s2[i]);
            }

            m2[s2[j]]++;

            
            i++;
            j++;
        }

        return false;
    }
};
