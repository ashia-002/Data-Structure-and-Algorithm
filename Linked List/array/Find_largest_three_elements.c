#include <stdio.h>
#include <limits.h> //for INT_MIN

void find_3leargest(int arr[], int size)
{

    int i, first, second, third;
    if (size < 3)
    {
        printf("Invalid Input....");
        return;
    }
    first = second = third = INT_MIN;
    for (i = 0; i < size; i++)
    {
        if (arr[i] > first)
        {
            third = second;
            second = first;
            first = arr[i];
        }
        else if (arr[i] > second && arr[i] != first)
        {
            third = second;
            second = arr[i];
        }
        else if (arr[i] > third && arr[i] != second && arr[i] != first)
        {
            third = arr[i];
        }
    }

    printf("\nThree largest elements are %d %d %d.", first, second, third);
}

int main()
{

    int array[] = {10, 4, 3, 50, 23, 90};
    int size = sizeof(array) / sizeof(array[0]);
    find_3leargest(array, size);

    return 0;
}