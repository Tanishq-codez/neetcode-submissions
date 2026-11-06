class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;

        for (string s : tokens) {
            if (s == "+") {
                int two = stoi(st.top());
                st.pop();
                int one = stoi(st.top());
                st.pop();
                st.push(to_string(one + two));

            }

            else if (s == "-") {
                int two = stoi(st.top());
                st.pop();
                int one = stoi(st.top());
                st.pop();
                st.push(to_string(one - two));
            }

            else if (s == "/") {
                int two = stoi(st.top());
                st.pop();
                int one = stoi(st.top());
                st.pop();
                st.push(to_string(one / two));
            }

            else if (s == "*") {
                int two = stoi(st.top());
                st.pop();
                int one = stoi(st.top());
                st.pop();
                st.push(to_string(one *  two));
            } else
                st.push(s);
        }

        return stoi(st.top());
    }
};
