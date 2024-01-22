#include<iostream>
using namespace std;
int main(){
    // int const* p; it means that p is a pointer to a constant integer and *p can't change the value of the integer otherwise value of integer can be changed its just remains constant through the path of the pointer
    int i=10;
    int j=21;
    int const* p=&i;  //it means it won't change the value of the variable it is pointing it
    p=&j;             //but the value of p can change
    //(*p)++;         //this is not possible
    cout<<*p<<endl;    
    
    // int const*constp3=&i; it means p3 is a constant pointer to a constant integer so neither p3 can change not the integer;
    // (*p3)++; its not possible because integer is constant
    // p3=&j; its not possible because the pointer is constant so it can't change its value or the address it is storing
    return 0;
}