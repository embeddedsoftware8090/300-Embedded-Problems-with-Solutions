#include <stdio.h>

// Define a Date structure
struct Date {
    int day;
    int month;
    int year;
};

// Function to calculate the difference in days between two dates
int dateDifference(struct Date date1, struct Date date2) {
    // Days in each month (non-leap year)
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Calculate days in Date1
    int days1 = date1.year * 365 + date1.day;
    for (int i = 1; i < date1.month; i++) {
        days1 += daysInMonth[i];
    }
    if (date1.month > 2 && ((date1.year % 4 == 0 && date1.year % 100 != 0) || (date1.year % 400 == 0))) {
        days1 += 1; // Leap year adjustment
    }

    // Calculate days in Date2
    int days2 = date2.year * 365 + date2.day;
    for (int i = 1; i < date2.month; i++) {
        days2 += daysInMonth[i];
    }
    if (date2.month > 2 && ((date2.year % 4 == 0 && date2.year % 100 != 0) || (date2.year % 400 == 0))) {
        days2 += 1; // Leap year adjustment
    }

    // Calculate the difference in days
    int difference = days2 - days1;

    return difference;
}

int main() {
    // Define two date structures
    struct Date date1 = {15, 2, 2020};
    struct Date date2 = {20, 2, 2020};

    // Calculate the difference in days
    int daysDifference = dateDifference(date1, date2);

    // Print the result
    printf("I/P: Date1: %02d/%02d/%04d, Date2: %02d/%02d/%04d\n", date1.day, date1.month, date1.year, date2.day, date2.month, date2.year);
    printf("O/P: Diff: %d days\n", daysDifference);

    return 0;
}
