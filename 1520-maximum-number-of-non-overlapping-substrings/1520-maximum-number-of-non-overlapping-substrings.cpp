class Solution {
public:
    static bool ord(const pair<int,int> &a, const pair<int,int> &b)
    {
        return a.second<b.second;
    }
    vector<string> maxNumOfSubstrings(string s) {
        unordered_map<int,pair<int,int>> m;
        vector<bool> vs(26,false);
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(vs[s[i]-'a'])
                continue;
            m[s[i]-'a'].first=i;
            m[s[i]-'a'].second=n-1-(find(s.rbegin(),s.rend(),s[i])-s.rbegin());
            vs[s[i]-'a']=true;
        }
        vector<pair<int,int>> v;
        for(int c = 0; c < 26; c++)
        {
            if(!vs[c])
                continue;
            int l = m[c].first;
            int r = m[c].second;
            bool valid = true;
            for(int j = l; j <= r; j++)
            {
                int x = s[j] - 'a';
                if(m[x].first < l)
                {
                    valid = false;
                    break;
                }
            r = max(r, m[x].second);
            }

            if(valid)
                v.push_back({l,r});
        }
        sort(v.begin(), v.end(), ord);
        vector<string> ans;
        ans.push_back(s.substr(v[0].first,v[0].second-v[0].first+1));
        int last=v[0].second;
        for(int i=1;i<v.size();i++)
        {
            if(v[i].first<=last)
                continue;
            ans.push_back(s.substr(v[i].first,v[i].second-v[i].first+1));
            last=v[i].second;
        }
        return ans;
    }
};