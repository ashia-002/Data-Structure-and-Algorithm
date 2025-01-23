/* 1. Inbuilt implementation -- uses hash
2. Time complexity
3. valid keys datatype
difference between time complexity
keys are inserted by comparesion
insertion and access = O(1)-->Average
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<int, string> m;
    m[1] = "abc" //O(1)
    m[2] = "def"
    m[3] = "ghi"
    m[4] = "jkl"

    auto it = m.find(3); //O(1)
    if(it != m.end()){
        m.erase(it); //log(1)
    }
}
