#include<iostream>
using namespace std;
int main(){
    int*p=new int;
    delete p; //deletes the allocated memory, the integer gets deleted not the pointer p

    p=new int[100];
    delete [] p; //to delete an array we put'[]' in from of the pointer
    return 0;
}