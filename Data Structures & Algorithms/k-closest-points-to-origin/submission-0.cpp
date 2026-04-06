class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<
            pair<int, vector<int>>,
            vector<pair<int, vector<int>>>,
            greater<pair<int, vector<int>>>
        > pq;

        // push all points
        for (auto &p : points) {
            int d = p[0]*p[0] + p[1]*p[1];
            pq.push({d, p});
        }

        vector<vector<int>> ans;

        // take k closest
        while (k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};