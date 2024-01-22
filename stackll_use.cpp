#include<iostream>
using namespace std;
#include"stackll.cpp"
int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    if(s.isEmpty()){
        cout<<"Empty"<<endl;
    }
    else{
        cout<<"Not Empty"<<endl;
    }
    cout<<s.pop()<<endl;
    cout<<s.getSize()<<endl;
    if(s.isEmpty()){
        cout<<"Empty"<<endl;
    }
    else{
        cout<<"Not Empty"<<endl;
    }
    return 0;
}