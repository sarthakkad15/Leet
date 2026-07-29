class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        stack<char> st;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                st.push(s[i]);
                continue;
            }
            if(s[i]=='(')
                st.push(s[i]);
            else
                st.pop();
            if(!st.empty())
                ans.push_back(s[i]);
        }
        return ans;
    }
};