class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> mapS(26,0);
        vector<int> mapT(26,0);
        if(s.size()!=t.size())
            return false;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            mapS[s[i]-'a']++;
            mapT[t[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(mapS[i]!=mapT[i])
                return false;
        }
        return true;
    }
};