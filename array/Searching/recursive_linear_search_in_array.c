#include<stdio.h>

int recursive_linear_search(int arr[], int size, int key){
    if(size == 0){
        return -1;
    }

    if(arr[size-1] == key)
        return size-1;
    
    return recursive_linear_search(arr, size-1, key);
}



int main(){

    int num;
    printf("Enter the maximum elements you ant to enter: ");
    scanf("%d", &num);
    int array[num];

    for(int i = 0; i< num; i++){
        printf("\nIndax[%d]= ", i);
        scanf("%d", &array[i]);
    }

    printf("\nThe Array is: ");
    for(int i = 0; i< num; i++){
        printf("%d ", array[i]);
    }
    int N;
    printf("\nEnter the element you want to search: ");
    scanf("%d", &N);

    int index = recursive_linear_search(array, num, N);
    if(index == -1){
        printf("\nThe element is not in the array.");

    }else{
        printf("\nThe element is in the %dth position. And the element is %d", index, N);
    }



    return 0;
}