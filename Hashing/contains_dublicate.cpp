#include <bits/stdc++.h>
using namespace std;

bool isContainDup( vector<int> &arr){
    unordered_set<int> hash;

// Iterate through each number in the array
    for(auto e : arr){
        // Check if the number is already in the set
        if(hash.find(e) != hash.end()){
            // Duplicate found if exists
            return true;
        }
        // if not found Add the number to the set
        hash.insert(e);
    }

    // No duplicates found
    return false;

}

int main(){

    vector<int> nums = {1, 2, 3, 4, 5, 2};
    if(isContainDup(nums)){
        cout<<"Yes, Contains Dublicate"<<endl;
    }else{
        cout<<"No, No Dublicates"<<endl;
    }


    return 0;
}