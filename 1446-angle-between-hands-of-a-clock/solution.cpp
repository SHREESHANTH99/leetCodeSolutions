class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourAngle = (hour % 12) * 30.0 + minutes * 0.5;
        double minuteAngle = minutes * 6.0;
        double angle = abs(hourAngle - minuteAngle);
        return min(angle, 360.0 - angle);
    }
};
