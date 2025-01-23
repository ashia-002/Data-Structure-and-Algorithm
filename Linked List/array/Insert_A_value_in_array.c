#include<stdio.h>
#define MAX_CAP 100

int main(){
    int arr[MAX_CAP];
    int total_element=0;
    int insert_index=0;
    int insert_value=0;

    printf("Enter the total numbers of values for the user to store: ");
    scanf("%d", &total_element);

//Prompts user for numbers to store in a Array.
    for(int i=0; i<total_element; i++){
        printf("Array[%d] = ",i);
        scanf("%d", &arr[i]);
    }

//Prints the taken elements 
    printf("\nArray is: ");
    for(int i=0; i<total_element; i++){
        printf("%d ", arr[i]);
    }

//Inserts a given value into a given index.
    printf("\nEnter the value to insert: ");
    scanf("%d", &insert_value);

    printf("Enter the index to insert the value: ");
    scanf("%d", &insert_index);

    for(int i = total_element; i >insert_index; i-- ){  //0 1 2 3 4 5
        arr[i]=arr[i-1];                       // 5 4 3 2 1 0
    }
    arr[insert_index] = insert_value;
    total_element++;

//Prints the new Array.
    printf("\nArray is: ");
    for(int i=0; i<total_element; i++){
        printf("%d ", arr[i]);
    }





    return 0;

}