class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        string start;
        if(arriveAlice>arriveBob)
            start=arriveAlice;
        else
            start=arriveBob;
        string end;
        if(leaveBob>leaveAlice) 
            end=leaveAlice;
        else
            end=leaveBob;
        if(start>end)
            return 0;
        int startMonth=stoi(start.substr(0,2));
        int endMonth=stoi(end.substr(0,2));
        int startDay=stoi(start.substr(3,2));
        int endDay=stoi(end.substr(3,2));
        if(startMonth==endMonth)
            return endDay-startDay+1;
        vector<int> months = {31,28,31,30,31,30,31,31,30,31,30,31};
        int days=months[startMonth-1]-startDay+1;
        startMonth++;
        while(startMonth<endMonth)
        {
            days+=months[startMonth-1];
            startMonth++;
        }
        days+=endDay;
        return days;
    }
};