#include<iostream>
using namespace std;

void Merge(int arr[], int l, int m, int r){//passing left most index, middle index, right most index.

//finding the length of two devided array
    int n1 = m - l+1;
    int n2 = r - m;

//Initializing the two divided array
    int arr1[n1];
    int arr2[n2];

//Filling the Two array with elements from the actual array
    for(int i = 0; i<n1; i++){
        arr1[i] = arr[l + i];//arr1 with the first half elements
    }
    for(int j = 0; j<n2; j++){
        arr2[j] = arr[m+1 + j];//arr2 with the second half elements
    }

//Comparing the two divided arrays to find the smallest element. After finding the smallest element filling it in the actual array
    int i, j, k;
    i = 0;
    j = 0;
    k= l;
    while(i < n1 && j < n2){
        if(arr1[i] <= arr2[j]){
            arr[k] = arr1[i];
            i++;
        }else{
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

//While compareing if we get remaining elements in either of the two devided array we also fill those into the actual array.
    while(i<n1){
        arr[k] = arr1[i];
        i++;
        k++;
    }

    while(j<n2){
        arr[k] = arr2[j];
        j++;
        k++;
    }

}

//THe function to sort an array
void MergeSort(int arr[], int l,  int r){
    if(l < r){//if l is less that means there is only 1 element so the array doesn't need sorting
        int m = l + (r - l)/2;//finding the middle element
        
        //Breaking the array into smaller parts using recursion
        MergeSort(arr, l, m);
        MergeSort(arr, m+1, r);

        //Calling the merge function to merge the two
        Merge(arr, l, m, r);
    }
}

//Printing the sorted array
void PrintArray( int arr[], int size){
    cout<<"The Sorted array is: ";
    for(int i = 0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){

    int num;
    printf("enter the maximum element of array: ");
    scanf("%d", &num);

    int arr[num];
    for(int i = 0; i<num; i++){
        scanf("%d", &arr[i]);
    }

    MergeSort(arr, 0 , (num-1));

    PrintArray(arr, num);


    return 0;
}