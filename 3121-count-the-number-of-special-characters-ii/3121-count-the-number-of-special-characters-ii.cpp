class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> first(26,-1);
        vector<int> last(26,-1);
        int c=0,n=word.length();;
        for(int i=0;i<n;i++)
        {
            if(word[i]>='A' && word[i]<='Z')
            {
                if(first[word[i]-65]==-1)
                    first[word[i]-65]=i;
            }
            if(word[n-i-1]>='a' && word[n-i-1]<='z')
            {
                if(last[word[n-i-1]-97]==-1)
                    last[word[n-i-1]-97]=n-i-1;
            }
        }
        for(int i=0;i<26;i++)
        {
            if(first[i]!=-1 && last[i]!=-1)
            {
                if(first[i]>last[i])
                    c++;
            }
        }
        return c;
    }
};