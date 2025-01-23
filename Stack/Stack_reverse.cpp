#include<iostream>
#include<stack>
#include<string>
#include<sstream>//for string stream
using namespace std;

//Function to reverse a string
void ReverseWord(string s){
    //Creating a stack named st.
    stack<string> st;  

    //without space words are being stored in string word.
    for(int i = 0; i<s.length(); i++){
        string word = "";
        while(s[i]!=' ' && i<s.length()){
            word+=s[i];
            i++;
        }
        st.push(word);//pushing each word into stack st
    }

    //printing the top element of the stack
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

//Another function to reverse a string sentance
string reverse_sentance(const string &input){
    stringstream ss(input);
    stack<string> st;
    string word, reverseString;

    while(ss >> word){ // ss >> word, it reads the next word (sequence of characters separated 
                       //by whitespace) from the stringstream ss and stores it in the word variable.
        st.push(word);
    }

    while(!st.empty()){
        reverseString+=st.top() + ' ';
        st.pop();
    }

    if(!reverseString.empty()){
        reverseString.pop_back();
    }

    return reverseString;

}

string Reverse_character(const string &input){
    stack<char> CharStack;

    for(char c : input){
        CharStack.push(c);
    }

    string ReverseInput;
    while(!CharStack.empty()){
        ReverseInput += CharStack.top();
        CharStack.pop();
    }

    return ReverseInput;
}

int main(){

    string sentance = "Hey! how are you doing ?";
    //ReverseWord(sentance);
    //string output = reverse_sentance(sentance);
    string output = Reverse_character(sentance);
    cout<<output<<endl;


    return 0;
}
