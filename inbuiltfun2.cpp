#include<iostream>
using namespace std;
int main(){
    char input1[100]="abcd";
    char input2[100]="def";
    char input3[100]="abcd";
    cout<<"Before copy--"<<endl;
    cout<<"Input1--"<<input1<<endl;
    cout<<"Input2--"<<input2<<endl;
    strcpy(input1,input2);      //3 to copy 1 string into other and strcpy(destination string,source string)
    cout<<"After copy--"<<endl;
    cout<<"Input1--"<<input1<<endl;
    cout<<"Input2--"<<input2<<endl;
    strncpy(input3,input2,3);   //4 strncpy here we give the third argument as how many starting characters of string 2 you want to copy
    cout<<"Input3--"<<input3<<endl; // if here we give the third argument bigger than the length of string 2 it automatically prints null in further places
    cout<<"Input2--"<<input2<<endl;
    return 0;
}