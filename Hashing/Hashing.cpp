#include <bits/stdc++.h>
using namespace std;

int main(){
//input the num of elements in the array
    int n;
    cin>>n;
//input the array elements
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    //precompute
    /*here the hash is storing the num of dublicate elements in the array*/
    int hash[12] = {0};
    for(int i = 0; i<n; i++){
        hash[arr[i]] += 1;
    }
//the num to find dublicate for
    int q;
    cin>>q;

    while(q--){
        int num;
        cin>>num;

        cout<< hash[num] <<endl;

    }




    return 0;
}