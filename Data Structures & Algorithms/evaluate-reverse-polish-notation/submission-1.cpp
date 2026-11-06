class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string& s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int two = st.top();
                st.pop();
                int one = st.top();
                st.pop();

                if (s == "+") st.push(one + two);
                else if (s == "-") st.push(one - two);
                else if (s == "*") st.push(one * two);
                else st.push(one / two);
            } else {
                st.push(stoi(s));
            }
        }

        return st.top();
    }
};