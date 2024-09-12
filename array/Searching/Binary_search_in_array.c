//It is extreamly important that the array is sorted for Binary search if not the output will be incorrect.

#include<stdio.h>

int BinarySearch(int arr[], int size, int key){
    int start = 0;
    int end = size - 1;

    while (start <= end)
    {
        int mid = (start+end)/2;

        if(arr[mid] == key){
            return mid;

        }else if(arr[mid]>key){
            end = mid - 1;
            
        }else{
            start = mid + 1;
        }
           
    }
    return -1;
    
}



int main(){

    int num;
    printf("Enter the maximum element you want to enter: ");
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

     int indax = BinarySearch(array, num, N);
    if(indax == -1){
        printf("\nThe element is not in the array.");
    }else{
        printf("\nThe element is in %dth position.", indax);
    }


    return 0;
}