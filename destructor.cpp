#include<iostream>
using namespace std;
#include"Student.cpp"
int main(){
    Student s1(10,1001);
    Student s2(20,2001);
    Student*s3=new Student(30,3001);
    delete s3; //for dynamically created objects we need to delete them to call the destructor
    return 0;
}