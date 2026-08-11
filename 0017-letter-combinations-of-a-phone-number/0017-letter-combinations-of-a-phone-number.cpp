class Solution {
public:
    void generate(vector<vector<char>>& hash, string digits, vector<string>& ans,int idx,string curr)
    {
        if(curr.length()==digits.length())
        {
            ans.push_back(curr);
            return;
        }
        int num=digits[idx]-'0';
        for(int i=0;i<hash[num].size();i++)
        {
            curr.push_back(hash[num][i]);
            generate(hash,digits,ans,idx+1,curr);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<vector<char>> hash(10);
        string curr;
        hash[2]={'a','b','c'};
        hash[3]={'d','e','f'};
        hash[4]={'g','h','i'};
        hash[5]={'j','k','l'};
        hash[6]={'m','n','o'};
        hash[7]={'p','q','r','s'};
        hash[8]={'t','u','v'};
        hash[9]={'w','x','y','z'};
        vector<string> ans;
        generate(hash,digits,ans,0,curr);
        return ans;
    }
};