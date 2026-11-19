class TimeMap {
   public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {}

    void set(string key, string value, int timestamp) { mp[key].push_back({timestamp, value}); }

    string get(string key, int timestamp) {
        string res = "";

        int s = 0;
        int e = mp[key].size()-1;
        int m;
        auto& v = mp[key];

        if ( mp.find(key) == mp.end()) return res ; 

        while (s <= e) {
            m = s + (e - s) / 2 ;

            if ( v[m].first == timestamp){
                return v[m].second;
            }

            if (v[m].first < timestamp){
                res = v[m].second;
                s = m + 1 ;
            }

            else {
                e = m - 1; 
            }
        }

        return res;
    }
};
