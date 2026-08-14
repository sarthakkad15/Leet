class Solution {
public:
    void solve(string num, int target, int start, long long curr_val, long long prev_num, string exp, vector<string>& ans, int n)
    {
        if(start==num.length())
        {
            if(curr_val==target)
                ans.push_back(exp);
            return;
        }
        for(int i=start;i<n;i++)
        {
            if(i>start && num[start]=='0')
                return;
            string curr_num=num.substr(start,i-start+1);
            long long curr_num_val=stoll(curr_num);
            if(start==0)
                solve(num,target,i+1,curr_num_val,curr_num_val,curr_num,ans,n);
            else
            {
                solve(num,target,i+1,curr_val+curr_num_val,curr_num_val,exp+"+"+curr_num,ans,n);
                solve(num,target,i+1,curr_val-curr_num_val,-curr_num_val,exp+"-"+curr_num,ans,n);
                solve(num,target,i+1,curr_val-prev_num+prev_num*curr_num_val,prev_num*curr_num_val,exp+"*"+curr_num,ans,n);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        int n=num.size();
        vector<string> ans;
        solve(num,target,0,0,0,"",ans,n);
        return ans;
    }
};