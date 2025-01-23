//Get the minimum and swap it
/*Time COmplexity
   Best, Average, worst O(n^2)*/
#include<bits/stdc++.h>
using namespace std;

void selectionSort(int a[], int size){
    for(int i = 0; i <= size-2; i++){
        int min = i;
        for(int j = i; j<= size-1;j++){
            if(a[j] < a[min]) min = j;
        }
        int temp = a[min];
        a[min] = a[i];
        a[i] = temp;

    }
}

int main(){
    // 13 46 24 52 20 9
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    selectionSort(arr, n);

    for(int i = 0; i<n; i++){
        cout << arr[i] <<" ";
    }





    return 0;
}