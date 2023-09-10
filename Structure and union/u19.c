#include <stdio.h>

// Define a structure for time
struct Time {
    int hours;
    int minutes;
    int seconds;
};

// Function to add two time durations
struct Time addTime(struct Time t1, struct Time t2) {
    struct Time sum;
    sum.hours = t1.hours + t2.hours;
    sum.minutes = t1.minutes + t2.minutes;
    sum.seconds = t1.seconds + t2.seconds;

    // Adjust for overflow
    if (sum.seconds >= 60) {
        sum.minutes += sum.seconds / 60;
        sum.seconds %= 60;
    }
    if (sum.minutes >= 60) {
        sum.hours += sum.minutes / 60;
        sum.minutes %= 60;
    }

    return sum;
}

// Function to convert time duration to seconds
int timeToSeconds(struct Time t) {
    return t.hours * 3600 + t.minutes * 60 + t.seconds;
}

int main() {
    // Initialize two time durations
    struct Time time1 = {1, 20, 0};
    struct Time time2 = {0, 50, 0};

    // Add the time durations
    struct Time sum = addTime(time1, time2);

    // Convert the sum to seconds
    int seconds = timeToSeconds(sum);

    printf("I/P: Time1: %dh %dm, Time2: %dh %dm; O/P: Sum: %dh %dm, Seconds: %ds\n",
           time1.hours, time1.minutes, time2.hours, time2.minutes, sum.hours, sum.minutes, seconds);

    return 0;
}
