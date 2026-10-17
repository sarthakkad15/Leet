class Solution {
public:
    static int digit_sum(int n)
    {
        int sum=0;
        while(n!=0)
        {
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    static bool compare(const pair<int,int> a, const pair<int,int> b)
    {
        int x=digit_sum(a.first),y=digit_sum(b.first);
        if(x==y)
            return a<b;
        return x<y;
    }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++)
        {
            arr.push_back({nums[i], i});
        }
        sort(arr.begin(), arr.end(), compare);
        vector<bool> visited(n, false);
        int swaps = 0;
        for (int i = 0; i < n; i++) 
        {
            if (visited[i] || arr[i].second == i)
                continue;
            int cycle = 0;
            int j = i;
            while (!visited[j]) 
            {
                visited[j] = true;
                j = arr[j].second;
                cycle++;
            }
            swaps += cycle - 1;
        }
        return swaps;
    }
};