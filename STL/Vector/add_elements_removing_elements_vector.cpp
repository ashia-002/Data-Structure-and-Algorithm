#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> number;
    for(int i = 1; i<=10; i++){
        number.push_back(i);
    } 

    number.insert(number.begin() + 5, 88); //here in 5th indax the element 88 will be inserted

    for(auto n : number){ //printing elements
        cout<<n<<endl;
    }
    
    number.erase(number.begin() + 5); //this will delete the element in 5th index
    number.pop_back(); //this will delete the last element

    for(auto n : number){ //printing elements
        cout<<n<<endl;
    }


    return 0;
}