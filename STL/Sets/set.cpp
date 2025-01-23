//sets --- > stores unique keys
#include<bits/stdc++.h>
using namespace std;

void print(set<string> &s){
    for(string value : s){
       cout<< value << endl; //prints in sorted order
    }

    // for(auto it = s.begin(); it != s.end(); ++it){
    //    cout<< (*it) << endl; 
    // }
}

int main(){
    set<string> s;//any data type can be stored
    s.insert("abc"); //log(n)
    s.insert("xyz");
    s.insert("bcd");
    s.insert("abc");
    // auto it = s.find("abc"); //O log(n)
    // if(it != s.end()){
    //     cout<< (*it) <<endl;
    // }
    auto it2 = s.find("abc");
    if(it2 != s.end()){
        s.erase(it2);
    }

    cout<<"Printing the values: "<<endl;
    print(s);


    return 0;
}