class Solution {
public:
    int carFleet(int target, vector<int>& p, vector<int>& s) {
        vector<pair<int,int>> v;

        for (int i = 0; i < p.size(); i++) {
            v.push_back({p[i], s[i]});
        }

        sort(v.begin(), v.end(), greater<pair<int,int>>());

        stack<double> st;

        for (int i = 0; i < v.size(); i++) {
            double time = (double)(target - v[i].first) / v[i].second;

            if (!st.empty() && time <= st.top()) {
                continue;
            }

            st.push(time);
        }

        return st.size();
    }
};