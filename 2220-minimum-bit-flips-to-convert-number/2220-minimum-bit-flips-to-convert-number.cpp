class Solution {
public:
    int minBitFlips(int start, int goal) {
        int check=start^goal,c=0;
        while(check)
        {
            check&=check-1;
            c++;
        }
        return c;
    }
};