
//THis will swap the last element with the first element
#include<stdio.h>

int main(){
    int num;
    printf("Enter the maximum element of the array: ");
    scanf("%d", &num);

    int arr[num];
    for(int i =0; i<num; i++){
        scanf("%d", &arr[i]);
    }
    
    for(int i=0; i<num-1; i++){
        for(int j= i+1; j<num; j++){
            if(arr[j]<arr[i]){
            int temp= arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            }
        }
    }
    
    for(int i =0; i<num; i++){
        printf("%d ", arr[i]);
    }
    
    return 0;

    
}