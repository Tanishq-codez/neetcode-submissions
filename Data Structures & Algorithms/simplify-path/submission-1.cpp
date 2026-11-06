class Solution {
   public:
    string simplifyPath(string path) {
        string temp = "";
        stack<string> s;
        path += '/';
        for (char c : path) {
            if (c == '/') {
                if (temp == "" || temp == ".") {
                temp = "";
                 continue;
                }

                if (temp == "..") {
                    if (!s.empty()) {
                        s.pop();
                    }
                }

                else {
                    s.push(temp);
                    
                }
                temp = "";
                continue;
            }

            temp.push_back(c);
        }

        string ans = "";
        while (!s.empty()) {
            ans = "/" + s.top() + ans;
            s.pop();
        }

        return ans.empty() ? "/" : ans;
    }
};