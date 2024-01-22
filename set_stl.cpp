#include<iostream>
#include<set>
#include<unordered_set>
using namespace std;
int main(){
    set<int>s;
    unordered_set<int>s1;
    s.insert(5);
    s.insert(5);
    s.insert(1);
    s.insert(6);
    s.insert(6);
    s.insert(0);
    s.insert(0);
    s.insert(1);
    for(auto i:s){
        cout<<i<<endl;
    }
    cout<<endl;
    // s.erase(s.begin());
    set<int>::iterator it=s.begin();
    it++;
    s.erase(it);
    for(int i:s){
        cout<<i<<endl;
    }
    cout<<endl;
    cout<<s.count(-5)<<endl; 
    cout<<endl;
    set<int>::iterator itr=s.find(5);
    cout<<*itr<<endl;
    return 0;
}