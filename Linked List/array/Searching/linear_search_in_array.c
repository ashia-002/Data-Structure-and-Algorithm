#include<stdio.h>

int linear_search(int arr[], int n, int x){
    
    for(int i = 0; i<n; i++){
        if(arr[i]==x){
            return i;
        }
    }
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

    int indax = linear_search(array, num, N);
    if(indax == -1){
        printf("\nThe element is not in the array.");
    }else{
        printf("\nThe element is in %dth position.", indax);
    }






    return 0;
}