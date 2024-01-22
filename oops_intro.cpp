#include<iostream>
using namespace std;
#include"Student.cpp"

int main(){
    
    //Create objects statically
    Student s1;
    s1.setage(24);
    s1.rollNumber=101;
    int age=s1.getage();
    s1.display();
    
    //Create objects dynamically
    Student*s6=new Student;
    //(*s6).age=23;
    (*s6).rollNumber=102;
    (*s6).setage(25);
    (*s6).display();
    // s6 -> age=23;  //this syntax also works
    // s6 -> rollNumber=102;
    // s6 -> display();

    return 0;
}