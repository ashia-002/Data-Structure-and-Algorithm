#include<bits/stdc++.h>
using namespace std;

void sortDocuments(vector<string> &docs){
    for(int i = 0; i<docs.size()-1; i++){
        for(int j = 0; j<docs.size() - i - 1; j++){
            if(docs[j] > docs[j+1]){
                swap(docs[j], docs[j+1]);
            }
        }
    }
}

int main(){
    vector<string> documentTopic;
    string input;
    cout<<"Input the documents by their topic(input END to stop): ";
    while(cin>>input){
        if(input == "END") break;
        documentTopic.push_back(input);
    }

    sortDocuments(documentTopic);

    cout<<"Sorted documents by their topic: "<<endl;
    for(const auto &doc : documentTopic){
        cout<<doc<<endl;
    }

    return 0;
}