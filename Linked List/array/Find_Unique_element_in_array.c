#include<stdio.h>

int main(){
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Elements inputted only once: ");
    for (int i = 0; i < size; i++) {
        int count = 0;
        for (int j = 0; j < size; j++) {
            if (i != j && arr[i] == arr[j]) {
                count++;
                break;
            }
        }
        if (count == 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");



    return 0;
}