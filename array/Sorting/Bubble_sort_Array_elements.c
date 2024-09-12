//In Bubble sort it will go by comparing two elements.
//comparisions will happen untill the whole array is sorted. 

#include<stdio.h>

int main () {
    int num;
    printf("Enter the maximum number of elements in the array: ");
    scanf("%d", &num);

    int arr[num];
    // Reading the elements of the array from the user
    for(int i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }

    int counter = 1;
    // Outer loop to control the number of passes
    while(counter < num) {
        // Inner loop for pairwise comparison and swapping
        for(int i = 0; i < num - counter; i++) {
            // If the current element is greater than the next element, swap them
            if(arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
        counter++;
    }
    printf("\nThe sorted list is: ");
    // Printing the sorted array
    for(int i = 0; i < num; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

//*************USe of Counter Variable**************
/*The counter variable is used to keep track of the number of passes through the array. 
In a bubble sort algorithm, each pass compares and possibly swaps adjacent elements, moving the 
largest element to its correct position at the end of the array. After each pass, the largest 
unsorted element is in its correct place, so there's no need to check it again in subsequent passes. 
Hence, we use the counter variable to control the number of passes. After each pass, counter is 
incremented until it reaches num - 1, which means that the array is fully sorted. This optimization 
reduces the number of unnecessary comparisons in the later passes, making the sorting process more 
efficient.*/
