class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.size() < t.size()) return "";

        vector<int> mapT(128, 0);
        vector<int> window(128, 0);

        int required = 0;
        for (auto &c : t) {
            mapT[c]++;
            if (mapT[c] == 1) required++;
        }

        int have = 0;
        int minL = INT_MAX;
        int startIdx = -1;

        int i = 0;
        for (int j = 0; j < (int)s.size(); j++) {
            window[s[j]]++;
            if (window[s[j]] == mapT[s[j]]) have++;

            while (have == required) {
                if (j - i + 1 < minL) {
                    minL = j - i + 1;
                    startIdx = i;
                }

                window[s[i]]--;
                if (window[s[i]] < mapT[s[i]]) {
                    have--;
                }
                i++;
            }
        }

        return startIdx == -1 ? "" : s.substr(startIdx, minL);
    }
};