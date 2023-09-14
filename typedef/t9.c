#include <stdio.h>

typedef struct {
    char name[20];
    int age;
} Person;

int main() {
    Person john;
    strcpy(john.name, "John");
    john.age = 30;
    printf("Name: %s, Age: %d\n", john.name, john.age);
    return 0;
}

