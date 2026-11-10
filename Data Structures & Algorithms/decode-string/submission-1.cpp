class Solution {
public:
    string decodeString(string s) {
        int i = s.size() - 1;

        stack<char> st;

        while (i >= 0) {
            if (s[i] == '[') {
                i--;

                int n = 0;
                int place = 1;

                while (i >= 0 && isdigit(s[i])) {
                    n += (s[i] - '0') * place;
                    place *= 10;
                    i--;
                }

                string temp = "";

                while (!st.empty() && st.top() != ']') {
                    temp += st.top();
                    st.pop();
                }

                if (!st.empty()) st.pop();

                string repeated = "";

                for (int j = 0; j < n; j++) {
                    repeated += temp;
                }

                for (int j = repeated.size() - 1; j >= 0; j--) {
                    st.push(repeated[j]);
                }
            }
            else {
                st.push(s[i]);
                i--;  
                continue;
            }
        }

        string res = "";

        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        return res;
    }
};