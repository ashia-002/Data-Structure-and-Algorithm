#include <iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> numbers;
    //numbers.push_back(0); //inserting number 0
    for(int i = 1; i<=10; i++){
        numbers.push_back(i);
    }
    //print elements
    for(int number : numbers){
        cout<< number <<endl;
    }

    //using iterators . Iterators are like special function that point to some important location in your vector
    //two important location start and end

    //another method for printing elements
    for(auto iterator = numbers.begin(); iterator != numbers.end(); iterator++ ){
        *it = 20; //this will change all the value
        //to not change any value constant iterator is used --> cbegin() and cend()
        cout<< *iterator <<endl; //print the value of the iterator 
        //cout<< &iterator <<endl; //print the address of the iterator
        //cout<< &(*iterator) <<endl; //print the address of the element
    }

    //Various functionalities of vector
    cout<<"Size: "<<numbers.size()<<endl; //current size of the vector or the number of elements inside the vector
    cout<<"Max Size: "<<numbers.max_size()<<endl; //maximum size or maximum elements that i can enter
    cout<<"Capacity: "<<numbers.capacity()<<endl; //how many element we can add before resizing
    numbers.resize(5); //resize into the specified size
    cout<<"Size: "<< numbers.size() <<endl; //new size which is 5
    if(numbers.empty()){
        cout<<"Vector is empty"<<endl;
    }else{
        cout<<"Vector is not empty"<<endl;
    }
    cout<<"Element [0] os: "<<numbers[0]<<endl; //two ways to access elements
    cout<<"Element at (0) is: "<<numbers.at(0) <<endl;
    cout<<"Front: "<<numbers.front()<<endl; // the first element
    cout<<"Back: "<<numbers.back()<<endl; //prints the last element
    numbers.clear(); //Going to delete all element
    cout<<"Size: "<< numbers.size() <<endl; //Now the size will be zero

    //arithmetic operation using vectors
    auto it = numbers.begin();
    cout<< *(it + 5) <<endl; //here this begins from index 0 and prints the elemnt from 5th index



    return 0;
}