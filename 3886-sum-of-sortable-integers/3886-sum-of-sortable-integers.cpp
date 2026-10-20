class Solution {
public:
    void computeLPS(vector<int>& pattern, vector<int>& lps)
    {
        int M = pattern.size();
        int len=0;
        lps[0]=0;
        int i=1;
        while(i<M)
        {
            if(pattern[i]==pattern[len])
            {
                len++;
                lps[i]=len;
                i++;
            }
            else
            {
                if(len!=0)
                    len=lps[len-1];
                else
                {
                    lps[i]=0;
                    i++;
                }
            }
        }
    }
    bool KMPSearch(vector<int>& pat, vector<int>& txt)
    {
        if (pat.empty()) 
            return txt.empty();
        int N = txt.size();
        int M = pat.size();
        vector<int> lps(M,0);
        computeLPS(pat,lps);

        int i=0,j=0;
        while(i<N)
        {
            if(pat[j]==txt[i])
            {
                i++;
                j++;
            }
            if(j==M)
                return true;
            else if(i<N && pat[j]!=txt[i])
            {
                if(j!=0)
                    j=lps[j-1];
                else
                    i++;
            }
        }
        return false;;
    }
    bool rotate(vector<int>& v1, vector<int>& v2)
    {
        vector<int> temp = v2;
        v2.insert(v2.end(), temp.begin(), temp.end());
        return KMPSearch(v1,v2);
    }
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(),sorted.end());
        int ans=0;
        for(int k=1;k<=n;k++)
        {
            if(n%k!=0)
                continue;
            bool valid = true;
            for(int st=0 ; st<n ; st+=k)
            {
                vector<int> v1(nums.begin()+st, nums.begin()+st+k);
                vector<int> v2(sorted.begin()+st, sorted.begin()+st+k);
                if(!rotate(v1,v2))
                {
                    valid = false;
                    break;
                }
            }
            if(valid)
                ans+=k;
        }
        return ans;
    }
};