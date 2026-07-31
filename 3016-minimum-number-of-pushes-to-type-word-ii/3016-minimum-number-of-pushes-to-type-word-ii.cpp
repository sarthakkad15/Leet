class Solution {
public:
    int minimumPushes(string word) {
        int n=word.length();
        vector<int> map(26,0);
        for(int i=0;i<n;i++)
        {
            map[word[i]-'a']++;
        }
        sort(map.begin(),map.end());
        int pushes=1,ans=0;
        for(int i=25;i>=0;i--)
        {
            if(i==17 || i==9 || i==1)
                pushes++;
            ans+=map[i]*pushes;
        }
        return ans;
    }
};