class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.length(),c=0;
        vector<int> mp(52,0);
        for(int i=0;i<n;i++)
        {
            if(word[i]>='a' && word[i]<='z')
                mp[word[i]-97]=1;
            if(word[i]>='A' && word[i]<='Z')
                mp[word[i]-65+26]=1;
        }
        for(int i=0;i<26;i++)
        {
            if(mp[i]==1 && mp[i+26]==1)
                c++;
        }
        return c;
    }
};