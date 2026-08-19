class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        set<pair<int,int>> reserved;
        set<int> rows;
        for(auto i:reservedSeats)
        {
            reserved.insert({i[0],i[1]});
            rows.insert(i[0]);
        }
        int c = (n - rows.size()) * 2;
        vector<int> first_seat = {2,4,6};
        bool possible;
        for(int i:rows)
        {
            for(int j=0;j<3;j++)
            {
                possible=true;
                int first=first_seat[j];
                for(int k=0;k<4;k++)
                {
                    if(reserved.find({i,first+k})!=reserved.end())
                    {
                        possible=false;
                        break;
                    }
                }
                if(possible)
                {
                    c++;
                    j++;
                }
            }
        }
        return c;
    }
};