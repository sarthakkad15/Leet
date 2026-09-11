class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_map<int,int> m;
        int n=digits.size();
        int ans=0;
        for(int i:digits)
        {
            m[i]++;
        }
        for(int i:{2,4,6,8,0})
        {
            if(m.find(i) == m.end())
                continue;
            m[i]--;

            for(int j=1;j<=9;j++)
            {
                if(m.find(j) == m.end() || m[j] == 0)
                    continue;
                m[j]--;

                for(auto k:m)
                {
                    if(k.second>0)
                        ans++;
                }
                m[j]++;
            }
            m[i]++;
        }
        return ans;
    }
};