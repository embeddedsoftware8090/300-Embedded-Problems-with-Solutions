#include <stdio.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    char name[20];
    int age;
} Person;

int main() {
    Point p = {10, 20};
    Person person = {"Alice", 30};
    printf("Point: (%d, %d), Person: %s, %d years old\n", p.x, p.y, person.name, person.age);
    return 0;
}
