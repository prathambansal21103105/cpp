#include<iostream>
using namespace std;
#include<vector>
int main(){
    vector<int>v;
    // vector<int>*v1=new vector<int>();
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    v[1]=100;

    cout<<v[0]<<endl;
    cout<<v[1]<<endl;
    cout<<v[2]<<endl;
    cout<<v.size()<<endl;
    cout<<v.at(2)<<endl;
    v.pop_back();
    cout<<v.size()<<endl;
    cout<<v.capacity()<<endl; //tells the actual size of the underlying array
    return 0;
}
// we use [] only to get or update a value not to insert a value