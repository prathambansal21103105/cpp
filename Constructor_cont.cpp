#include<iostream>
using namespace std;
#include"Student.cpp"
int main(){
    
    Student s1(10,1001);
    Student s2(20,2001);
    Student *s3=new Student(30,3001);
    // making a copy using copy assignment constructor
    s2=s1;
    *s3=s1;
    s2=*s3;

    // Student s1;
    // s1.display();
    // // making a copy of the object s1 using copy constructor
    // Student s2(s1);
    // s2.display();

    // Student *s3=new Student(20,2001);
    // cout<<"S3 :";
    // s3 -> display();

    // Student s4(*s3);

    // Student *s5=new Student(*s3);

    // Student *s6=new Student(*s1);

    return 0;
}