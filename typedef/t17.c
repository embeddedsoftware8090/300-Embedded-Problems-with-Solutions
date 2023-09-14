#include <stdio.h>

typedef short MyShort;
typedef long MyLong;

int main() {
    MyShort s = 32767;
    MyLong l = 2147483647;
    printf("Short: %hd, Long: %ld\n", s, l);
    return 0;
}
