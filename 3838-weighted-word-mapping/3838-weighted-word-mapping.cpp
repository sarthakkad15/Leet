class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        for(string s:words)
        {
            int weight=0;
            for(char c:s)
            {
                weight+=weights[c-'a'];
            }
            weight%=26;
            ans.push_back((char)(97+25-weight));
        }
        return ans;
    }
};