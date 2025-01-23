#include<bits/stdc++.h>
using namespace std;

//Map stores unique values in pair 

void print(map<int, string> &map){
    cout<< map.size() <<endl;
    for(auto it : map){
        cout<< it.first <<" " << it.second <<endl; // access complexity is O(log(n))
    }
}

int main(){
    map<int, string> m;
    m[1] = "S1"; //this will get stored in sorted order
    m[3] = "S3"; // O(log(n)) -- > for inserting any value
    m[2] = "S2";
    m[2] = "S5"; //this will preplace the original one as keys are unique
    m.insert({4, "S4"});
    //cout<< m.size() <<endl; // this will print the sie of the map

    //different ways to print the values
    // for(auto it = m.begin(); it != m.end(); ++it){
    //     cout<<(*it).first <<"--> "<< (*it).second <<endl;
    //     cout<< it->first <<"--> "<< it->second <<endl;
    // }
    // for(auto &pr : m){
    //     cout<< pr.first << " " << pr.second <<endl;
    // }

    auto it  = m.find(7); //find function returns an iterator
    if(it == m.end()){
        cout<<"NO value" <<endl;
    }else{
        cout<< (*it).first << " " <<(*it).second <<endl;
    }

    m.erase(3); //this deletes a pair

    print(m);

    map<string, string> m2;
    m2["abcd"] = "bnjg"; //s.size()* log(n)




    return 0;
}