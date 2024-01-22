#include<iostream>
using namespace std;
#include"Student4.cpp"
int main(){
    Student s1;
    // cout<<s1.rollNumber<<endl;
    // cout<<s1.age<<endl;          // :: is scope resolution
    // s1.totalStudents=20;      
    // cout<<s1.totalStudents<<endl;  // it doesn't show error but it should not be used
    Student s2;
    // cout<<s2.totalStudents<<endl;   
    Student s3;
    Student s4;
    Student s5;
    // cout<<Student::totalStudents; //to access a static variable
    cout<<Student::getTotalStudent()<<endl; //to access a static function same as a static variable
    return 0;
}