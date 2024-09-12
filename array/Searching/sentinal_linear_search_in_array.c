#include<stdio.h>

int SentinalSearch(int arr[], int size, int key){
    int last = arr[size-1];
    arr[size-1] = key;

    int i = 0;
    while(arr[i] != key)
        i++;

    arr[size-1] = last;
    if((i<size-1) || arr[size-1] == key)
        return i;
    else
        return -1;    
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

    int index = SentinalSearch(array, num, N);
    if(index == -1)
        printf("\nThe element is not in the array.");
    else
        printf("\nThe element is in %dth position. And the element is %d.", index, N);




    return 0;
}