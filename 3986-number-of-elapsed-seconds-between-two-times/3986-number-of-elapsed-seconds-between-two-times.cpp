class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int time = 0;
        time += 60*60*((endTime[0]*10+endTime[1]) - (startTime[0]*10+startTime[1]));
        time += 60*((endTime[3]*10+endTime[4]) - (startTime[3]*10+startTime[4]));
        time += (endTime[6]*10+endTime[7]) - (startTime[6]*10+startTime[7]);
        return time;
    }
};