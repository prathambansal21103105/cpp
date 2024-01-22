#include<iostream>
using namespace std;
#include<stack>             // pop is a void function doesn't return the top element and here we have empty() instead of isEmpty() they work the same way.
int main(){
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    cout<<s.size()<<endl;
    cout<<s.empty()<<endl;
    return 0;
} 