#include<stdio.h>
#define MAX_CAP 100

int main(){
    int arr[MAX_CAP];
    int total_element = 0;
    int delete_index =0;

    printf("Enter the total numbers of value for the user to store: ");
    scanf("%d", &total_element);

    for(int i =0; i<total_element; i++){
        printf("Array[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("\narray is: ");
    for(int i =0; i<total_element; i++){
        printf("%d ", arr[i]);
    }
6
    printf("\nEnter value index to delete: ");
    scanf("%d", &delete_index);

    for(int i = delete_index; i<total_element; i++){
        arr[i] = arr[i+1];
        total_element--;
    }

    printf("\narray is: ");
    for(int i =0; i<total_element; i++){
        printf("%d ", arr[i]);
    }


    return 0;
}