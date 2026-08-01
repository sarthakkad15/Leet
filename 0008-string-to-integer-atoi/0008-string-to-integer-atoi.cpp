class Solution {
public:
    int myAtoi(string s) {
        int n=s.size(),i=0,sign=1;
        long long ans=0;
        while(i<n && s[i]==' ')
            i++;
        if(s[i]=='+')
            i++;
        else if(s[i]=='-')
        {
            sign=-1;
            i++;
        }
        while(i<n && s[i]=='0')
            i++;
        for(;i<n;i++)
        {            
            if(((s[i]-'0')>=0 && (s[i]-'0')<=9) && ans<INT_MAX)
                ans=ans*10+(s[i]-'0');
            else
                break;
        }
        if((sign*ans)>=INT_MAX)
            return INT_MAX;
        else if((sign*ans)<=INT_MIN)
            return INT_MIN;
        else
            return sign*ans;

    }
};