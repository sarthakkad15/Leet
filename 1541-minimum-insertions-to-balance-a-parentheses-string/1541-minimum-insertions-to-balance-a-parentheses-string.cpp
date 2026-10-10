class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int n=s.length(),c=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
                st.push(s[i]);
            else
            {
                if(i==n-1 || s[i+1]!=')')
                    c++;
                else
                    i++;
                if(st.empty())
                    c++;
                else
                    st.pop();
            }
        }
        while(!st.empty())
        {
            st.pop();
            c+=2;
        }
        return c;
    }
};