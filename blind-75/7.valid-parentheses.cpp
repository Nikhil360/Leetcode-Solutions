class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if(s.size() < 2)
            return false;
        for(auto ch : s){
            switch(ch){
                case '(':
                    st.push(ch);
                    break;
                case '{':
                    st.push(ch);
                    break;
                case '[':
                    st.push(ch);
                    break;
                case ')':
                    if(st.empty() || st.top() != '(')
                        return false;
                    st.pop();
                    break;
                case '}':
                    if(st.empty() || st.top() != '{')
                        return false;
                    st.pop();
                    break;
                case ']':
                    if(st.empty() || st.top() != '[')
                        return false;
                    st.pop();
                    break;
            }
        }
        return st.empty() ? true : false;
    }
};