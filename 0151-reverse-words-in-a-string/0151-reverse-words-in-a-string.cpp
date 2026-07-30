class Solution {
public:
    string reverseWords(string s) {
        int i=0,j=0,n=s.length();
        while(i<n)
        {
            while(i<n && s[i]==' ')
                i++;
            while(i<n && s[i]!=' ')
            {
                s[j]=s[i];
                i++;
                j++;
            }
            while(i<n && s[i]==' ')
                i++;
            if(i<s.length())
                s[j++]=' ';
        }
        s.resize(j);
        reverse(s.begin(),s.end());
        int start=0;
        for(int i=0;i<=j;i++)
        {
            if(i==j || s[i]==' ')
            {
                reverse(s.begin()+start,s.begin()+i);
                start=i+1;
            }
        }
        return s;
    }
};