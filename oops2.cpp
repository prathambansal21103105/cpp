#include<iostream>
using namespace std;
#include"Student2.cpp"

int main(){
    char name[]="abcd";
    Student s1(20,name);  //here the object copied the address of the char array
    s1.display();         //called shallow copy

    Student s2(s1);        //copy constructor always creates a shallow copy;
    s2.name[0]='x';
    s1.display();
    s2.display();

    // name[3]='e';
    // Student s2(24,name);
    // s2.display();

    // s1.display();
    return 0;
}