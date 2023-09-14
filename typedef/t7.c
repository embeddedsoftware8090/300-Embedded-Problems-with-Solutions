#include <stdio.h>

typedef enum {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY
} Weekday;

int main() {
    Weekday today = MONDAY;
    printf("Today is day %d\n", today);
    return 0;
}
