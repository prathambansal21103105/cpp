#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void insert(stack<int>& a, int x){
    if(a.size()==0){
        a.push(x);
    }
    else{
        int y=a.top();
        a.pop();
        insert(a,x);
        a.push(y);
    }
}
void func1(stack<int>& a){
    if(a.size()==0){
        return;
    }
    else{
        int x=a.top();
        a.pop();
        func1(a);
        insert(a,x);
    }
}
int main(){
    stack<int>a;
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push(x);
    }
    func1(a);
    while(a.size()!=0){
        cout<<a.top()<<" ";
        a.pop();
    }
    cout<<endl;
    return 0;
}