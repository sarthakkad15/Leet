class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0)
            return true;
        int s=flowerbed.size();
        if(s==1)
        {
            if(n>1 || (n==1 && flowerbed[0]==1))
                return false;
            else
                return true;
        }
        for(int i=0;i<s-1;i++)
        {
            if(flowerbed[i]==1)
                i++;
            else if(flowerbed[i+1]!=1)
            {
                flowerbed[i]=1;
                i++;
                n--;
                if(n==0)
                    return true;
            }
        }
        if(n>0 && flowerbed[s-2]==0 && flowerbed[s-1]==0)
        {
            flowerbed[n-1]=1;
            n--;
        }
        if(n!=0)
            return false;
        return true;
    }
};