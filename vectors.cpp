#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v;
    // vector<int>* vp=new vector<int>();
    // v.push_back(10);
    // v.push_back(20);
    // v.push_back(30);
    // v[1]=100;
    // v[3]=1002;
    // v[4]=1234;       // we only use square bracket [] to get an element or update an element not to enter a new element
    // v.push_back(23);
    // v.push_back(234);
    // cout<<v[0]<<endl; // to get size we use v.size()
    // cout<<v[1]<<endl; // for capacity v.capacity()
    // cout<<v[2]<<endl; // to del last element use v.popback()
    // cout<<v[3]<<endl;
    // cout<<v[4]<<endl;
    // cout<<v[5]<<endl;
    // cout<<v[6]<<endl;
    for(int i=0;i<100;i++){
        cout<<"cap:"<<v.capacity()<<endl;
        v.push_back(i+1);
        cout<<v[i]<<endl;
        cout<<"size:"<<v.size()<<endl;
    }
    return 0;
}