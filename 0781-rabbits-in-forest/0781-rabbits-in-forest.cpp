class Solution {
public:
    static bool compare(const int a, const int b)
    {
        return a>b;
    }
    int numRabbits(vector<int>& answers) {
        sort(answers.begin(),answers.end(),compare);
        int n=answers.size(),c=0,s;
        for(int i=0;i<n;i++)
        {
            c+=answers[i]+1;
            s=answers[i];
            while(i<n-1 && s>0 && answers[i+1]==answers[i])
            {
                i++;
                s--;
            }
        }
        return c;
    }
};