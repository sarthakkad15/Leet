class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int time=requests[0],n1=requests.size();
        for(int i=1;i<n1;i++)
        {
            time+=abs(requests[i]-requests[i-1]);
        }
        return time;
    }
};