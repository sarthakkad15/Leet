class Solution {
public:
    bool consecutiveSetBits(int n) {
        string bits="";
        while(n>0)
        {
            bits+=(n&1)+'0';
            n>>=1;
        }
        int s=bits.size(),ans=0;
        for(int i=1;i<s;i++)
        {
            if(bits[i]=='1' && bits[i-1]=='1')
                ans++;
        }
        return ans==1;
    }
};