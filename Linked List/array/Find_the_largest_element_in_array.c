//example enter five numbers and find the largest among them.

#include<stdio.h>

int main(){
    int n;
    double arr[100];
    printf("Enter the number of elements you want to compare: ");
    scanf("%d", &n);
//Used for taking input into the number of elements. /*  for ++i sequence is 5 4 3 2 1  */
    for(int i=1; i<=n; i++){//if I don't write <= . I must write i+1 inside printf.
        printf("Enter the number %d: ", i);
        scanf("%lf", &arr[i]);
    }
//Used for comparing two arrays of input values
    for(int i =1; i<n; ++i){
        if(arr[0]<arr[i])
            arr[0]=arr[i];//If the input value is bigger storing it in arr[0].
    }

    printf("The largest number = %.2lf", arr[0]);
    return 0;
}