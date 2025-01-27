//"abcdabcgc" how many times "a" appears or some other character appers
/*for upper case we can use 'ch' - 'A' */
//by doing 'ch' - 'a'(substracting ASSCI value of character 'a' from other character) we can get the coresponding indax
#include<bits/stdc++.h>
using namespace std;

int main(){
    //Taking a big string
    string s;
    cin>>s;

    int hash[26] = {0};
    for(int i = 0; i<s.size(); i++){
        hash[s[i] - 'a']++;//for all character hash[s[i]]
    }

    //Taking the characters for counting
    int q;
    cin>>q;
    while(q--){
        char c;
        cin>>c;
        //fetch
        cout<<hash[c - 'a']<<endl; //for all character hash[c]

    }
    


    return 0;
}
