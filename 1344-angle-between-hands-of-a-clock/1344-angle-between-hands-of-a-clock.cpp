class Solution {
public:
    double angleClock(int hour, int minutes) {
        double H,M,A;
        if(hour!=12)
            H=hour+(minutes*1.0/60);
        else
            H=minutes*1.0/60;
        M=minutes*1.0/5;
        A=(abs(H-M)/12)*360;
        if(A<180)
            return A;
        else
            return 360-A;
    }
};