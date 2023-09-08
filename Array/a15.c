#include <stdio.h>
void printTwoRepeatNumber (int arr [], int size)
{
    int i, j;
    printf("Repeating elements are ");
    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (arr [i] == arr [j])
            {
                printf("%d ", arr [i]);
                break;
            }
        }
    }
}
int main ()
{
    int arr [] = { 4, 2, 4, 5, 2, 3, 1 };
    int arr_size = sizeof(arr) / sizeof(arr [0]);
    printTwoRepeatNumber (arr, arr_size);
    return 0;
}
