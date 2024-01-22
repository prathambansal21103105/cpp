#include<iostream>   //if we make our own constructor then the default will not automatically work we need to make a new default constructor
using namespace std;  //whenever we pass arguments while creating an object the constructor checks the address of the object through this and put those values over there
#include"Student.cpp"
int main(){
    Student s1(10,1001);
    cout<<"Address of s1: "<<&s1<<endl;

    Student s2(20);
    s2.display();
    // Student s1;
    // s1.display();

    // Student s2;
    // s2.display();

    // Student*s3=new Student;
    // s3 -> display();

    // cout<<"Parameterized Constructors Demo"<<endl;
    // Student s4(10);
    // s4.display();

    // Student* s5=new Student(101);
    // s5 -> display();

    // Student s6(20,102);
    // s6.display();

    return 0;
}